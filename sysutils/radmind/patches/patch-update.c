$NetBSD: patch-update.c,v 1.1.2.2 2014/01/08 18:53:27 tron Exp $

--- update.c.orig	2010-12-13 03:42:49.000000000 +0000
+++ update.c
@@ -26,6 +26,7 @@
 #include "update.h"
 #include "code.h"
 #include "radstat.h"
+#include "largefile.h"
 #include "transcript.h"
 #include "progress.h"
 #include "mkdirs.h"
@@ -73,7 +74,7 @@ update( char *path, char *displaypath, i
 
 	mode = strtol( targv[ 2 ], (char **)NULL, 8 );
 
-	times.modtime = atoi( targv[ 5 ] );
+	times.modtime = strtotimet( targv[ 5 ], NULL, 10 );
 	if ( times.modtime != st->st_mtime ) {
 	    times.actime = st->st_atime;
 	    if ( utime( path, &times ) != 0 ) {
