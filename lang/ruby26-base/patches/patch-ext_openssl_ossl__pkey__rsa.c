$NetBSD: patch-ext_openssl_ossl__pkey__rsa.c,v 1.1 2021/11/09 12:13:03 jperkin Exp $

Support OpenSSL 3.

--- ext/openssl/ossl_pkey_rsa.c.orig	2021-07-07 10:38:58.000000000 +0000
+++ ext/openssl/ossl_pkey_rsa.c
@@ -939,7 +939,9 @@ Init_ossl_rsa(void)
     rb_define_method(cRSA, "params", ossl_rsa_get_params, 0);
 
     DefRSAConst(PKCS1_PADDING);
+#ifdef SSLV23_PADDING
     DefRSAConst(SSLV23_PADDING);
+#endif
     DefRSAConst(NO_PADDING);
     DefRSAConst(PKCS1_OAEP_PADDING);
 
