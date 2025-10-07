$NetBSD: patch-camlibs_ptp2_ptpip.c,v 1.1 2025/10/07 11:36:53 wiz Exp $

Add header for inet_aton().

--- camlibs/ptp2/ptpip.c.orig	2025-10-07 11:31:46.519566717 +0000
+++ camlibs/ptp2/ptpip.c
@@ -49,6 +49,7 @@
 # include <ws2tcpip.h>
 #else
 # include <sys/socket.h>
+# include <arpa/inet.h>
 # include <netinet/in.h>
 # include <fcntl.h>
 #endif
