$NetBSD: patch-src_common_tls.c,v 1.1 2019/09/07 16:25:53 maya Exp $

OpenSSL 1.1.x support.
Newer OpenSSL will do atexit(OPENSSL_cleanup) by default.

--- src/common/tls.c.orig	2014-07-15 12:07:02.000000000 +0000
+++ src/common/tls.c
@@ -419,7 +419,11 @@ initialize_openssl(const SSL_METHOD *met
 
 	(void)SSL_library_init();
 	SSL_load_error_strings();
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	(void)atexit(ERR_free_strings);
+#else
+	(void)atexit(OPENSSL_cleanup);
+#endif
 
 	/*
 	 * In earlier versions, we called
