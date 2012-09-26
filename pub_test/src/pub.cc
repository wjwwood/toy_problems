#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Time.h>

int main(int argc, char ** argv) {
   ros::init(argc, argv, "pub");
   ros::NodeHandle n;
   ros::Rate loop_rate(1);

   ros::Publisher pub = n.advertise<std_msgs::Int32>("pub", 10);
   std_msgs::Time msg;
   msg.data = ros::Time::now();

   while(ros::ok()) {
      ROS_INFO("Publishing %f", msg.data.toSec());
      pub.publish(msg);
      msg.data = ros::Time::now();

      ros::spinOnce();
      loop_rate.sleep();
   }

   return 0;
}