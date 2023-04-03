$NetBSD: patch-double-conversion_utils.h,v 1.1 2023/04/03 11:28:38 nros Exp $

- fix a build error on NetBSD/sh3el.

--- double-conversion/utils.h.orig	2023-03-29 13:10:31.737772844 +0000
+++ double-conversion/utils.h
@@ -144,7 +144,7 @@ int main(int argc, char** argv) {
     defined(__powerpc__) || defined(__ppc__) || defined(__ppc64__) || \
     defined(_POWER) || defined(_ARCH_PPC) || defined(_ARCH_PPC64) || \
     defined(__sparc__) || defined(__sparc) || defined(__s390__) || \
-    defined(__SH4__) || defined(__alpha__) || \
+    defined(__sh__) || defined(__SH4__) || defined(__alpha__) || \
     defined(_MIPS_ARCH_MIPS32R2) || defined(__ARMEB__) ||\
     defined(__AARCH64EL__) || defined(__aarch64__) || defined(__AARCH64EB__) || \
     defined(__riscv) || defined(__e2k__) || \
