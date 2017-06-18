$NetBSD: patch-ext_openssl_ossl__ssl.c,v 1.1 2017/06/18 13:45:11 taca Exp $

Utilize OPENSSL_NO_SSL2, do we still need it?

--- ext/openssl/ossl_ssl.c.orig	2017-03-27 01:40:50.000000000 +0000
+++ ext/openssl/ossl_ssl.c
@@ -65,7 +65,7 @@ static const struct {
     { #name"_server", (SSL_METHOD *(*)(void))name##_server_method, version }, \
     { #name"_client", (SSL_METHOD *(*)(void))name##_client_method, version }
 #endif
-#if defined(HAVE_SSLV2_METHOD)
+#if !defined(OPENSSL_NO_SSL2) && defined(HAVE_SSLV2_METHOD)
     OSSL_SSL_METHOD_ENTRY(SSLv2, SSL2_VERSION),
 #endif
 #if defined(HAVE_SSLV3_METHOD)
