$NetBSD: patch-runtime_src_kmp__platform.h,v 1.1 2025/01/23 13:59:37 he Exp $

Recognize NetBSD/powerpc.

--- runtime/src/kmp_platform.h.orig	2025-01-23 13:46:36.907713760 +0000
+++ runtime/src/kmp_platform.h
@@ -157,6 +157,9 @@
 #define KMP_ARCH_PPC_XCOFF 1
 #undef KMP_ARCH_PPC
 #define KMP_ARCH_PPC 1
+#elif defined(__powerpc__) && defined(KMP_OS_NETBSD)
+#undef KMP_ARCH_PPC
+#define KMP_ARCH_PPC 1
 #elif defined __aarch64__
 #undef KMP_ARCH_AARCH64
 #define KMP_ARCH_AARCH64 1
