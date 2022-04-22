$NetBSD: patch-Modules___hashopenssl.c,v 1.1 2022/04/22 14:25:35 sjmulder Exp $

Fix version check for OpenBSD. Adapted from OpenBSD port.

--- Modules/_hashopenssl.c.orig	Wed Mar 23 21:12:08 2022
+++ Modules/_hashopenssl.c
@@ -43,7 +43,8 @@
 #  error "OPENSSL_THREADS is not defined, Python requires thread-safe OpenSSL"
 #endif
 
-#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER)
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L) || \
+    (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x2070000fL)
 /* OpenSSL < 1.1.0 */
 #define EVP_MD_CTX_new EVP_MD_CTX_create
 #define EVP_MD_CTX_free EVP_MD_CTX_destroy
