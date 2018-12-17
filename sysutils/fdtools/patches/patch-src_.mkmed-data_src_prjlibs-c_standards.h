$NetBSD: patch-src_.mkmed-data_src_prjlibs-c_standards.h,v 1.1 2018/12/17 17:04:38 schmonz Exp $

Handle _XOPEN_SOURCE on SunOS.

--- src/.mkmed-data/src/prjlibs-c/standards.h.orig	2015-03-28 22:14:51.231617623 +0000
+++ src/.mkmed-data/src/prjlibs-c/standards.h
@@ -7,13 +7,16 @@
 #endif
 #endif
 #endif
-#define _XOPEN_SOURCE_EXTENDED 1
 #ifndef _BSD_SOURCE
 #define _BSD_SOURCE 1
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
