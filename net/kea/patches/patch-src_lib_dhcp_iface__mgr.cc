$NetBSD: patch-src_lib_dhcp_iface__mgr.cc,v 1.1 2025/01/15 06:05:14 wiz Exp $

Fix build with boost 1.87.
https://github.com/isc-projects/kea/pull/143

--- src/lib/dhcp/iface_mgr.cc.orig	2024-07-25 08:50:58.000000000 +0000
+++ src/lib/dhcp/iface_mgr.cc
@@ -1034,7 +1034,7 @@ IfaceMgr::getLocalAddress(const IOAddres
     }
 
     // Create socket that will be used to connect to remote endpoint.
-    boost::asio::io_service io_service;
+    boost::asio::io_context io_service;
     boost::asio::ip::udp::socket sock(io_service);
 
     boost::system::error_code err_code;
