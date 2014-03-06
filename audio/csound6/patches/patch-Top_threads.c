$NetBSD: patch-Top_threads.c,v 1.1 2014/03/06 10:16:53 mrg Exp $

--- Top/threads.c.orig	2014-01-07 08:54:20.000000000 -0800
+++ Top/threads.c	2014-02-12 23:55:26.000000000 -0800
@@ -26,7 +26,7 @@
 
 #ifndef HAVE_GETTIMEOFDAY
 #if defined(LINUX)    || defined(__unix)   || defined(__unix__) || \
-    defined(__MACH__) || defined(__HAIKU__)
+    defined(__MACH__) || defined(__HAIKU__) || defined(__NetBSD__) || defined(__DragonFly__)
 #define HAVE_GETTIMEOFDAY 1
 #endif
 #endif
@@ -152,7 +152,7 @@
 
 
 #if defined(LINUX) || defined(__MACH__) || defined(__HAIKU__) || \
-    defined(ANDROID) || defined(WIN32)
+    defined(ANDROID) || defined(WIN32) || defined(__NetBSD__) || defined(__DragonFly__)
 
 #include <errno.h>
 #include <pthread.h>
