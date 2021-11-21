$NetBSD: patch-runtime_src_kmp__runtime.cpp,v 1.1 2021/11/21 14:52:35 ryoon Exp $

* Support NetBSD/i386 and other 32-bit architectures.

--- runtime/src/kmp_runtime.cpp.orig	2021-06-28 16:23:38.000000000 +0000
+++ runtime/src/kmp_runtime.cpp
@@ -8399,7 +8399,8 @@ __kmp_determine_reduction_method(
 
 #elif KMP_ARCH_X86 || KMP_ARCH_ARM || KMP_ARCH_AARCH || KMP_ARCH_MIPS
 
-#if KMP_OS_LINUX || KMP_OS_FREEBSD || KMP_OS_WINDOWS || KMP_OS_HURD
+#if KMP_OS_LINUX || KMP_OS_FREEBSD || KMP_OS_WINDOWS || KMP_OS_HURD || \
+    KMP_OS_NETBSD
 
     // basic tuning
 
