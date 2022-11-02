$NetBSD: patch-router_src_harness_include_mysql_harness_net_ts_impl_netif.h,v 1.2 2022/11/02 17:02:10 jperkin Exp $

NetBSD also has & needs <ifaddrs.h>

--- router/src/harness/include/mysql/harness/net_ts/impl/netif.h.orig	2022-09-13 16:15:16.000000000 +0000
+++ router/src/harness/include/mysql/harness/net_ts/impl/netif.h
@@ -32,7 +32,7 @@
 #include <string_view>
 
 #if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || \
-    defined(__sun__)
+    defined(__sun__) || defined(__NetBSD__)
 #define HAVE_IFADDRS_H
 #endif
 
