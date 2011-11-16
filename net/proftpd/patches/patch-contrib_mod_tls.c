$NetBSD: patch-contrib_mod_tls.c,v 1.1.6.1 2011/11/16 21:06:50 sbd Exp $

--- contrib/mod_tls.c.orig	2011-03-25 13:53:45.000000000 +0000
+++ contrib/mod_tls.c
@@ -7235,7 +7235,7 @@ static int tls_sess_init(void) {
   if (opts != NULL)
     tls_opts = *opts;
 
-#if OPENSSL_VERSION_NUMBER > 0x009080cfL
+#if OPENSSL_VERSION_NUMBER > 0x009080cfL && OPENSSL_VERSION_NUMBER != 0x00909000L
   /* The OpenSSL team realized that the flag added in 0.9.8l, the
    * SSL3_FLAGS_ALLOW_UNSAFE_LEGACY_RENEGOTIATION flag, was a bad idea.
    * So in later versions, it was changed to a context flag,
