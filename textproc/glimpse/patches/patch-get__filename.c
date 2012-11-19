$NetBSD: patch-get__filename.c,v 1.1 2012/11/19 03:05:04 joerg Exp $

--- get_filename.c.orig	2012-11-18 22:58:10.000000000 +0000
+++ get_filename.c
@@ -481,6 +481,7 @@ endofinput:
 	return 0;
 }
 
+void
 get_filenames(index_vect, argc, argv, dummylen, dummypat, file_num)
 int  *index_vect;
 int argc; /* the arguments to agrep for -F */
