$NetBSD: patch-src_pj__mutex.c,v 1.1 2017/12/19 01:57:48 wiedi Exp $

fix build on SunOS
upstream commit: https://github.com/OSGeo/proj.4/commit/181cd2f3374f3a030b198dc4d2aace467637b584

--- src/pj_mutex.c.orig	2016-08-29 18:47:58.000000000 +0000
+++ src/pj_mutex.c
@@ -28,7 +28,7 @@
 
 /* projects.h and windows.h conflict - avoid this! */
 
-#if defined(MUTEX_pthread) && !defined(_XOPEN_SOURCE)
+#if defined(MUTEX_pthread) && !defined(_XOPEN_SOURCE) && !defined(__sun)
 /* For pthread_mutexattr_settype */
 #define _XOPEN_SOURCE 500
 #endif
