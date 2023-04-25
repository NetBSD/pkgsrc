$NetBSD: patch-src_tds_tls.c,v 1.2 2023/04/25 13:41:16 wiz Exp $

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
