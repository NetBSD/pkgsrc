$NetBSD: patch-src_runtime_runtime.h,v 1.1 2016/10/12 11:35:48 asau Exp $

--- src/runtime/runtime.h.orig	2016-09-30 16:41:12.000000000 +0000
+++ src/runtime/runtime.h
@@ -15,6 +15,10 @@
 #ifndef _SBCL_RUNTIME_H_
 #define _SBCL_RUNTIME_H_
 
+#if defined(__NetBSD__)
+#define _KERNTYPES
+#endif
+
 #if defined(LISP_FEATURE_WIN32) && defined(LISP_FEATURE_SB_THREAD)
 # include "pthreads_win32.h"
 #else
