$NetBSD: patch-io_src_vlp__grabber.cpp,v 1.1 2025/01/30 22:07:41 wiz Exp $

Prepare for Boost 1.87
https://github.com/PointCloudLibrary/pcl/commit/6f64495840c4e5674d542ccf20df96ed12665687

--- io/src/vlp_grabber.cpp.orig	2024-05-03 12:14:21.000000000 +0000
+++ io/src/vlp_grabber.cpp
@@ -92,7 +92,7 @@ pcl::VLPGrabber::loadVLP16Corrections ()
 boost::asio::ip::address
 pcl::VLPGrabber::getDefaultNetworkAddress ()
 {
-  return (boost::asio::ip::address::from_string ("255.255.255.255"));
+  return (boost::asio::ip::make_address ("255.255.255.255"));
 }
 
 /////////////////////////////////////////////////////////////////////////////
