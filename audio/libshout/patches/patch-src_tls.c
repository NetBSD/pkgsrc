$NetBSD: patch-src_tls.c,v 1.1 2018/03/05 09:16:28 kamil Exp $

Support OpenSSL 1.1

--- src/tls.c.orig	2015-06-18 04:27:45.000000000 +0000
+++ src/tls.c
@@ -65,7 +65,11 @@ static inline int tls_setup(shout_tls_t 
 
 	SSL_library_init();
 	SSL_load_error_strings();
+#if OPENSSL_VERSION_NUMBER >= 0x10100000
+	OpenSSL_add_all_algorithms();
+#else
 	SSLeay_add_all_algorithms();
+#endif
  	SSLeay_add_ssl_algorithms();
 
 	meth = TLSv1_client_method();
