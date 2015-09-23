$NetBSD: patch-src_main.c,v 1.1 2015/09/23 08:32:15 manu Exp $

From upstream:
Negotiate highest TLS protocol possible, with TLSv1.0 being the minium.

--- src/main.c.orig	2015-09-23 09:44:41.000000000 +0200
+++ src/main.c	2015-09-23 09:49:30.000000000 +0200
@@ -479,17 +479,24 @@
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
