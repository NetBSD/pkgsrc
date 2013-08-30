$NetBSD: patch-fea_data__plane_io_io__ip__socket.cc,v 1.1 2013/08/30 22:40:00 joerg Exp $

--- fea/data_plane/io/io_ip_socket.cc.orig	2013-08-30 21:41:39.000000000 +0000
+++ fea/data_plane/io/io_ip_socket.cc
@@ -2068,7 +2068,7 @@ IoIpSocket::send_packet(const string& if
 #endif
 
 #ifdef IP_PKTINFO
-#ifndef HOST_OS_WINDOWS
+#if !defined(HOST_OS_WINDOWS) && !defined(__NetBSD__)
 	// XXX: Linux
 	{
 	    //
