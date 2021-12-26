$NetBSD: patch-src_tiff.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/tiff.ml.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/tiff.ml
@@ -23,7 +23,7 @@ type in_handle;;
 
 external open_in : string -> int * int * float * colormodel * in_handle
     = "open_tiff_file_for_read";;
-external read_scanline : in_handle -> string -> int -> unit
+external read_scanline : in_handle -> Bytes.t -> int -> unit
     = "read_tiff_scanline";;
 external close_in : in_handle -> unit
     = "close_tiff_file";;
@@ -45,23 +45,23 @@ let load name opts =
     | RGB ->
       	let img = Rgb24.create w h in
 	Rgb24 img,
-      	String.create (w * 3)
+      	Bytes.create (w * 3)
     | CMYK ->
 	let img = Cmyk32.create w h in
 	Cmyk32 img,
-      	String.create (w * 4)
+      	Bytes.create (w * 4)
     | WHITEBLACK ->
 	let img = Index8.create w h in
 	img.Index8.colormap.map <- [| {r = 255; g = 255; b = 255};
 				      {r = 0; g = 0; b = 0} |];
 	Index8 img,
-	String.create ((w + 7) / 8)
+	Bytes.create ((w + 7) / 8)
     | BLACKWHITE ->
 	let img = Index8.create w h in
 	img.Index8.colormap.map <- [| {r = 0; g = 0; b = 0};
 				      {r = 255; g = 255; b = 255} |];
 	Index8 img,
-	String.create ((w + 7) / 8) in
+	Bytes.create ((w + 7) / 8) in
 
   let set_scanline =
     match colormodel, img with
@@ -81,7 +81,8 @@ let load name opts =
 
   for y = 0 to h - 1 do
     read_scanline tif buf y;
-    set_scanline buf y;
+    (* safe: set_scanline copies it *)
+    set_scanline (Bytes.unsafe_to_string buf) y;
     match prog with
     | Some p -> p (float (y + 1) /. float h)
     | None -> ()
@@ -107,10 +108,11 @@ let check_header filename =
   let len = 4 in
   let ic = open_in_bin filename in
   try
-    let str = String.create len in
+    let str = Bytes.create len in
     really_input ic str 0 len;
-    Pervasives.close_in ic;
-    match str with
+    Stdlib.close_in ic;
+    (* safe: transient and private *)
+    match Bytes.unsafe_to_string str with
     | "MM\000\042" ->
       { header_width = -1;
   	header_height = -1;
@@ -122,7 +124,7 @@ let check_header filename =
     | _ -> raise Wrong_file_type
   with
   | _ ->
-      Pervasives.close_in ic;
+      Stdlib.close_in ic;
       raise Wrong_file_type;;
 
 add_methods Tiff
