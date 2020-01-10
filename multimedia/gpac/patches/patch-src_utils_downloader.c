$NetBSD: patch-src_utils_downloader.c,v 1.1 2020/01/10 21:16:40 joerg Exp $

Don't use ancient SSLeay functions. SSLey_add_ssl_algorithms() is mapped to
SSL_library_init().

--- src/utils/downloader.c.orig	2020-01-09 00:48:40.383588739 +0000
+++ src/utils/downloader.c
@@ -392,8 +392,9 @@ static Bool init_ssl_lib() {
 	}
 	SSL_library_init();
 	SSL_load_error_strings();
-	SSLeay_add_all_algorithms();
-	SSLeay_add_ssl_algorithms();
+	OPENSSL_init_crypto(OPENSSL_INIT_ADD_ALL_CIPHERS
+	                | OPENSSL_INIT_ADD_ALL_DIGESTS
+	                | OPENSSL_INIT_LOAD_CONFIG, NULL);
 	_ssl_is_initialized = GF_TRUE;
 	GF_LOG(GF_LOG_DEBUG, GF_LOG_NETWORK, ("[HTTPS] Initalization of SSL library complete.\n"));
 	return GF_FALSE;
