$NetBSD: patch-router_src_harness_include_mysql_harness_net_ts_local.h,v 1.1 2021/05/13 15:25:20 jdolecek Exp $

NetBSD has uucred, not sockpeercred.

--- router/src/harness/include/mysql/harness/net_ts/local.h.orig	2021-05-09 01:07:01.720111634 +0000
+++ router/src/harness/include/mysql/harness/net_ts/local.h
@@ -44,7 +44,7 @@
 
 #ifdef NET_TS_HAS_UNIX_SOCKET
 
-#if defined(__FreeBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__NetBSD__)
 #include <sys/ucred.h>
 #endif
 
@@ -229,7 +229,7 @@ class cred {
 #elif defined(__FreeBSD__) || defined(__APPLE__)
   using value_type = struct xucred;
 #elif defined(__NetBSD__)
-  using value_type = struct sockpeercred;
+  using value_type = struct uucred;
 #else
 #error "unsupported OS"
 #endif
