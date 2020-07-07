$NetBSD: patch-src_.mkmed-data_src_prjlibs-c_standards.h,v 1.2 2020/07/07 10:31:31 schmonz Exp $

Handle _XOPEN_SOURCE on SunOS.

--- src/.mkmed-data/src/prjlibs-c/standards.h.orig	2020-05-04 08:10:42.000000000 +0000
+++ src/.mkmed-data/src/prjlibs-c/standards.h
@@ -7,7 +7,6 @@
 #endif
 #endif
 #endif
-#define _XOPEN_SOURCE_EXTENDED 1
 #ifndef _DEFAULT_SOURCE
 #define _DEFAULT_SOURCE 1
 #endif
@@ -16,7 +15,11 @@
 #endif
 #ifdef __sun
 #undef _XOPEN_SOURCE
+#if (__STDC_VERSION__-0 < 199901L)
 #define _XOPEN_SOURCE 500
+#else
+#define _XOPEN_SOURCE 600
+#endif
 #ifndef __EXTENSIONS__
 #define __EXTENSIONS__ 1
 #endif
