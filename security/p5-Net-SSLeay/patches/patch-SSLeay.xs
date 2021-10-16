$NetBSD: patch-SSLeay.xs,v 1.1 2021/10/16 14:02:56 schmonz Exp $

Build with OpenBSD's LibreSSL (patch taken from OpenBSD ports).

--- SSLeay.xs.orig	Thu Jan 21 15:14:11 2021
+++ SSLeay.xs
@@ -6172,7 +6172,7 @@ SSL_total_renegotiations(ssl)
   OUTPUT:
   RETVAL
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
+#if (OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)) || (LIBRESSL_VERSION_NUMBER >= 0x2070000fL)
 void
 SSL_SESSION_get_master_key(s)
      SSL_SESSION *   s
