$NetBSD: patch-Top_threads.c,v 1.3 2019/11/02 22:25:46 mrg Exp $

Add NetBSD and DragonFlyBSD support.

--- Top/threads.c.orig	2019-07-12 14:54:19.000000000 -0700
+++ Top/threads.c	2019-10-29 13:37:43.363970338 -0700
@@ -28,7 +28,7 @@
 
 #ifndef HAVE_GETTIMEOFDAY
 #if defined(LINUX)    || defined(__unix)   || defined(__unix__) || \
-    defined(__MACH__) || defined(__HAIKU__)
+    defined(__MACH__) || defined(__HAIKU__) || defined(__NetBSD__) || defined(__DragonFly__)
 #define HAVE_GETTIMEOFDAY 1
 #endif
 #endif
