$NetBSD: patch-src_torrent_net_socket__address__key.h,v 1.1 2023/11/09 19:09:19 nia Exp $

Add missing header for AF_INET and friends.
Needed for SunOS but also "POSIX sez so".

--- src/torrent/net/socket_address_key.h.orig	2019-07-19 11:44:08.000000000 +0000
+++ src/torrent/net/socket_address_key.h
@@ -6,6 +6,7 @@
 
 #include <cstring>
 #include <inttypes.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
 
 // Unique key for the socket address, excluding port numbers, etc.
