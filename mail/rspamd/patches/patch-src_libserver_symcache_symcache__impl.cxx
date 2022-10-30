$NetBSD: patch-src_libserver_symcache_symcache__impl.cxx,v 1.1 2022/10/30 15:38:54 jperkin Exp $

Explicitly use std::pow().

--- src/libserver/symcache/symcache_impl.cxx.orig	2022-10-01 14:19:21.000000000 +0000
+++ src/libserver/symcache/symcache_impl.cxx
@@ -31,6 +31,8 @@
 #endif
 #include <cmath>
 
+using std::pow;
+
 namespace rspamd::symcache {
 
 INIT_LOG_MODULE_PUBLIC(symcache)
