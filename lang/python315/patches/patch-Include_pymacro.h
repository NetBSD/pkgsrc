$NetBSD: patch-Include_pymacro.h,v 1.2 2026/10/26 05:37:44 adam Exp $

Fix build on NetBSD: error: initializer element is not constant.

--- Include/pymacro.h.orig	2026-10-25 16:57:51.000000000 +0000
+++ Include/pymacro.h
@@ -145,7 +145,7 @@
 #define Py_CHARMASK(c) ((unsigned char)((c) & 0xff))
 
 #if (defined(_Py_STDC_VERSION) && _Py_STDC_VERSION >= 201112L \
-     && !defined(__cplusplus) && !defined(_MSC_VER))
+     && !defined(__cplusplus) && !defined(_MSC_VER) && !defined(__NetBSD__) && !defined(__sun))
 #  define Py_BUILD_ASSERT_EXPR(cond) \
     ((void)sizeof(struct { int dummy; _Static_assert(cond, #cond); }), \
      0)
