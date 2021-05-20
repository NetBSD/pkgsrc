$NetBSD: patch-Modules___ssl.c,v 1.1 2021/05/20 06:56:43 triaxx Exp $

Fix build failure on FreeBSD 12.
From https://github.com/python/cpython/commit/3309113

--- Modules/_ssl.c.orig	2021-05-14 15:52:07.251636000 +0200
+++ Modules/_ssl.c	2021-05-14 15:52:37.012941000 +0200
@@ -151,6 +151,9 @@
  * unless OpenSSL is compiled without the methods. It's the easiest way to
  * make 1.0.2, 1.1.0, 1.1.1, and 3.0.0 happy without deprecation warnings.
  */
+#ifndef OPENSSL_NO_SSL3_METHOD
+extern const SSL_METHOD *SSLv3_method(void);
+#endif
 #ifndef OPENSSL_NO_TLS1_METHOD
 extern const SSL_METHOD *TLSv1_method(void);
 #endif
