$NetBSD: patch-src_uigtk2.ml,v 1.2 2018/04/30 10:23:49 wiz Exp $

Lablgtk now has safe_string
https://github.com/bcpierce00/unison/commit/2e7ea9481c6c3ff2ec513c39f73cfe15c0763c06

--- src/uigtk2.ml.orig	2015-10-05 18:14:23.000000000 +0000
+++ src/uigtk2.ml
@@ -94,7 +94,7 @@ let icon =
 let icon =
   let p = GdkPixbuf.create ~width:48 ~height:48 ~has_alpha:true () in
   Gpointer.blit
-    (Gpointer.region_of_string Pixmaps.icon_data) (GdkPixbuf.get_pixels p);
+    (Gpointer.region_of_bytes Pixmaps.icon_data) (GdkPixbuf.get_pixels p);
   p
 
 let leftPtrWatch =
