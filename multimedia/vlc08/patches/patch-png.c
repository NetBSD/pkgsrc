$NetBSD: patch-png.c,v 1.1 2011/12/06 22:02:24 sborrill Exp $

--- modules/codec/png.c.orig	2011-12-06 21:04:12.000000000 +0000
+++ modules/codec/png.c	2011-12-06 21:04:39.000000000 +0000
@@ -147,7 +147,7 @@
     p_info = png_create_info_struct( p_png );
     if( p_info == NULL )
     {
-        png_destroy_read_struct( &p_png, png_infopp_NULL, png_infopp_NULL );
+        png_destroy_read_struct( &p_png, NULL, NULL );
         block_Release( p_block ); *pp_block = NULL;
         return NULL;
     }
@@ -155,7 +155,7 @@
     p_end_info = png_create_info_struct( p_png );
     if( p_end_info == NULL )
     {
-        png_destroy_read_struct( &p_png, &p_info, png_infopp_NULL );
+        png_destroy_read_struct( &p_png, &p_info, NULL );
         block_Release( p_block ); *pp_block = NULL;
         return NULL;
     }
