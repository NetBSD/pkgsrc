$NetBSD: patch-src_runtime_save.c,v 1.1 2016/10/12 11:35:48 asau Exp $

--- src/runtime/save.c.orig	2016-09-30 16:41:12.000000000 +0000
+++ src/runtime/save.c
@@ -9,6 +9,10 @@
  * files for more information.
  */
 
+#if defined(__NetBSD__)
+#define _KERNTYPES
+#endif
+
 #ifndef LISP_FEATURE_WIN32
 #include <sys/types.h>
 #include <sys/stat.h>
