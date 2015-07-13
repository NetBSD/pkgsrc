$NetBSD: patch-contrib_mod_tls.c,v 1.3 2015/07/13 15:39:27 he Exp $

Add a specific other OpenSSL version to avoid re-negotiation for.

--- contrib/mod_tls.c.orig	2015-05-28 00:25:54.000000000 +0000
+++ contrib/mod_tls.c
@@ -7204,7 +7204,7 @@ static int tls_netio_write_cb(pr_netio_s
     if (tls_data_renegotiate_limit &&
         session.xfer.total_bytes >= tls_data_renegotiate_limit
 
-#if OPENSSL_VERSION_NUMBER >= 0x009080cfL
+#if OPENSSL_VERSION_NUMBER >= 0x009080cfL && OPENSSL_VERSION_NUMBER != 0x00909000L
         /* In OpenSSL-0.9.8l and later, SSL session renegotiations
          * (both client- and server-initiated) are automatically disabled.
          * Unless the admin explicitly configured support for
