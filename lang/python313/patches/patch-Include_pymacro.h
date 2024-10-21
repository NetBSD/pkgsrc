$NetBSD: patch-Include_pymacro.h,v 1.2 2024/10/21 10:21:27 jperkin Exp $

Fix build on NetBSD: error: initializer element is not constant.

--- Include/pymacro.h.orig	2024-10-09 19:39:18.701274249 +0000
+++ Include/pymacro.h
@@ -47,7 +47,7 @@
 #define Py_CHARMASK(c) ((unsigned char)((c) & 0xff))
 
 #if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L \
-     && !defined(__cplusplus))
+     && !defined(__cplusplus) && !defined(__NetBSD__) && !defined(__sun))
 #  define Py_BUILD_ASSERT_EXPR(cond) \
     ((void)sizeof(struct { int dummy; _Static_assert(cond, #cond); }), \
      0)
