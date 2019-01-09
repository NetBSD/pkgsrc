$NetBSD: patch-cipher_camellia-aarch64.S,v 1.2 2019/01/09 14:19:26 martin Exp $

Do not make _gcry_camellia_arm_tables global, to allow the assembler to
resolve the symbol locally (avoids relocations that break the build).

--- cipher/camellia-aarch64.S.orig	2017-11-23 19:16:58.000000000 +0100
+++ cipher/camellia-aarch64.S	2019-01-09 14:27:16.928019986 +0100
@@ -284,7 +284,7 @@
 .size _gcry_camellia_arm_decrypt_block,.-_gcry_camellia_arm_decrypt_block;
 
 /* Encryption/Decryption tables */
-.globl _gcry_camellia_arm_tables
+#  .globl _gcry_camellia_arm_tables
 .type  _gcry_camellia_arm_tables,@object;
 .balign 32
 _gcry_camellia_arm_tables:
