$NetBSD: patch-src_netstat.h,v 1.1 2016/04/18 12:14:29 jperkin Exp $

Fix SunOS build, from OpenIndiana.

--- src/netstat.h.orig	2009-05-20 00:56:41.000000000 +0000
+++ src/netstat.h
@@ -36,6 +36,12 @@
 #   define NETSTAT_ROUTE_FORMAT "%s %s %s %d %d %s"
 #   define NETSTAT_MULTICAST_FORMAT "%s %d %s"
 
+#elif defined(__sun)
+#   define NETSTAT_PROTOCOL_FORMAT "%s %d %d %s %s %s"
+#   define NETSTAT_ROUTE_FORMAT "%s %s %s %d %d %s"
+#   define NETSTAT_ROUTE6_FORMAT "%s %s %s %d %d %d %s"
+#   define NETSTAT_MULTICAST_FORMAT "%s %s %d"
+
 #endif
 
 typedef enum {
