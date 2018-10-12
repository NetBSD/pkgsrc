$NetBSD: patch-src_libcryptobox_cryptobox.c,v 1.1 2018/10/12 12:49:28 roy Exp $

OpenSSL-1.1 automatically loads error strings.
Calling these without an OpenSSL init function can result in an error.

--- src/libcryptobox/cryptobox.c.orig	2018-09-24 13:53:53.000000000 +0000
+++ src/libcryptobox/cryptobox.c
@@ -374,7 +374,7 @@ rspamd_cryptobox_init (void)
 	ctx->blake2_impl = blake2b_load ();
 	ctx->ed25519_impl = ed25519_load ();
 	ctx->base64_impl = base64_load ();
-#ifdef HAVE_USABLE_OPENSSL
+#if defined(HAVE_USABLE_OPENSSL) && OPENSSL_VERSION_NUMBER < 0x10100000L
 	ERR_load_EC_strings ();
 	ERR_load_RAND_strings ();
 	ERR_load_EVP_strings ();
