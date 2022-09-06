$NetBSD: patch-ncat_http__digest.c,v 1.1 2022/09/06 18:47:27 adam Exp $

OPENSSL_API_LEVEL is not defined correctly. Assume OpenSSL 1.1+.

--- ncat/http_digest.c.orig	2022-09-06 09:10:57.000000000 +0000
+++ ncat/http_digest.c
@@ -133,10 +133,6 @@ int http_digest_init_secret(void)
     return 0;
 }
 
-#if OPENSSL_API_LEVEL < 10100
-#define EVP_MD_CTX_new EVP_MD_CTX_create
-#define EVP_MD_CTX_free EVP_MD_CTX_destroy
-#endif
 static char *make_nonce(const struct timeval *tv)
 {
     char *buf = NULL;
