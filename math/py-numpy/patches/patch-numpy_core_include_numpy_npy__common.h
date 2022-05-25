$NetBSD: patch-numpy_core_include_numpy_npy__common.h,v 1.2 2022/05/25 19:22:20 tnn Exp $

Fix build on non-x86:
The configure test for __builtin_prefetch is broken with clang.
_configtest.c:6:3: error: builtin functions must be directly called

--- numpy/core/include/numpy/npy_common.h.orig	2022-05-20 05:46:10.000000000 +0000
+++ numpy/core/include/numpy/npy_common.h
@@ -116,7 +116,7 @@
 #define NPY_UNLIKELY(x) (x)
 #endif
 
-#ifdef HAVE___BUILTIN_PREFETCH
+#if 1
 /* unlike _mm_prefetch also works on non-x86 */
 #define NPY_PREFETCH(x, rw, loc) __builtin_prefetch((x), (rw), (loc))
 #else
