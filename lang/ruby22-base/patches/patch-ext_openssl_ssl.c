$NetBSD: patch-ext_openssl_ssl.c,v 1.1 2015/10/14 18:38:57 sevan Exp $

Only enable SSLv3 methods if library provides support.

--- ext/openssl/ossl_ssl.c.orig	Sat Oct 10 17:31:20 2015
+++ ext/openssl/ossl_ssl.c
@@ -138,9 +138,12 @@ static const struct {
     OSSL_SSL_METHOD_ENTRY(SSLv2_server),
     OSSL_SSL_METHOD_ENTRY(SSLv2_client),
 #endif
+#if defined(HAVE_SSLV3_METHOD) && defined(HAVE_SSLV3_SERVER_METHOD) && \
+	defined(HAVE_SSLV3_CLIENT_METHOD)
     OSSL_SSL_METHOD_ENTRY(SSLv3),
     OSSL_SSL_METHOD_ENTRY(SSLv3_server),
     OSSL_SSL_METHOD_ENTRY(SSLv3_client),
+#endif
     OSSL_SSL_METHOD_ENTRY(SSLv23),
     OSSL_SSL_METHOD_ENTRY(SSLv23_server),
     OSSL_SSL_METHOD_ENTRY(SSLv23_client),
