$NetBSD: patch-lib_decompress_huf__decompress__amd64.S,v 1.2 2024/04/02 20:05:57 adam Exp $

Move the stack marking stuff inside the ifdef, as it doesn't necessarily
work on non-amd64.

--- lib/decompress/huf_decompress_amd64.S.orig	2024-03-21 22:05:51.000000000 +0000
+++ lib/decompress/huf_decompress_amd64.S
@@ -10,6 +10,7 @@
 
 #include "../common/portability_macros.h"
 
+#if ZSTD_ENABLE_ASM_X86_64_BMI2
 #if defined(__ELF__) && defined(__GNUC__)
 /* Stack marking
  * ref: https://wiki.gentoo.org/wiki/Hardened/GNU_stack_quickstart
@@ -38,8 +39,6 @@
 
 #endif
 
-#if ZSTD_ENABLE_ASM_X86_64_BMI2
-
 /* Calling convention:
  *
  * %rdi contains the first argument: HUF_DecompressAsmArgs*.
