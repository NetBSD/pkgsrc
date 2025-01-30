$NetBSD: patch-io_src_tim__grabber.cpp,v 1.1 2025/01/30 22:07:41 wiz Exp $

Prepare for Boost 1.87
https://github.com/PointCloudLibrary/pcl/commit/6f64495840c4e5674d542ccf20df96ed12665687

--- io/src/tim_grabber.cpp.orig	2024-05-03 12:14:21.000000000 +0000
+++ io/src/tim_grabber.cpp
@@ -184,8 +184,8 @@ pcl::TimGrabber::start ()
 
   try {
     boost::asio::ip::tcp::resolver resolver (tim_io_service_);
-    tcp_endpoint_ = *resolver.resolve (tcp_endpoint_);
-    tim_socket_.connect (tcp_endpoint_);
+    boost::asio::ip::tcp::resolver::results_type endpoints = resolver.resolve (tcp_endpoint_);
+    boost::asio::connect(tim_socket_, endpoints);
   }
   catch (std::exception& e)
   {
