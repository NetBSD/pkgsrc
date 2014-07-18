$NetBSD: patch-common_uposixdefs.h,v 1.2 2014/07/18 10:28:11 ryoon Exp $

--- common/uposixdefs.h.orig	2013-10-04 20:49:24.000000000 +0000
+++ common/uposixdefs.h
@@ -42,8 +42,10 @@
      * and define _XOPEN_SOURCE to different values depending on __STDC_VERSION__.
      * In C++ source code (e.g., putil.cpp), __STDC_VERSION__ is not defined at all.
      */
+#if !defined(_SCO_DS)
 #   define _XOPEN_SOURCE 600
 #endif
+#endif
 
 /*
  * Make sure things like readlink and such functions work.
@@ -52,9 +54,11 @@
  *
  * z/OS needs this definition for timeval and to get usleep.
  */
+#if !defined(__sun) && !defined(_SCO_DS)
 #if !defined(_XOPEN_SOURCE_EXTENDED)
 #   define _XOPEN_SOURCE_EXTENDED 1
 #endif
+#endif
 
 /*
  * There is an issue with turning on _XOPEN_SOURCE_EXTENDED on certain platforms.
