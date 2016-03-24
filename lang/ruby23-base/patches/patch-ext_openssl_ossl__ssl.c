$NetBSD: patch-ext_openssl_ossl__ssl.c,v 1.1 2016/03/24 16:29:24 taca Exp $

Utilize OPENSSL_NO_SSL2.

--- ext/openssl/ossl_ssl.c.orig	2015-12-13 01:29:44.000000000 +0000
+++ ext/openssl/ossl_ssl.c
@@ -102,7 +102,7 @@ static const struct {
     OSSL_SSL_METHOD_ENTRY(TLSv1_1_server),
     OSSL_SSL_METHOD_ENTRY(TLSv1_1_client),
 #endif
-#if defined(HAVE_SSLV2_METHOD) && defined(HAVE_SSLV2_SERVER_METHOD) && \
+#if !defined(OPENSSL_NO_SSL2) && defined(HAVE_SSLV2_METHOD) && defined(HAVE_SSLV2_SERVER_METHOD) && \
         defined(HAVE_SSLV2_CLIENT_METHOD)
     OSSL_SSL_METHOD_ENTRY(SSLv2),
     OSSL_SSL_METHOD_ENTRY(SSLv2_server),
