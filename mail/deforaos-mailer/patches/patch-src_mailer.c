$NetBSD: patch-src_mailer.c,v 1.1 2020/01/10 21:15:21 joerg Exp $

SSLv23 is considered the generic request and mapped to TLS with newer
OpenSSL.

--- src/mailer.c.orig	2020-01-08 23:37:23.358580636 +0000
+++ src/mailer.c
@@ -391,7 +391,7 @@ Mailer * mailer_new(void)
 	/* ssl */
 	SSL_load_error_strings();
 	SSL_library_init();
-	if((mailer->ssl_ctx = SSL_CTX_new(SSLv3_client_method())) == NULL
+	if((mailer->ssl_ctx = SSL_CTX_new(SSLv23_client_method())) == NULL
 			|| SSL_CTX_set_cipher_list(mailer->ssl_ctx,
 				SSL_DEFAULT_CIPHER_LIST) != 1
 			|| SSL_CTX_load_verify_locations(mailer->ssl_ctx, NULL,
