$NetBSD: patch-t2pkg.c,v 1.1 2019/05/03 11:04:34 hauke Exp $

Move to openssl 1.1 api

--- t2pkg.c.orig	2010-12-13 03:42:49.000000000 +0000
+++ t2pkg.c
@@ -23,6 +23,7 @@
 #include <sys/vfs.h>
 #endif /* linux */
 
+#include "openssl_compat.h"
 #include "applefile.h"
 #include "base64.h"
 #include "transcript.h"
@@ -61,7 +62,7 @@ copy_file( struct transcript *t, char *d
     char		*trancksum = t->t_pinfo.pi_cksum_b64;
     char		*path = t->t_pinfo.pi_name;
     ssize_t		rr, size = 0;
-    EVP_MD_CTX          mdctx;
+    EVP_MD_CTX          *mdctx = EVP_MD_CTX_new();
     unsigned char       md_value[ EVP_MAX_MD_SIZE ];
     char       		cksum_b64[ SZ_BASE64_E( EVP_MAX_MD_SIZE ) ];
 #ifdef __APPLE__
@@ -83,7 +84,7 @@ copy_file( struct transcript *t, char *d
 	    fprintf( stderr, "line %d: no checksum\n", t->t_linenum );
 	    return( -1 );
 	}
-	EVP_DigestInit( &mdctx, md );
+	EVP_DigestInit( mdctx, md );
     }
 
     if (( rfd = open( src, O_RDONLY, 0 )) < 0 ) {
@@ -150,7 +151,7 @@ copy_file( struct transcript *t, char *d
 	    goto error2;
 	}
 	if ( cksum ) {
-	    EVP_DigestUpdate( &mdctx, ( char * )&header, ( unsigned int )rr );
+	    EVP_DigestUpdate( mdctx, ( char * )&header, ( unsigned int )rr );
 	}
 	size -= rr;
 	if ( showprogress ) {
@@ -175,7 +176,7 @@ copy_file( struct transcript *t, char *d
 	as_entry_netswap( &as_ents[ AS_DFE ] );
 
 	if ( cksum ) {
-	    EVP_DigestUpdate( &mdctx, ( char * )&as_ents, ( unsigned int )rr );
+	    EVP_DigestUpdate( mdctx, ( char * )&as_ents, ( unsigned int )rr );
 	}
 	size -= rr;
 	if ( showprogress ) {
@@ -198,7 +199,7 @@ copy_file( struct transcript *t, char *d
 	    goto error2;
 	}
 	if ( cksum ) {
-	    EVP_DigestUpdate( &mdctx, finfo, ( unsigned int )rr );
+	    EVP_DigestUpdate( mdctx, finfo, ( unsigned int )rr );
 	}
 	if ( showprogress ) {
 	    progressupdate( rr, path );
@@ -229,7 +230,7 @@ copy_file( struct transcript *t, char *d
 		goto error2;
 	    }
 	    if ( cksum ) {
-		EVP_DigestUpdate( &mdctx, buf, ( unsigned int )rr );
+		EVP_DigestUpdate( mdctx, buf, ( unsigned int )rr );
 	    }
 	    if ( showprogress ) {
 		progressupdate( rr, path );
@@ -248,7 +249,7 @@ copy_file( struct transcript *t, char *d
 	 * entries to the checksum digest.
 	 */
 	if ( cksum ) {
-	    EVP_DigestUpdate( &mdctx, &as_header, AS_HEADERLEN );
+	    EVP_DigestUpdate( mdctx, &as_header, AS_HEADERLEN );
 
 	    as_ents[AS_FIE].ae_id = ASEID_FINFO;
 	    as_ents[AS_FIE].ae_offset = AS_HEADERLEN +
@@ -274,7 +275,7 @@ copy_file( struct transcript *t, char *d
 	    as_entry_netswap( &as_ents[ AS_RFE ] );
 	    as_entry_netswap( &as_ents[ AS_DFE ] );
 
-	    EVP_DigestUpdate( &mdctx, ( char * )&as_ents,
+	    EVP_DigestUpdate( mdctx, ( char * )&as_ents,
 					    ( 3 * sizeof( struct as_entry )));
 	} 
 	size -= ( AS_HEADERLEN + ( 3 * sizeof( struct as_entry )) + FINFOLEN );
@@ -292,7 +293,7 @@ copy_file( struct transcript *t, char *d
 	    }
 	}
 	if ( cksum ) {
-	    EVP_DigestUpdate( &mdctx, ai.ai_data, FINFOLEN );
+	    EVP_DigestUpdate( mdctx, ai.ai_data, FINFOLEN );
 	}
 
 	/* read and write the finder info and rsrc fork from the system */
@@ -318,7 +319,7 @@ copy_file( struct transcript *t, char *d
 		    goto error2;
 		}
 		if ( cksum ) {
-		    EVP_DigestUpdate( &mdctx, buf, rr );
+		    EVP_DigestUpdate( mdctx, buf, rr );
 		}
 		size -= rr;
 		if ( showprogress ) {
@@ -354,7 +355,7 @@ copy_file( struct transcript *t, char *d
 	    goto error2;
 	}
 	if ( cksum ) {
-	    EVP_DigestUpdate( &mdctx, buf, rr );
+	    EVP_DigestUpdate( mdctx, buf, rr );
 	}
 	size -= rr;
 	if ( showprogress ) {
@@ -383,8 +384,9 @@ copy_file( struct transcript *t, char *d
     }
 
     if ( cksum ) {
-	EVP_DigestFinal( &mdctx, md_value, &md_len );
+	EVP_DigestFinal( mdctx, md_value, &md_len );
 	base64_e( md_value, md_len, ( char * )cksum_b64 );
+        EVP_MD_CTX_free(mdctx);
 	if ( strcmp( trancksum, cksum_b64 ) != 0 ) {
 	    if ( force ) {
 		fprintf( stderr, "warning: " );
