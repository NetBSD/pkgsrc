$NetBSD: patch-src_glpng.c,v 1.1 2011/04/03 16:38:41 wiz Exp $

Fix build with png-1.5.

--- src/glpng.c.orig	2009-05-04 18:51:48.000000000 +0000
+++ src/glpng.c
@@ -278,7 +278,7 @@ int APIENTRY pngLoadRawF(FILE *fp, pngRa
 	endinfo = png_create_info_struct(png);
 
 	// DH: added following lines
-	if (setjmp(png->jmpbuf))
+	if (setjmp(png_jmpbuf(png)))
 	{
 		png_destroy_read_struct(&png, &info, &endinfo);
 		return 0;
@@ -382,7 +382,7 @@ int APIENTRY pngLoadF(FILE *fp, int mipm
 	endinfo = png_create_info_struct(png);
 
 	// DH: added following lines
-	if (setjmp(png->jmpbuf))
+	if (setjmp(png_jmpbuf(png)))
 	{
 		png_destroy_read_struct(&png, &info, &endinfo);
 		return 0;
@@ -561,7 +561,7 @@ int APIENTRY pngLoadF(FILE *fp, int mipm
 			#define ALPHA *q
 
 			switch (trans) {
-				case PNG_CALLBACK:
+				case PNG_CALLBACKT:
 					FORSTART
 						ALPHA = AlphaCallback((unsigned char) r, (unsigned char) g, (unsigned char) b);
 					FOREND
