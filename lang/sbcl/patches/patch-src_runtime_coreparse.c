$NetBSD: patch-src_runtime_coreparse.c,v 1.1 2016/10/12 11:35:48 asau Exp $

--- src/runtime/coreparse.c.orig	2016-09-30 16:41:12.000000000 +0000
+++ src/runtime/coreparse.c
@@ -14,6 +14,10 @@
  * files for more information.
  */
 
+#if defined(__NetBSD__)
+#define _KERNTYPES
+#endif
+
 #include "sbcl.h"
 
 #ifndef LISP_FEATURE_WIN32
