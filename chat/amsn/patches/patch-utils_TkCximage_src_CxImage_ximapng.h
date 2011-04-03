$NetBSD: patch-utils_TkCximage_src_CxImage_ximapng.h,v 1.1 2011/04/03 15:26:36 wiz Exp $

Fix build with png-1.5.

--- utils/TkCximage/src/CxImage/ximapng.h.orig	2008-03-07 19:14:37.000000000 +0000
+++ utils/TkCximage/src/CxImage/ximapng.h
@@ -64,8 +64,8 @@ protected:
 
     static void PNGAPI user_error_fn(png_structp png_ptr,png_const_charp error_msg)
 	{
-		strncpy((char*)png_ptr->error_ptr,error_msg,255);
-		longjmp(png_ptr->jmpbuf, 1);
+		strncpy((char*)png_get_error_ptr(png_ptr),error_msg,255);
+		longjmp(png_jmpbuf(png_ptr), 1);
 	}
 };
 
