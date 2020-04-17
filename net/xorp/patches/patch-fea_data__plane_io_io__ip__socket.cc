$NetBSD: patch-fea_data__plane_io_io__ip__socket.cc,v 1.2 2020/04/17 00:20:45 joerg Exp $

--- fea/data_plane/io/io_ip_socket.cc.orig	2009-01-05 18:30:54.000000000 +0000
+++ fea/data_plane/io/io_ip_socket.cc
@@ -2022,7 +2022,7 @@ IoIpSocket::send_packet(const string& if
 	    //
 	    struct sockaddr_in sin;
 	    src_address.copy_out(sin);
-	    if (bind(_proto_socket_out,
+	    if (::bind(_proto_socket_out,
 		     reinterpret_cast<struct sockaddr*>(&sin),
 		     sizeof(sin))
 		< 0) {
@@ -2068,7 +2068,7 @@ IoIpSocket::send_packet(const string& if
 #endif
 
 #ifdef IP_PKTINFO
-#ifndef HOST_OS_WINDOWS
+#if !defined(HOST_OS_WINDOWS) && !defined(__NetBSD__)
 	// XXX: Linux
 	{
 	    //
