$NetBSD: patch-src_mongo_db_repl_isself.c,v 1.3 2016/02/12 03:37:24 ryoon Exp $

* Add NetBSD support.

--- src/mongo/db/repl/isself.cpp.orig	2016-01-05 18:31:44.000000000 +0000
+++ src/mongo/db/repl/isself.cpp
@@ -48,7 +48,7 @@
 #include "mongo/util/log.h"
 
 #if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__sun) || \
-    defined(__OpenBSD__)
+    defined(__OpenBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 #define FASTPATH_UNIX 1
 #endif
 
@@ -61,7 +61,7 @@
 #include <ifaddrs.h>
 #include <netdb.h>
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <netinet/in.h>
 #endif
 
