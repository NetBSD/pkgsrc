$NetBSD: patch-io_src_hdl__grabber.cpp,v 1.1 2025/01/30 22:07:41 wiz Exp $

Prepare for Boost 1.87
https://github.com/PointCloudLibrary/pcl/commit/6f64495840c4e5674d542ccf20df96ed12665687

--- io/src/hdl_grabber.cpp.orig	2024-05-03 12:14:21.000000000 +0000
+++ io/src/hdl_grabber.cpp
@@ -287,7 +287,7 @@ pcl::HDLGrabber::loadHDL32Corrections ()
 boost::asio::ip::address
 pcl::HDLGrabber::getDefaultNetworkAddress ()
 {
-  return (boost::asio::ip::address::from_string ("192.168.3.255"));
+  return (boost::asio::ip::make_address ("192.168.3.255"));
 }
 
 /////////////////////////////////////////////////////////////////////////////
