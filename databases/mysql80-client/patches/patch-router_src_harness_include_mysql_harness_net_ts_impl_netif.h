$NetBSD: patch-router_src_harness_include_mysql_harness_net_ts_impl_netif.h,v 1.1 2021/05/13 15:25:20 jdolecek Exp $

NetBSD also has & needs <ifaddrs.h>

--- router/src/harness/include/mysql/harness/net_ts/impl/netif.h.orig	2021-05-09 02:48:24.814349260 +0000
+++ router/src/harness/include/mysql/harness/net_ts/impl/netif.h
@@ -31,7 +31,7 @@
 #include <string>
 
 #if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || \
-    defined(__sun__)
+    defined(__sun__) || defined(__NetBSD__)
 #define HAVE_IFADDRS_H
 #endif
 
