$NetBSD: patch-src_main.c,v 1.3 2020/04/16 14:03:29 manu Exp $

From upstream:
Negotiate highest TLS protocol possible, with TLSv1.0 being the minium.

Local patch:
Fixes to build with OpenSSL 1.1.1

--- src/main.c.orig	2010-07-26 09:21:19.000000000 +0200
+++ src/main.c	2020-04-16 15:44:18.020665162 +0200
@@ -470,26 +470,36 @@
 
 	    /* Set up OpenSSL thread protection */
 	    ssl_thread_setup(fn);
 	    
+
             /* Need to seed PRNG, too! */
+# ifndef OPENSSL_NO_EGD
             if ( RAND_egd( ( RAND_file_name( f_randfile, sizeof( f_randfile ) ) == f_randfile ) ? f_randfile : "/.rnd" ) ) 
+#endif
 	    {
                 /* Not an EGD, so read and write it. */
                 if ( RAND_load_file( f_randfile, -1 ) )
                     RAND_write_file( f_randfile );
             }
 	
 	    SSL_load_error_strings();
-	    tls_ctx = SSL_CTX_new( TLSv1_client_method() );
+
+	    /* 
+	     * Despite its name, SSLv23_client_method() negociates highest
+	     * version possible, which includes TLSv1.0, TLSv1.1, and TLSv1.2. 
+	     * SSLv2 and SSLv3 are disabled using SSL_OP_NO_SSLv2 and 
+	     * SSL_OP_NO_SSLv3 below.
+	     */ 
+	    tls_ctx = SSL_CTX_new( SSLv23_client_method() );
 	    if ( tls_ctx == NULL )
-	    {
+	    { 
 		syslog(LOG_ERR, "%s: Failed to create new SSL_CTX.  Exiting.", fn);
 		exit( 1 );
 	    }
-
-	    /* Work around all known bugs */
-	    SSL_CTX_set_options( tls_ctx, SSL_OP_ALL );
+	 
+	    /* Work around all known bugs, disable SSLv2 and SSLv3 */
+	    SSL_CTX_set_options( tls_ctx, SSL_OP_ALL | SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3 );
 
 	    if ( ! SSL_CTX_load_verify_locations( tls_ctx,
 						  PC_Struct.tls_ca_file,
 						  PC_Struct.tls_ca_path ) ||
@@ -1380,11 +1390,11 @@
 	    ok = 0;
 	    verify_error = X509_V_ERR_CERT_CHAIN_TOO_LONG;
 	}
     }
-    switch (ctx->error) {
+    switch (X509_STORE_CTX_get_error(ctx)) {
     case X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT:
-	X509_NAME_oneline(X509_get_issuer_name(ctx->current_cert), buf, sizeof(buf));
+	X509_NAME_oneline(X509_get_issuer_name(X509_STORE_CTX_get_current_cert(ctx)), buf, sizeof(buf));
 	syslog(LOG_NOTICE, "issuer= %s", buf);
 	break;
     case X509_V_ERR_CERT_NOT_YET_VALID:
     case X509_V_ERR_ERROR_IN_CERT_NOT_BEFORE_FIELD:
