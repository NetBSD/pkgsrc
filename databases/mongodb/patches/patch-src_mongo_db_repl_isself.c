$NetBSD: patch-src_mongo_db_repl_isself.c,v 1.4 2017/05/29 14:44:47 ryoon Exp $

* Add NetBSD support.

--- src/mongo/db/repl/isself.cpp.orig	2017-04-20 21:43:42.000000000 +0000
+++ src/mongo/db/repl/isself.cpp
@@ -50,7 +50,7 @@
 #include "mongo/util/scopeguard.h"
 
 #if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__sun) || \
-    defined(__OpenBSD__)
+    defined(__OpenBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 #define FASTPATH_UNIX 1
 #endif
 
@@ -63,7 +63,7 @@
 #include <ifaddrs.h>
 #include <netdb.h>
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <netinet/in.h>
 #endif
 
