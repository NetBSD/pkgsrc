$NetBSD: patch-lib_accelerated_x86_aes-cbc-x86-aesni.c,v 1.1 2014/02/10 12:01:20 tron Exp $

Fix build under Mac OS X when assembler code is enabled.
Patch taken from here:

https://www.gitorious.org/gnutls/gnutls/commit/54768ca1cd9049bbd1c695696ef3c8595c6052db

--- lib/accelerated/x86/aes-cbc-x86-aesni.c.orig	2014-01-01 17:14:59.000000000 +0000
+++ lib/accelerated/x86/aes-cbc-x86-aesni.c	2014-02-10 11:31:27.000000000 +0000
@@ -39,8 +39,6 @@
 	int enc;
 };
 
-unsigned int _gnutls_x86_cpuid_s[4];
-
 static int
 aes_cipher_init(gnutls_cipher_algorithm_t algorithm, void **_ctx, int enc)
 {
