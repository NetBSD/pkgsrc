$NetBSD: patch-ptstream.c,v 1.1 2020/03/01 18:20:34 nia Exp $

Migrate from SSLv3

--- ptstream.c.orig	2008-02-26 23:27:27.000000000 +0000
+++ ptstream.c
@@ -151,7 +151,7 @@ int stream_enable_ssl(PTSTREAM *pts) {
 	
 	/* Initialise the connection */
 	SSLeay_add_ssl_algorithms();
-	meth = SSLv3_client_method();
+	meth = SSLv23_client_method();
 	SSL_load_error_strings();
 
 	ctx = SSL_CTX_new (meth);
