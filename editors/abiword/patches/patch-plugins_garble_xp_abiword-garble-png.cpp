$NetBSD: patch-plugins_garble_xp_abiword-garble-png.cpp,v 1.1 2011/02/01 10:48:15 wiz Exp $

Fix build with png-1.5.

--- plugins/garble/xp/abiword-garble-png.cpp.orig	2009-09-05 15:34:44.000000000 +0000
+++ plugins/garble/xp/abiword-garble-png.cpp
@@ -79,7 +79,7 @@ bool abiword_document::garble_png( void*
 		png_set_strip_alpha( png_ptr );
 		png_set_interlace_handling( png_ptr );
 		png_set_bgr( png_ptr );
-		rowbytes = info_ptr->rowbytes;
+		rowbytes = png_get_rowbytes( png_ptr, info_ptr );
 		png_destroy_read_struct( &png_ptr, &info_ptr, NULL );
 	}
 
