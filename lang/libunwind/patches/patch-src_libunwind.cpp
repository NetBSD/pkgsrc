$NetBSD: patch-src_libunwind.cpp,v 1.1 2020/10/18 17:06:35 he Exp $

Gcc doesn't define __ppc__, but defines __powerpc__ on NetBSD/powerpc.

--- src/libunwind.cpp.orig	2020-07-07 16:21:37.000000000 +0000
+++ src/libunwind.cpp
@@ -42,7 +42,7 @@ _LIBUNWIND_HIDDEN int __unw_init_local(u
 # define REGISTER_KIND Registers_x86_64
 #elif defined(__powerpc64__)
 # define REGISTER_KIND Registers_ppc64
-#elif defined(__ppc__)
+#elif defined(__ppc__) || defined(__powerpc__)
 # define REGISTER_KIND Registers_ppc
 #elif defined(__aarch64__)
 # define REGISTER_KIND Registers_arm64
