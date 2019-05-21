$NetBSD: patch-src_tls.c,v 1.2 2019/05/21 15:49:27 wiz Exp $

Fix build with OpenSSL-1.1.

--- src/tls.c.orig	2019-04-29 10:00:11.000000000 +0000
+++ src/tls.c
@@ -90,7 +90,11 @@ static inline int tls_setup(shout_tls_t 
 
     SSL_library_init();
     SSL_load_error_strings();
+#if OPENSSL_VERSION_NUMBER >= 0x10100000
+    OpenSSL_add_all_algorithms();
+#else
     SSLeay_add_all_algorithms();
+#endif
     SSLeay_add_ssl_algorithms();
 
     meth = TLSv1_client_method();
