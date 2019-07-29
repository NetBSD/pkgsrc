$NetBSD: patch-src_uigtk2.ml,v 1.1 2019/07/29 18:07:10 wiz Exp $

Lablgtk now has safe_string
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
