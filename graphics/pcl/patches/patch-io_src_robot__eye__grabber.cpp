$NetBSD: patch-io_src_robot__eye__grabber.cpp,v 1.1 2025/01/30 22:07:41 wiz Exp $

Prepare for Boost 1.87
https://github.com/PointCloudLibrary/pcl/commit/6f64495840c4e5674d542ccf20df96ed12665687

--- io/src/robot_eye_grabber.cpp.orig	2024-05-03 12:14:21.000000000 +0000
+++ io/src/robot_eye_grabber.cpp
@@ -269,7 +269,7 @@ void
 pcl::RobotEyeGrabber::socketThreadLoop ()
 {
   asyncSocketReceive();
-  io_service_.reset();
+  io_service_.restart();
   io_service_.run();
 }
 
