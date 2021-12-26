$NetBSD: patch-src_imagegdk.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for OCaml immutable strings.

--- src/imagegdk.ml.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/imagegdk.ml
@@ -31,7 +31,7 @@ let draw (obj : #GDraw.drawable) ?x ?y ?
   match tag image, image#blocks with
   | Rgb24 image, (1,1) ->
       let string = fst (image#unsafe_access 0 0) in
-      let buf = Gpointer.region_of_string string in
+      let buf = Gpointer.region_of_bytes string in
       obj#put_rgb_data ~width: image#width ~height: image#height
 	?x ?y ?dither ~row_stride:(image#width * 3) buf
   | _ -> failwith "Gdkrgb.draw"
@@ -41,7 +41,7 @@ let to_pixbuf image =
   match tag image, image#blocks with
   | Rgb24 image, (1,1) ->
       let string = fst (image#unsafe_access 0 0) in
-      let buf = Gpointer.region_of_string string in
+      let buf = Gpointer.region_of_bytes string in
       (* string may be GC'ed here? *)
       let pixbuf = 
 	GdkPixbuf.from_data ~width: image#width ~height: image#height
@@ -58,7 +58,8 @@ let to_pixbuf image =
 	  let blk = image#dump_block x y in
 	  let width = blk.Bitmap.Block.width in
 	  let height = blk.Bitmap.Block.height in
-	  let buf = Gpointer.region_of_string blk.Bitmap.Block.dump in
+          (* safe: temporary readonly access *)
+	  let buf = Gpointer.region_of_bytes (Bytes.unsafe_of_string blk.Bitmap.Block.dump) in
 	  let pixbuf =
 	    GdkPixbuf.from_data ~width ~height ~bits: 8
 	      ~rowstride:(width * 3) ~has_alpha: false buf 
