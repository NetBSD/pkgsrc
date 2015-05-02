$NetBSD: patch-src_mongo_db_repl_isself.c,v 1.1 2015/05/02 08:10:33 ryoon Exp $

* Add NetBSD support.

--- src/mongo/db/repl/isself.cpp.orig	2015-04-08 20:28:08.000000000 +0000
+++ src/mongo/db/repl/isself.cpp
@@ -47,7 +47,7 @@
 #include "mongo/util/scopeguard.h"
 #include "mongo/util/log.h"
 
-#if defined(__linux__) || defined(__APPLE__) || defined(__freebsd__) || defined(__sunos__) || defined(__openbsd__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__freebsd__) || defined(__sunos__) || defined(__openbsd__) || defined(__netbsd__)
 #define FASTPATH_UNIX 1
 #endif
 
@@ -60,7 +60,7 @@
 #include <ifaddrs.h>
 #include <netdb.h>
 
-#ifdef __freebsd__
+#if defined __freebsd__ || defined __netbsd__
 #include <netinet/in.h>
 #endif
 
