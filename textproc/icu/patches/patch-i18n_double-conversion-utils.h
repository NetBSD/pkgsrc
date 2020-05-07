$NetBSD: patch-i18n_double-conversion-utils.h,v 1.6 2020/05/07 16:01:33 tsutsui Exp $

Add support for sh3.

--- i18n/double-conversion-utils.h.orig	2020-03-11 18:16:11.000000000 +0000
+++ i18n/double-conversion-utils.h
@@ -107,7 +107,7 @@ int main(int argc, char** argv) {
     defined(__powerpc__) || defined(__ppc__) || defined(__ppc64__) || \
     defined(_POWER) || defined(_ARCH_PPC) || defined(_ARCH_PPC64) || \
     defined(__sparc__) || defined(__sparc) || defined(__s390__) || \
-    defined(__SH4__) || defined(__alpha__) || \
+    defined(__SH4__) || defined(__sh__) || defined(__alpha__) || \
     defined(_MIPS_ARCH_MIPS32R2) || defined(__ARMEB__) ||\
     defined(__AARCH64EL__) || defined(__aarch64__) || defined(__AARCH64EB__) || \
     defined(__riscv) || defined(__e2k__) || \
