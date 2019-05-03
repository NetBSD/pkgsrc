$NetBSD: patch-cksum.c,v 1.1 2019/05/03 11:04:34 hauke Exp $

Move to openssl 1.1 api

--- cksum.c.orig	2010-12-13 03:42:49.000000000 +0000
+++ cksum.c
@@ -20,6 +20,7 @@
 
 #include <openssl/evp.h>
 
+#include "openssl_compat.h"
 #include "applefile.h"
 #include "cksum.h"
 #include "base64.h"
@@ -41,21 +42,22 @@ do_fcksum( int fd, char *cksum_b64 )
     off_t		size = 0;
     unsigned char	buf[ 8192 ];
     extern EVP_MD	*md;
-    EVP_MD_CTX		mdctx;
+    EVP_MD_CTX		*mdctx = EVP_MD_CTX_new();
     unsigned char 	md_value[ EVP_MAX_MD_SIZE ];
 
-    EVP_DigestInit( &mdctx, md );
+    EVP_DigestInit( mdctx, md );
 
     while (( rr = read( fd, buf, sizeof( buf ))) > 0 ) {
 	size += rr;
-	EVP_DigestUpdate( &mdctx, buf, (unsigned int)rr );
+	EVP_DigestUpdate( mdctx, buf, (unsigned int)rr );
     }
     if ( rr < 0 ) {
 	return( -1 );
     }
 
-    EVP_DigestFinal( &mdctx, md_value, &md_len );
+    EVP_DigestFinal( mdctx, md_value, &md_len );
     base64_e( md_value, md_len, cksum_b64 );
+    EVP_MD_CTX_free(mdctx);
 
     return( size );
 }
@@ -103,13 +105,13 @@ do_acksum( char *path, char *cksum_b64, 
     struct as_entry		as_entries_endian[ 3 ];
     unsigned int		md_len;
     extern EVP_MD		*md;
-    EVP_MD_CTX          	mdctx;
+    EVP_MD_CTX          	*mdctx = EVP_MD_CTX_new();
     unsigned char       	md_value[ EVP_MAX_MD_SIZE ];
 
-    EVP_DigestInit( &mdctx, md ); 
+    EVP_DigestInit( mdctx, md ); 
 
     /* checksum applesingle header */
-    EVP_DigestUpdate( &mdctx, (char *)&as_header, AS_HEADERLEN );
+    EVP_DigestUpdate( mdctx, (char *)&as_header, AS_HEADERLEN );
     size += (size_t)AS_HEADERLEN;
 
     /* endian handling, sum big-endian header entries */
@@ -120,12 +122,12 @@ do_acksum( char *path, char *cksum_b64, 
     as_entry_netswap( &as_entries_endian[ AS_DFE ] );
 
     /* checksum header entries */
-    EVP_DigestUpdate( &mdctx, (char *)&as_entries_endian,
+    EVP_DigestUpdate( mdctx, (char *)&as_entries_endian,
 		(unsigned int)( 3 * sizeof( struct as_entry )));
     size += sizeof( 3 * sizeof( struct as_entry ));
 
     /* checksum finder info data */
-    EVP_DigestUpdate( &mdctx, afinfo->ai.ai_data, FINFOLEN );
+    EVP_DigestUpdate( mdctx, afinfo->ai.ai_data, FINFOLEN );
     size += FINFOLEN;
 
     /* checksum rsrc fork data */
@@ -140,7 +142,7 @@ do_acksum( char *path, char *cksum_b64, 
 	    return( -1 );
 	}
 	while (( rc = read( rfd, buf, sizeof( buf ))) > 0 ) {
-	    EVP_DigestUpdate( &mdctx, buf, (unsigned int)rc );
+	    EVP_DigestUpdate( mdctx, buf, (unsigned int)rc );
 	    size += (size_t)rc;
 	}
 	if ( close( rfd ) < 0 ) {
@@ -156,7 +158,7 @@ do_acksum( char *path, char *cksum_b64, 
     }
     /* checksum data fork */
     while (( rc = read( dfd, buf, sizeof( buf ))) > 0 ) {
-	EVP_DigestUpdate( &mdctx, buf, (unsigned int)rc );
+	EVP_DigestUpdate( mdctx, buf, (unsigned int)rc );
 	size += (size_t)rc;
     }
     if ( rc < 0 ) {
@@ -166,8 +168,9 @@ do_acksum( char *path, char *cksum_b64, 
 	return( -1 );
     }
 
-    EVP_DigestFinal( &mdctx, md_value, &md_len );
+    EVP_DigestFinal( mdctx, md_value, &md_len );
     base64_e( ( char*)&md_value, md_len, cksum_b64 );
+    EVP_MD_CTX_free();
 
     return( size );
 }
