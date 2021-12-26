$NetBSD: patch-src_genimage.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/genimage.ml.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/genimage.ml
@@ -33,6 +33,7 @@ module MakeRawImage(E:ENCODE) = struct
 
   let width t = t.width
   let height t = t.height
+  let dumpbytes t = Bitmap.dumpbytes t.bitmap
   let dump t = Bitmap.dump t.bitmap
 
   let create_with width height init_buffer =
@@ -57,9 +58,11 @@ module MakeRawImage(E:ENCODE) = struct
   ;;
 
   let make width height init =
+    (* safe: make returns a fresh bytes AND create copies it *)
+    let init' = Bytes.unsafe_to_string (E.make init) in
     { width= width;
       height= height;
-      bitmap= Bitmap.create width height (Some (E.make init));
+      bitmap= Bitmap.create width height (Some init');
     }
   ;;
 
@@ -126,6 +129,7 @@ module Make(RI:RAWIMAGE)(CON:CONTAINER w
   type elt = RI.elt
 
   let dump t = RI.dump (CON.rawimage t)
+  let dumpbytes t = RI.dumpbytes (CON.rawimage t)
 
   let create width height =
     CON.create_default width height (RI.create width height)
