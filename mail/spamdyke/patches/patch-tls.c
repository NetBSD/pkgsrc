$NetBSD: patch-tls.c,v 1.1 2020/07/02 08:50:09 schmonz Exp $

Support OpenSSL 1.1.x.

--- tls.c.orig	2015-04-30 00:53:36.000000000 +0000
+++ tls.c
@@ -186,7 +186,11 @@ int tls_init_inner(struct filter_setting
 
   if (!initialized)
     {
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     SSL_library_init();
+#else
+    OPENSSL_init_ssl(0, NULL);
+#endif
 
     if (!RAND_status())
       {
