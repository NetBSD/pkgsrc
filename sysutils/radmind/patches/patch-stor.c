$NetBSD: patch-stor.c,v 1.1 2019/05/03 11:04:34 hauke Exp $

Move to openssl 1.1 api

--- stor.c.orig	2010-12-13 03:42:49.000000000 +0000
+++ stor.c
@@ -32,6 +32,7 @@
 
 #include <snet.h>
 
+#include "openssl_compat.h"
 #include "applefile.h"
 #include "connect.h"
 #include "cksum.h"
@@ -136,7 +137,7 @@ stor_file( SNET *sn, char *pathdesc, cha
     ssize_t             rr, size = 0;
     unsigned int	md_len;
     extern EVP_MD       *md;
-    EVP_MD_CTX          mdctx;
+    EVP_MD_CTX          *mdctx = EVP_MD_CTX_new();
     unsigned char       md_value[ EVP_MAX_MD_SIZE ];
     char       cksum_b64[ SZ_BASE64_E( EVP_MAX_MD_SIZE ) ];
 
@@ -146,7 +147,7 @@ stor_file( SNET *sn, char *pathdesc, cha
 	    fprintf( stderr, "line %d: No checksum listed\n", linenum );
 	    exit( 2 );
         }
-	EVP_DigestInit( &mdctx, md );
+	EVP_DigestInit( mdctx, md );
     }
 
     /* Open and stat file */
@@ -202,7 +203,7 @@ stor_file( SNET *sn, char *pathdesc, cha
 	size -= rr;
 	if ( dodots ) { putc( '.', stdout ); fflush( stdout ); }
 	if ( cksum ) {
-	    EVP_DigestUpdate( &mdctx, buf, (unsigned int)rr );
+	    EVP_DigestUpdate( mdctx, buf, (unsigned int)rr );
 	}
 	
 	if ( showprogress ) {
@@ -237,8 +238,9 @@ stor_file( SNET *sn, char *pathdesc, cha
 
     /* cksum data sent */
     if ( cksum ) {
-	EVP_DigestFinal( &mdctx, md_value, &md_len );
+	EVP_DigestFinal( mdctx, md_value, &md_len );
 	base64_e( md_value, md_len, cksum_b64 );
+	EVP_MD_CTX_free(mdctx);
         if ( strcmp( trancksum, cksum_b64 ) != 0 ) {
 	    fprintf( stderr,
 		"line %d: checksum listed in transcript wrong\n", linenum );
@@ -262,7 +264,7 @@ stor_applefile( SNET *sn, char *pathdesc
     unsigned int      	md_len;
     unsigned int	rsrc_len;
     extern EVP_MD      	*md;
-    EVP_MD_CTX         	mdctx;
+    EVP_MD_CTX         	*mdctx = EVP_MD_CTX_new();
     unsigned char 	md_value[ EVP_MAX_MD_SIZE ];
     char		cksum_b64[ EVP_MAX_MD_SIZE ];
 
@@ -272,7 +274,7 @@ stor_applefile( SNET *sn, char *pathdesc
 	    fprintf( stderr, "line %d: No checksum listed\n", linenum );
 	    exit( 2 );
         }
-        EVP_DigestInit( &mdctx, md );
+        EVP_DigestInit( mdctx, md );
     }
 
     /* Check size listed in transcript */
@@ -339,7 +341,7 @@ stor_applefile( SNET *sn, char *pathdesc
     }
     size -= AS_HEADERLEN;
     if ( cksum ) {
-	EVP_DigestUpdate( &mdctx, (char *)&as_header, AS_HEADERLEN );
+	EVP_DigestUpdate( mdctx, (char *)&as_header, AS_HEADERLEN );
     }
     if ( dodots ) { putc( '.', stdout ); fflush( stdout ); }
     if ( showprogress ) {
@@ -357,7 +359,7 @@ stor_applefile( SNET *sn, char *pathdesc
     }
     size -= ( 3 * sizeof( struct as_entry ));
     if ( cksum ) {
-	EVP_DigestUpdate( &mdctx, (char *)&afinfo->as_ents,
+	EVP_DigestUpdate( mdctx, (char *)&afinfo->as_ents,
 	    (unsigned int)( 3 * sizeof( struct as_entry )));
     }
     if ( dodots ) { putc( '.', stdout ); fflush( stdout ); }
@@ -375,7 +377,7 @@ stor_applefile( SNET *sn, char *pathdesc
     }
     size -= FINFOLEN;
     if ( cksum ) {
-	EVP_DigestUpdate( &mdctx, afinfo->ai.ai_data, FINFOLEN );
+	EVP_DigestUpdate( mdctx, afinfo->ai.ai_data, FINFOLEN );
     }
     if ( dodots ) { putc( '.', stdout ); fflush( stdout ); }
     if ( showprogress ) {
@@ -393,7 +395,7 @@ stor_applefile( SNET *sn, char *pathdesc
 	    }
 	    size -= rc;
 	    if ( cksum ) {
-		EVP_DigestUpdate( &mdctx, buf, (unsigned int)rc );
+		EVP_DigestUpdate( mdctx, buf, (unsigned int)rc );
 	    } 
 	    if ( dodots ) { putc( '.', stdout ); fflush( stdout ); }
 	    if ( showprogress ) {
@@ -417,7 +419,7 @@ stor_applefile( SNET *sn, char *pathdesc
 	}
 	size -= rc;
 	if ( cksum ) {
-	    EVP_DigestUpdate( &mdctx, buf, (unsigned int)rc );
+	    EVP_DigestUpdate( mdctx, buf, (unsigned int)rc );
 	}
     	if ( dodots ) { putc( '.', stdout ); fflush( stdout ); }
 	if ( showprogress ) {
@@ -463,8 +465,9 @@ stor_applefile( SNET *sn, char *pathdesc
 
     /* cksum data sent */
     if ( cksum ) {
-        EVP_DigestFinal( &mdctx, md_value, &md_len );
+        EVP_DigestFinal( mdctx, md_value, &md_len );
         base64_e( ( char*)&md_value, md_len, cksum_b64 );
+	EVP_MD_CTX_free(mdctx);
         if ( strcmp( trancksum, cksum_b64 ) != 0 ) {
 	    fprintf( stderr,
 		"line %d: checksum listed in transcript wrong\n", linenum );
