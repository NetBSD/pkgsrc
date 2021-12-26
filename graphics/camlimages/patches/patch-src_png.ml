$NetBSD: patch-src_png.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/png.ml.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/png.ml
@@ -53,16 +53,19 @@ let load name _opts =
   | PNG_INDEX16 (buf,cmap) ->
       Index16 (Index16.create_with_scanlines w h [] { max = 65535; map = cmap } (-1) buf)
   | PNG_INDEX4 (buf,cmap) ->
-      let buf' = Array.init h (fun _ -> String.create w) in
+      let buf' = Array.init h (fun _ -> Bytes.create w) in
       for y = 0 to h - 1 do
         for x = 0 to w - 1 do
-          buf'.(y).[x] <-
+          Bytes.set (buf'.(y)) x (
             char_of_int
               (let c = int_of_char buf.(y).[x / 2] in
                if x mod 2 = 0 then c lsr 4 else c mod 16)
+	    )
         done
       done;
-      Index8 (Index8.create_with_scanlines w h [] { max = 16; map = cmap } (-1) buf')
+      (* safe: create_with_scanlines copies the strings *)
+      let buf'' = Array.init h (fun n -> Bytes.unsafe_to_string buf'.(n)) in
+      Index8 (Index8.create_with_scanlines w h [] { max = 16; map = cmap } (-1) buf'')
 ;;
 
 let save name _opts image =
@@ -87,27 +90,27 @@ let check_header filename =
   let len = 24 in
   let ic = open_in_bin filename in
   try
-    let str = String.create len in
+    let str = Bytes.create len in
     really_input ic str 0 len;
     close_in ic;
-    if String.sub str 1 3 = "PNG" then begin
-      if String.sub str 0 8 <> "\137PNG\013\010\026\010" then begin
+    if Bytes.sub_string str 1 3 = "PNG" then begin
+      if Bytes.sub_string str 0 8 <> "\137PNG\013\010\026\010" then begin
           { header_width= -1;
             header_height= -1;
             header_infos= [Info_Corrupted]; }
       end else begin
           let belong str =
-            int_of_char str.[0] lsl 24 +
-            int_of_char str.[1] lsl 16 +
-            int_of_char str.[2] lsl 8 +
-            int_of_char str.[3] in
-          let w = belong (String.sub str 16 4) in
-          let h = belong (String.sub str 20 4) in
-          let bdepth = Info_Depth (int_of_char str.[12]) in
+            int_of_char (Bytes.get str 0) lsl 24 +
+            int_of_char (Bytes.get str 1) lsl 16 +
+            int_of_char (Bytes.get str 2) lsl 8 +
+            int_of_char (Bytes.get str 3) in
+          let w = belong (Bytes.sub str 16 4) in
+          let h = belong (Bytes.sub str 20 4) in
+          let bdepth = Info_Depth (int_of_char (Bytes.get str 12)) in
           let infos =
             try
               let colormodel =
-                match int_of_char str.[13] with
+                match int_of_char (Bytes.get str 13) with
                 | 0 -> Info_ColorModel Gray
                 | 2 -> Info_ColorModel RGB
                 | 3 -> Info_ColorModel Index
