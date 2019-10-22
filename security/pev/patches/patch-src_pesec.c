$NetBSD: patch-src_pesec.c,v 1.1 2019/10/22 16:37:05 khorben Exp $

Fix build with OpenSSL >= 1.1.0

--- src/pesec.c.orig	2017-01-06 22:27:18.000000000 +0000
+++ src/pesec.c
@@ -225,7 +225,9 @@ static int parse_pkcs7_data(const option
 	PKCS7 *p7 = NULL;
 	BIO *in = NULL;
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	CRYPTO_malloc_init();
+#endif
 	ERR_load_crypto_strings();
 	OpenSSL_add_all_algorithms();
 
