$NetBSD: patch-sql_mysqld.cc,v 1.1 2018/02/25 01:15:22 markd Exp $

support openssl 1.1 
from https://bugs.mysql.com/bug.php?id=83814

--- sql/mysqld.cc.orig	2017-12-28 03:46:26.000000000 +0000
+++ sql/mysqld.cc
@@ -3398,7 +3398,11 @@ static int init_ssl()
 {
 #ifdef HAVE_OPENSSL
 #ifndef HAVE_YASSL
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
   CRYPTO_malloc_init();
+#else
+  OPENSSL_malloc_init();
+#endif
 #endif
   ssl_start();
 #ifndef EMBEDDED_LIBRARY
