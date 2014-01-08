$NetBSD: patch-lcksum.c,v 1.1.2.2 2014/01/08 18:53:27 tron Exp $

--- lcksum.c.orig	2010-12-13 03:42:49.000000000 +0000
+++ lcksum.c
@@ -434,7 +434,7 @@ do_lcksum( char *tpath )
 		/* Check to see if checksum is listed in transcript */
 		if ( strcmp( targv[ 7 ], "-" ) != 0) {
 		    /* use mtime from server */
-		    fprintf( ufs, "%s %-37s %4s %5s %5s %9ld "
+		    fprintf( ufs, "%s %-37s %4s %5s %5s %9" PRItimet "d "
 			    "%7" PRIofft "d %s\n",
 			targv[ 0 ], targv[ 1 ], targv[ 2 ], targv[ 3 ],
 			targv[ 4 ], st.st_mtime, st.st_size, lcksum );
