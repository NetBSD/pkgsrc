$NetBSD: patch-src_xvthumb.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/xvthumb.ml.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/xvthumb.ml
@@ -19,10 +19,10 @@ open Images;;
 (********************************************************************** load *)
 
 let read_id ic =
-  let buf = String.create 7 in
+  let buf = Bytes.create 7 in
   try
     really_input ic buf 0 7;
-    if buf = "P7 332\n" then ()
+    if Bytes.to_string buf = "P7 332\n" then ()
     else begin
       prerr_endline "wrong header id";
       raise Wrong_image_type
@@ -79,10 +79,12 @@ let cmap_332 () =
 
 let load_body ic w h =
   let length = w * h in
-  let str = String.create length in
+  let str = Bytes.create length in
   try
     really_input ic str 0 length;
-    Index8.create_with w h [] (cmap_332 ()) (-1) str
+    (* safe: we just created it AND create_with copies it *)
+    let str' = Bytes.unsafe_to_string str in
+    Index8.create_with w h [] (cmap_332 ()) (-1) str'
   with
   | _ ->
       prerr_endline "short";
@@ -161,8 +163,12 @@ let create img =
 	resized
     | Rgba32 _ | Cmyk32 _ -> failwith "RGBA and CMYK not supported"
   in
+  (*
+   * XXX this creates and copies a batch of uninitialized data to
+   * create an uninitialized image to fill in, which is silly.
+   *)
   let thumb = Index8.create_with nw nh [] (cmap_332 ()) (-1)
-      (String.create (nw * nh))
+      (Bytes.unsafe_to_string (Bytes.create (nw * nh)))
   in
   for y = 0 to nh - 1 do
     for x = 0 to nw - 1 do
