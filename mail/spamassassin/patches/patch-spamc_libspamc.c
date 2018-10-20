$NetBSD: patch-spamc_libspamc.c,v 1.1.6.1 2018/10/20 15:59:14 spz Exp $

Set the client protocol to TLS instead of SSLv3.
Fixes build with current openssl.

--- spamc/libspamc.c.orig	2015-04-28 19:56:59.000000000 +0000
+++ spamc/libspamc.c
@@ -1214,7 +1214,7 @@
     if (flags & SPAMC_USE_SSL) {
 #ifdef SPAMC_SSL
 	SSLeay_add_ssl_algorithms();
-	meth = SSLv23_client_method();
+	meth = TLSv1_client_method();
 	SSL_load_error_strings();
 	ctx = SSL_CTX_new(meth);
 #else
@@ -1601,7 +1601,7 @@
     if (flags & SPAMC_USE_SSL) {
 #ifdef SPAMC_SSL
 	SSLeay_add_ssl_algorithms();
-	meth = SSLv23_client_method();
+	meth = TLSv1_client_method();
 	SSL_load_error_strings();
 	ctx = SSL_CTX_new(meth);
 #else
