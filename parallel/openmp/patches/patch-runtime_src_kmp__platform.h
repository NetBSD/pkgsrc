$NetBSD: patch-runtime_src_kmp__platform.h,v 1.3 2025/05/09 05:51:26 adam Exp $

Recognize NetBSD/powerpc.
Submitted upstream at
https://github.com/llvm/llvm-project/pull/124151

--- runtime/src/kmp_platform.h.orig	2025-01-14 09:41:02.000000000 +0000
+++ runtime/src/kmp_platform.h
@@ -158,6 +158,9 @@
 #define KMP_ARCH_PPC_XCOFF 1
 #undef KMP_ARCH_PPC
 #define KMP_ARCH_PPC 1
+#elif defined(__powerpc__) && defined(KMP_OS_NETBSD)
+#undef KMP_ARCH_PPC
+#define KMP_ARCH_PPC 1
 #elif defined __ARM64_ARCH_8_32__
 #undef KMP_ARCH_AARCH64_32
 #define KMP_ARCH_AARCH64_32 1
