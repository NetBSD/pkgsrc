$NetBSD: patch-src_jpeg.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

Use "Stdlib" instead of "Pervasives".

--- src/jpeg.ml.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/jpeg.ml
@@ -17,7 +17,7 @@
 open Images;;
 open Rgb24;;
 
-external read : string -> int * int * string
+external read : string -> int * int * Bytes.t
     = "read_JPEG_file";;
 external write : string -> string -> int -> int -> int -> unit
     = "write_JPEG_file";;
@@ -30,9 +30,9 @@ external set_scale_denom : in_handle -> 
     = "jpeg_set_scale_denom";;
 external open_in_start : in_handle -> int * int * in_handle
     = "open_jpeg_file_for_read_start";;
-external read_scanline : in_handle -> string -> int -> unit
+external read_scanline : in_handle -> Bytes.t -> int -> unit
     = "read_jpeg_scanline";;
-external read_scanlines : in_handle -> string -> int -> int -> unit
+external read_scanlines : in_handle -> Bytes.t -> int -> int -> unit
     = "read_jpeg_scanlines";;
 external close_in : in_handle -> unit
     = "close_jpeg_file_for_read";;
@@ -95,10 +95,11 @@ let load_aux prog ic w h = 
       load_scanlines 0
   | None -> 
       (* CR jfuruse: check overflow *)
-      let scanline = String.create (w * 3) in
+      let scanline = Bytes.create (w * 3) in
       for y = 0 to h - 1 do
 	read_scanline ic scanline 0;
-	Rgb24.set_scanline img y scanline;
+        (* safe: set_scanline copies it *)
+	Rgb24.set_scanline img y (Bytes.unsafe_to_string scanline);
 	prog y
       done
   end;
@@ -141,16 +142,16 @@ let save_as_cmyk name opts trans image =
     | None -> 80 in
   let prog = Images.save_progress opts in
   let get_cmyk_scanline width scanline =
-    let buf = String.create (width * 4) in
+    let buf = Bytes.create (width * 4) in
     for x = 0 to width - 1 do
       let r = int_of_char scanline.[x * 3 + 0] in
       let g = int_of_char scanline.[x * 3 + 1] in
       let b = int_of_char scanline.[x * 3 + 2] in
       let c, m, y, k = trans {r = r; g = g; b = b} in
-      buf.[x * 4 + 0] <- char_of_int (255 - c);
-      buf.[x * 4 + 1] <- char_of_int (255 - m);
-      buf.[x * 4 + 2] <- char_of_int (255 - y);
-      buf.[x * 4 + 3] <- char_of_int (255 - k)
+      Bytes.set buf (x * 4 + 0) (char_of_int (255 - c));
+      Bytes.set buf (x * 4 + 1) (char_of_int (255 - m));
+      Bytes.set buf (x * 4 + 2) (char_of_int (255 - y));
+      Bytes.set buf (x * 4 + 3) (char_of_int (255 - k))
     done;
     buf in
   match image with
@@ -158,7 +159,8 @@ let save_as_cmyk name opts trans image =
       let oc = open_out_cmyk name bmp.width bmp.height quality in
       for y = 0 to bmp.height - 1 do
         let buf = get_cmyk_scanline bmp.width (Rgb24.get_scanline bmp y) in
-        write_scanline oc buf;
+        (* safe: write_scanline does not keep a reference *)
+        write_scanline oc (Bytes.unsafe_to_string buf);
         match prog with
         | Some p -> p (float (y + 1) /. float bmp.height)
         | None -> ()
@@ -179,19 +181,20 @@ let save_cmyk_sample name opts =
     and k = (y mod 16) * 17 in
     c, m, y, k in
   let sample_scan y =
-    let s = String.create (256 * 4) in
+    let s = Bytes.create (256 * 4) in
     for x = 0 to 255 do
       let c, m, y, k = sample_point x y in
-      s.[x * 4 + 0] <- char_of_int c;
-      s.[x * 4 + 1] <- char_of_int m;
-      s.[x * 4 + 2] <- char_of_int y;
-      s.[x * 4 + 3] <- char_of_int k;
+      Bytes.set s (x * 4 + 0) (char_of_int c);
+      Bytes.set s (x * 4 + 1) (char_of_int m);
+      Bytes.set s (x * 4 + 2) (char_of_int y);
+      Bytes.set s (x * 4 + 3) (char_of_int k);
     done;
     s in
   let oc = open_out_cmyk name 256 256 quality in
   for y = 0 to 256 - 1 do
     let buf = sample_scan y in
-    write_scanline oc buf
+    (* safe: write_scanline does not keep a reference *)
+    write_scanline oc (Bytes.unsafe_to_string buf)
   done;
   close_out oc;;
 
@@ -207,20 +210,20 @@ let rec find_jpeg_size ic =
       else ch in
     jump_to_0xff ();
     let ch = jump_to_non_0xff () in
-    let str = String.create 4 in
+    let str = Bytes.create 4 in
     match ch with
     | 0xda -> raise Not_found
     | _ when ch >= 0xc0 && ch <= 0xc3 ->
       really_input ic str 0 3;
       really_input ic str 0 4;
-      int_of_char str.[2] lsl 8 + int_of_char str.[3], (* width *)
-      int_of_char str.[0] lsl 8 + int_of_char str.[1]  (* height *)
+      int_of_char (Bytes.get str 2) lsl 8 + int_of_char (Bytes.get str 3), (* width *)
+      int_of_char (Bytes.get str 0) lsl 8 + int_of_char (Bytes.get str 1)  (* height *)
     | _ ->
       (* skip this block *)
       let blocklen =
         really_input ic str 0 2;
-        int_of_char str.[0] lsl 8 + int_of_char str.[1] in
-      let s = String.create (blocklen - 2) in
+        int_of_char (Bytes.get str 0) lsl 8 + int_of_char (Bytes.get str 1) in
+      let s = Bytes.create (blocklen - 2) in
       really_input ic s 0 (blocklen - 2);
       loop () in
   try loop () with
@@ -230,18 +233,18 @@ let check_header filename =
   let len = 2 in
   let ic = open_in_bin filename in
   try
-    let str = String.create len in
+    let str = Bytes.create len in
     really_input ic str 0 len;
     if
       (* some jpeg's start with 7f58, the 7th bit is missing *)
-      int_of_char str.[0] lor 0x80 = 0xff &&
-      int_of_char str.[1] lor 0x80 = 0xd8
-      (* int_of_char str.[0] = 0xff && int_of_char str.[1] = 0xd8 *)
-      (* && String.sub str 6 4 = "JFIF" --- strict *) then begin
+      int_of_char (Bytes.get str 0) lor 0x80 = 0xff &&
+      int_of_char (Bytes.get str 1) lor 0x80 = 0xd8
+      (* int_of_char (Bytes.get str 0) = 0xff && int_of_char (Bytes.get str 1) = 0xd8 *)
+      (* && Bytes.sub str 6 4 = "JFIF" --- strict *) then begin
       let w, h =
         try find_jpeg_size ic with
         | Not_found -> -1, -1 in
-      Pervasives.close_in ic;
+      Stdlib.close_in ic;
       { header_width = w;
         header_height = h;
         header_infos = []; }
@@ -249,7 +252,7 @@ let check_header filename =
       raise Wrong_file_type
   with
   | _ ->
-      Pervasives.close_in ic;
+      Stdlib.close_in ic;
       raise Wrong_file_type;;
 
 add_methods Jpeg
