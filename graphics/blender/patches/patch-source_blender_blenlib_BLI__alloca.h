$NetBSD: patch-source_blender_blenlib_BLI__alloca.h,v 1.1 2017/02/09 00:23:29 joerg Exp $

Ensure that alloca is always using the builtin. On NetBSD, it is not
provided in standard-only mode.

--- source/blender/blenlib/BLI_alloca.h.orig	2017-01-08 18:11:56.918657083 +0000
+++ source/blender/blenlib/BLI_alloca.h
@@ -34,6 +34,8 @@
 #endif
 
 #if defined(__GNUC__) || defined(__clang__)
+#undef alloca
+#define alloca(n) __builtin_alloca(n)
 #if defined(__cplusplus) && (__cplusplus > 199711L)
 #define BLI_array_alloca(arr, realsize) \
 	(decltype(arr))alloca(sizeof(*arr) * (realsize))
