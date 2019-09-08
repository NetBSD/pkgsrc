$NetBSD: patch-sql_mysqld.cc,v 1.5.2.2 2019/09/08 16:55:18 bsiegert Exp $

* Allow build with OpenSSL 1.1.

--- sql/mysqld.cc.orig	2019-06-10 10:25:32.000000000 +0000
+++ sql/mysqld.cc
@@ -2759,9 +2759,9 @@ bool one_thread_per_connection_end(THD *
   }
 
   // Clean up errors now, before possibly waiting for a new connection.
-#ifndef EMBEDDED_LIBRARY
-  ERR_remove_state(0);
-#endif
+#if !defined(EMBEDDED_LIBRARY) && OPENSSL_VERSION_NUMBER < 0x10100000L
+  ERR_remove_thread_state(0);
+#endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
 
   delete thd;
 
@@ -4358,7 +4358,11 @@ static int init_ssl()
 {
 #ifdef HAVE_OPENSSL
 #ifndef HAVE_YASSL
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
   CRYPTO_malloc_init();
+#else /* OPENSSL_VERSION_NUMBER < 0x10100000L */
+  OPENSSL_malloc_init();
+#endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
 #endif
   ssl_start();
 #ifndef EMBEDDED_LIBRARY
@@ -4372,7 +4376,9 @@ static int init_ssl()
 					  opt_ssl_cipher, &error,
                                           opt_ssl_crl, opt_ssl_crlpath);
     DBUG_PRINT("info",("ssl_acceptor_fd: 0x%lx", (long) ssl_acceptor_fd));
-    ERR_remove_state(0);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+    ERR_remove_thread_state(0);
+#endif /* OPENSSL_VERSION_NUMBER < 0x10100000L */
     if (!ssl_acceptor_fd)
     {
       sql_print_warning("Failed to setup SSL");
