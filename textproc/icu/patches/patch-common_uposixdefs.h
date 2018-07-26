$NetBSD: patch-common_uposixdefs.h,v 1.6 2018/07/26 22:37:48 abs Exp $

C99 and related define overrides.
Do not play _XOPEN_SOURCE games on NetBSD, as it breaks at least gcc 6.4 on NetBSD-8.0

--- common/uposixdefs.h.orig	2018-06-21 09:39:23.000000000 +0000
+++ common/uposixdefs.h
@@ -44,8 +44,10 @@
      * and define _XOPEN_SOURCE to different values depending on __STDC_VERSION__.
      * In C++ source code (e.g., putil.cpp), __STDC_VERSION__ is not defined at all.
      */
+#if !defined(_SCO_DS) && !defined(__NetBSD__)
 #   define _XOPEN_SOURCE 600
 #endif
+#endif
 
 /*
  * Make sure things like readlink and such functions work.
@@ -54,9 +56,11 @@
  *
  * z/OS needs this definition for timeval and to get usleep.
  */
+#if !defined(__sun) && !defined(_SCO_DS)
 #if !defined(_XOPEN_SOURCE_EXTENDED) && defined(__TOS_MVS__)
 #   define _XOPEN_SOURCE_EXTENDED 1
 #endif
+#endif
 
 /**
  * Solaris says:
