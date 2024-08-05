$NetBSD: patch-router_src_harness_include_mysql_harness_net__ts_local.h,v 1.1 2024/08/05 01:24:00 jnemeth Exp $

--- router/src/harness/include/mysql/harness/net_ts/local.h.orig	2022-03-23 13:49:36.000000000 +0000
+++ router/src/harness/include/mysql/harness/net_ts/local.h
@@ -44,7 +44,7 @@
 
 #ifdef NET_TS_HAS_UNIX_SOCKET
 
-#if defined(__FreeBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__NetBSD__)
 #include <sys/ucred.h>
 #endif
 
@@ -228,7 +228,7 @@ class cred {
 #elif defined(__FreeBSD__) || defined(__APPLE__)
   using value_type = struct xucred;
 #elif defined(__NetBSD__)
-  using value_type = struct sockpeercred;
+  using value_type = struct uucred;
 #else
 #error "unsupported OS"
 #endif
