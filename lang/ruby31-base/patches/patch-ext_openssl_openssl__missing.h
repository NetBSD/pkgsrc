$NetBSD: patch-ext_openssl_openssl__missing.h,v 1.1 2022/01/16 13:57:10 taca Exp $

Support OpenSSL 3.

--- ext/openssl/openssl_missing.h.orig	2021-07-07 10:08:35.000000000 +0000
+++ ext/openssl/openssl_missing.h
@@ -235,7 +235,7 @@ IMPL_PKEY_GETTER(EC_KEY, ec)
 #  define TS_STATUS_INFO_get0_failure_info(a) ((a)->failure_info)
 #endif
 
-#if !defined(HAVE_TS_VERIFY_CTS_SET_CERTS)
+#if !defined(HAVE_TS_VERIFY_CTS_SET_CERTS) && !defined(TS_VERIFY_CTS_set_certs)
 #  define TS_VERIFY_CTS_set_certs(ctx, crts) ((ctx)->certs=(crts))
 #endif
 
