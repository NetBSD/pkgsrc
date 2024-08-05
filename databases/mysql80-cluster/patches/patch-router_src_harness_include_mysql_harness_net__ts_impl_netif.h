$NetBSD: patch-router_src_harness_include_mysql_harness_net__ts_impl_netif.h,v 1.1 2024/08/05 01:24:00 jnemeth Exp $

--- router/src/harness/include/mysql/harness/net_ts/impl/netif.h.orig	2022-03-23 13:49:36.000000000 +0000
+++ router/src/harness/include/mysql/harness/net_ts/impl/netif.h
@@ -32,7 +32,7 @@
 #include <string_view>
 
 #if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || \
-    defined(__sun__)
+    defined(__sun__) || defined(__NetBSD__)
 #define HAVE_IFADDRS_H
 #endif
 
