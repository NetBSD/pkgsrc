$NetBSD: patch-src_torrent_net_socket__address__key.h,v 1.2 2024/10/04 09:00:06 adam Exp $

Add missing header for AF_INET and friends.
Needed for SunOS but also "POSIX sez so".

--- src/torrent/net/socket_address_key.h.orig	2024-10-03 12:59:31.247837979 +0000
+++ src/torrent/net/socket_address_key.h
@@ -6,6 +6,7 @@
 
 #include <cstring>
 #include <cinttypes>
+#include <sys/socket.h>
 #include <netinet/in.h>
 
 // Unique key for the socket address, excluding port numbers, etc.
