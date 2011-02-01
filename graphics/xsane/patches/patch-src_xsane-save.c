$NetBSD: patch-src_xsane-save.c,v 1.1 2011/02/01 10:32:00 wiz Exp $

Fix build with png-1.5.

--- src/xsane-save.c.orig	2007-03-03 08:59:45.000000000 +0000
+++ src/xsane-save.c
@@ -4833,7 +4833,7 @@ int xsane_save_png(FILE *outfile, int co
     return -1; /* error */
   }
 
-  if (setjmp(png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(png_ptr)))
   {
     snprintf(buf, sizeof(buf), "%s %s", ERR_DURING_SAVE, ERR_LIBPNG);
     xsane_back_gtk_error(buf, TRUE);
@@ -5026,7 +5026,7 @@ int xsane_save_png_16(FILE *outfile, int
     return -1; /* error */
   }
 
-  if (setjmp(png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(png_ptr)))
   {
     snprintf(buf, sizeof(buf), "%s %s", ERR_DURING_SAVE, ERR_LIBPNG);
     xsane_back_gtk_error(buf, TRUE);
