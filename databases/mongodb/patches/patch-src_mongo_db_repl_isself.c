$NetBSD: patch-src_mongo_db_repl_isself.c,v 1.2 2015/08/26 05:03:00 fhajny Exp $

* Add NetBSD support.

--- src/mongo/db/repl/isself.cpp.orig	2015-08-24 00:39:52.000000000 +0000
+++ src/mongo/db/repl/isself.cpp
@@ -48,7 +48,7 @@
 #include "mongo/util/log.h"
 
 #if defined(__linux__) || defined(__APPLE__) || defined(__freebsd__) || defined(__sunos__) || \
-    defined(__openbsd__)
+    defined(__openbsd__) || defined(__netbsd__)
 #define FASTPATH_UNIX 1
 #endif
 
@@ -61,7 +61,7 @@
 #include <ifaddrs.h>
 #include <netdb.h>
 
-#ifdef __freebsd__
+#if defined __freebsd__ || defined __netbsd__
 #include <netinet/in.h>
 #endif
 
