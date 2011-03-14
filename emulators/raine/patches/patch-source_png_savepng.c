$NetBSD: patch-source_png_savepng.c,v 1.1 2011/03/14 12:04:31 obache Exp $

--- source/png/savepng.c.orig	2005-08-17 10:20:36.000000000 +0000
+++ source/png/savepng.c
@@ -188,7 +188,7 @@ static int really_save_png(PACKFILE *fp,
 	goto Error;
 
     /* Set error handling. */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	/* If we get here, we had a problem reading the file. */
 	goto Error;
     }
