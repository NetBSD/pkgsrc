$NetBSD: patch-spamc_libspamc.c,v 1.1 2018/03/17 09:14:35 tnn Exp $

Set the client protocol to TLS instead of SSLv3.
Fixes build with current openssl.

--- spamc/libspamc.c.orig	2015-04-28 19:56:59.000000000 +0000
+++ spamc/libspamc.c
@@ -1213,11 +1213,7 @@ int message_filter(struct transport *tp,
     if (flags & SPAMC_USE_SSL) {
 #ifdef SPAMC_SSL
 	SSLeay_add_ssl_algorithms();
-	if (flags & SPAMC_TLSV1) {
-	    meth = TLSv1_client_method();
-	} else {
-	    meth = SSLv3_client_method(); /* default */
-	}
+	meth = TLSv1_client_method();
 	SSL_load_error_strings();
 	ctx = SSL_CTX_new(meth);
 #else
@@ -1604,7 +1600,7 @@ int message_tell(struct transport *tp, c
     if (flags & SPAMC_USE_SSL) {
 #ifdef SPAMC_SSL
 	SSLeay_add_ssl_algorithms();
-	meth = SSLv3_client_method();
+	meth = TLSv1_client_method();
 	SSL_load_error_strings();
 	ctx = SSL_CTX_new(meth);
 #else
