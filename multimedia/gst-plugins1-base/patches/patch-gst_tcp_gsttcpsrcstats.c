$NetBSD: patch-gst_tcp_gsttcpsrcstats.c,v 1.1 2025/07/16 09:17:18 jperkin Exp $

Fix include order.

--- gst/tcp/gsttcpsrcstats.c.orig	2025-07-16 09:11:53.121563230 +0000
+++ gst/tcp/gsttcpsrcstats.c
@@ -6,8 +6,8 @@
 
 /* macOS and iOS have the .h files but the tcp_info struct is private API */
 #if defined(HAVE_NETINET_TCP_H) && defined(HAVE_NETINET_IN_H) && defined(HAVE_SYS_SOCKET_H)
-#include <netinet/tcp.h>
 #include <netinet/in.h>
+#include <netinet/tcp.h>
 #include <sys/socket.h>
 #if defined(TCP_INFO)
 #define HAVE_SOCKET_METRIC_HEADERS
