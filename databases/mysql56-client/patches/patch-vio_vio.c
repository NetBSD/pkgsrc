$NetBSD: patch-vio_vio.c,v 1.3.2.2 2019/09/08 16:55:18 bsiegert Exp $

* Allow build with OpenSSL 1.1.

--- vio/vio.c.orig	2019-06-10 10:25:32.000000000 +0000
+++ vio/vio.c
@@ -384,7 +384,9 @@ void vio_end(void)
   yaSSL_CleanUp();
 #elif defined(HAVE_OPENSSL)
   // This one is needed on the client side
-  ERR_remove_state(0);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+  ERR_remove_thread_state(0);
+#endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
   ERR_free_strings();
   EVP_cleanup();
   CRYPTO_cleanup_all_ex_data();
