$NetBSD: patch-lib_decompress_huf__decompress__amd64.S,v 1.5 2026/11/24 09:23:23 wiz Exp $

Move the stack marking stuff inside the ifdef, as it doesn't necessarily
work on non-amd64.

--- lib/decompress/huf_decompress_amd64.S.orig	2026-11-23 22:40:52.000000000 +0000
+++ lib/decompress/huf_decompress_amd64.S
@@ -10,6 +10,7 @@
 
 #include "../common/portability_macros.h"
 
+#if ZSTD_ENABLE_ASM_X86_64_BMI2
 #if defined(__ELF__) && defined(__GNUC__)
 /* Stack marking
  * ref: https://wiki.gentoo.org/wiki/Hardened/GNU_stack_quickstart
@@ -47,8 +48,6 @@
 #else
 #define LOCAL_LABEL(label) .L_ ## label
 #endif
-
-#if ZSTD_ENABLE_ASM_X86_64_BMI2
 
 /* Calling convention:
  *
