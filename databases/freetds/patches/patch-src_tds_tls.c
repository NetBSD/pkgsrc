$NetBSD: patch-src_tds_tls.c,v 1.1 2023/03/29 21:01:38 joerg Exp $

Allow building with LibreSSL 3.7.0

--- src/tds/tls.c.orig	2018-04-03 09:00:03.000000000 +0000
+++ src/tds/tls.c
@@ -594,7 +594,7 @@ tds_ssl_free(BIO *a)
 	return 1;
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x1010000FL || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x1010000FL || (defined(LIBRESSL_VERSION_NUMBER) && (LIBRESSL_VERSION_NUMBER - 0 < 0x3070000fL))
 static BIO_METHOD tds_method_login[1] = {
 {
 	BIO_TYPE_MEM,
@@ -949,6 +949,9 @@ tds_ssl_init(TDSSOCKET *tds)
 	/* Perform the TLS handshake */
 	tls_msg = "handshake";
 	SSL_set_connect_state(con);
+#ifndef TLS_STOK
+#define TLS_ST_OK SSL_ST_OK
+#endif
 	ret = SSL_connect(con) != 1 || SSL_get_state(con) != TLS_ST_OK;
 	if (ret != 0)
 		goto cleanup;
