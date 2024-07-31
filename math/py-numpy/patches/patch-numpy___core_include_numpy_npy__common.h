$NetBSD: patch-numpy___core_include_numpy_npy__common.h,v 1.1 2024/07/31 18:11:24 adam Exp $

Fix build on non-x86:
The configure test for __builtin_prefetch is broken with clang.
_configtest.c:6:3: error: builtin functions must be directly called

--- numpy/_core/include/numpy/npy_common.h.orig	2024-07-20 17:15:41.000000000 +0000
+++ numpy/_core/include/numpy/npy_common.h
@@ -68,7 +68,7 @@
 #define NPY_UNLIKELY(x) (x)
 #endif
 
-#ifdef HAVE___BUILTIN_PREFETCH
+#if 1
 /* unlike _mm_prefetch also works on non-x86 */
 #define NPY_PREFETCH(x, rw, loc) __builtin_prefetch((x), (rw), (loc))
 #else
