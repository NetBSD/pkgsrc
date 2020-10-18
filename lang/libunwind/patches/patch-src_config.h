$NetBSD: patch-src_config.h,v 1.1 2020/10/18 17:06:35 he Exp $

Gcc doesn't define __ppc__, but defines __powerpc__ on NetBSD/powerpc.

--- src/config.h.orig	2020-07-07 16:21:37.000000000 +0000
+++ src/config.h
@@ -95,7 +95,7 @@
 #define _LIBUNWIND_BUILD_SJLJ_APIS
 #endif
 
-#if defined(__i386__) || defined(__x86_64__) || defined(__ppc__) || defined(__ppc64__) || defined(__powerpc64__)
+#if defined(__i386__) || defined(__x86_64__) || defined(__ppc__) || defined(__ppc64__) || defined(__powerpc64__) || defined(__powerpc__)
 #define _LIBUNWIND_SUPPORT_FRAME_APIS
 #endif
 
