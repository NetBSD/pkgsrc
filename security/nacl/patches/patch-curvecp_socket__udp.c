$NetBSD: patch-curvecp_socket__udp.c,v 1.1 2022/01/04 20:53:20 schmonz Exp $

Borrow patch from FreeBSD ports that also fixes macOS build.

--- curvecp/socket_udp.c.orig	2011-02-21 01:49:34.000000000 +0000
+++ curvecp/socket_udp.c
@@ -6,6 +6,10 @@
 #include "socket.h"
 #include "blocking.h"
 
+#ifndef SOL_IP
+#define SOL_IP IPPROTO_IP  /* FreeBSD requires protocol number */
+#endif
+
 static void enable_bsd_fragmentation(int fd)
 {
 #ifdef IP_DONTFRAG
