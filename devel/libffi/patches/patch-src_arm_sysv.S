$NetBSD: patch-src_arm_sysv.S,v 1.9 2020/04/08 13:40:11 tnn Exp $

fix: libffi.so: undefined reference to `__aeabi_unwind_cpp_pr0'

--- src/arm/sysv.S.orig	2019-10-31 14:49:54.000000000 +0000
+++ src/arm/sysv.S
@@ -53,7 +53,7 @@
 #endif
 
 /* Conditionally compile unwinder directives.  */
-#ifdef __ARM_EABI__
+#if defined(__ARM_EABI__) && !defined(__ARM_DWARF_EH__)
 # define UNWIND(...)	__VA_ARGS__
 #else
 # define UNWIND(...)
