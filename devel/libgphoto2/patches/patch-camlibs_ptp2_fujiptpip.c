$NetBSD: patch-camlibs_ptp2_fujiptpip.c,v 1.1 2025/10/07 11:36:53 wiz Exp $

Add header for inet_aton().

--- camlibs/ptp2/fujiptpip.c.orig	2025-10-07 11:32:25.277585586 +0000
+++ camlibs/ptp2/fujiptpip.c
@@ -59,6 +59,7 @@
 # include <winsock2.h>
 # include <ws2tcpip.h>
 #else
+# include <arpa/inet.h>
 # include <sys/socket.h>
 # include <netinet/in.h>
 #endif
