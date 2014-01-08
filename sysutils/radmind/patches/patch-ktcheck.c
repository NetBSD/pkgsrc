$NetBSD: patch-ktcheck.c,v 1.1.2.2 2014/01/08 18:53:27 tron Exp $

--- ktcheck.c.orig	2010-12-13 03:42:49.000000000 +0000
+++ ktcheck.c
@@ -459,7 +459,7 @@ check( SNET *sn, char *type, char *file 
 	perror( "Incorrect number of arguments\n" );
 	return( 2 );
     }
-    times.modtime = atoi( targv[ 5 ] );
+    times.modtime = strtotimet( targv[ 5 ], NULL, 10 );
     times.actime = time( NULL );
 
     if (( stat( path, &st )) != 0 ) {
@@ -506,7 +506,7 @@ check( SNET *sn, char *type, char *file 
 		needupdate = 1;
 	    }
 	} else {
-	    if ( atoi( targv[ 5 ] ) != (int)st.st_mtime )  {
+	    if ( strtotimet( targv[ 5 ], NULL, 10 ) != st.st_mtime )  {
 		needupdate = 1;
 	    }
 	}
