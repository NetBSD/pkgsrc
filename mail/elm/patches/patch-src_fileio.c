$NetBSD: patch-src_fileio.c,v 1.1 2013/02/26 11:08:17 joerg Exp $

--- src/fileio.c.orig	2013-02-25 16:40:58.000000000 +0000
+++ src/fileio.c
@@ -66,9 +66,7 @@ int err;
 }
 
 
-copy_message(dest_file, msgnum, cm_options)
-FILE *dest_file;
-int msgnum, cm_options;
+void copy_message(FILE *dest_file, int msgnum, int cm_options)
 {
 	/** Copy selected message to destination file, with optional 'prefix' 
 	    as the prefix for each line.  If remove_header is true, it will 
