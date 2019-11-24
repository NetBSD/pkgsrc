$NetBSD: patch-opendkim_opendkim-crypto.c,v 1.1 2019/11/24 23:20:40 christos Exp $

- OpenSSL 1.1 compat https://sourceforge.net/p/opendkim/patches/37/

--- opendkim/opendkim-crypto.c.orig	2013-02-25 16:02:41.000000000 -0500
+++ opendkim/opendkim-crypto.c	2019-11-24 18:04:07.924299914 -0500
@@ -222,7 +222,11 @@
 	{
 		assert(pthread_setspecific(id_key, ptr) == 0);
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100000
+		OPENSSL_thread_stop();
+#else
 		ERR_remove_state(0);
+#endif
 
 		free(ptr);
 
@@ -392,11 +396,15 @@
 {
 	if (crypto_init_done)
 	{
+#if OPENSSL_VERSION_NUMBER >= 0x10100000
+		OPENSSL_thread_stop();
+#else
 		CRYPTO_cleanup_all_ex_data();
 		CONF_modules_free();
 		EVP_cleanup();
 		ERR_free_strings();
 		ERR_remove_state(0);
+#endif
 
 		if (nmutexes > 0)
 		{
