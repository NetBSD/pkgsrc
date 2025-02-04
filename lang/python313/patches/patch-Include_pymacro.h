$NetBSD: patch-Include_pymacro.h,v 1.3 2025/02/04 22:21:19 adam Exp $

Fix build on NetBSD: error: initializer element is not constant.

--- Include/pymacro.h.orig	2025-02-04 14:51:09.000000000 +0000
+++ Include/pymacro.h
@@ -47,7 +47,7 @@
 #define Py_CHARMASK(c) ((unsigned char)((c) & 0xff))
 
 #if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L \
-     && !defined(__cplusplus) && !defined(_MSC_VER))
+     && !defined(__cplusplus) && !defined(_MSC_VER) && !defined(__NetBSD__) && !defined(__sun))
 #  define Py_BUILD_ASSERT_EXPR(cond) \
     ((void)sizeof(struct { int dummy; _Static_assert(cond, #cond); }), \
      0)
