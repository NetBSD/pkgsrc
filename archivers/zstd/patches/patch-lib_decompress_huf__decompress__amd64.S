$NetBSD: patch-lib_decompress_huf__decompress__amd64.S,v 1.1.2.2 2023/05/15 17:49:47 spz Exp $

Move the stack marking stuff inside the ifdef, as it doesn't necessarily
work on non-amd64.

--- lib/decompress/huf_decompress_amd64.S~	2023-04-04 20:13:52.000000000 +0000
+++ lib/decompress/huf_decompress_amd64.S
@@ -10,6 +10,8 @@
 
 #include "../common/portability_macros.h"
 
+#if ZSTD_ENABLE_ASM_X86_64_BMI2
+
 /* Stack marking
  * ref: https://wiki.gentoo.org/wiki/Hardened/GNU_stack_quickstart
  */
@@ -17,8 +19,6 @@
 .section .note.GNU-stack,"",%progbits
 #endif
 
-#if ZSTD_ENABLE_ASM_X86_64_BMI2
-
 /* Calling convention:
  *
  * %rdi contains the first argument: HUF_DecompressAsmArgs*.
