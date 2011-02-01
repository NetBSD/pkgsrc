$NetBSD: patch-plugins_image__loader_png__loader.c,v 1.1 2011/02/01 08:50:07 wiz Exp $

Fix build with png-1.5.

--- plugins/image_loader/png_loader.c.orig	2004-05-23 14:08:16.000000000 +0000
+++ plugins/image_loader/png_loader.c
@@ -255,7 +255,7 @@ gimv_png_load (GimvImageLoader *loader, 
       return NULL;
    }
 
-   if (setjmp (png_ptr->jmpbuf)) goto ERROR;
+   if (setjmp (png_jmpbuf(png_ptr))) goto ERROR;
 
    context.gio = gio;
    context.bytes_read = 0;
