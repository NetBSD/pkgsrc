$NetBSD: patch-utilssdl_PNG.cpp,v 1.1 2011/06/20 09:30:03 wiz Exp $

Fix build with png-1.5.

--- utilssdl/PNG.cpp.orig	2004-12-18 02:41:42.000000000 +0000
+++ utilssdl/PNG.cpp
@@ -45,7 +45,7 @@ void PNG::writeData( png_structp png, pn
 {
     png_size_t check;
 
-    check = fwrite( data, 1, length, (FILE *)(png->io_ptr));
+    check = fwrite( data, 1, length, (FILE *)(png_get_io_ptr(png)));
     if( check != length)
     {
 	png_error( png, "Write Error");
@@ -72,7 +72,7 @@ bool PNG::init( FILE *fp, int width, int
 	return false;
     }
 
-    if( setjmp(_png->jmpbuf))
+    if( setjmp(png_jmpbuf(_png)))
     {
 	fclose( fp);
 	png_destroy_write_struct(&_png, (png_infopp)NULL);
