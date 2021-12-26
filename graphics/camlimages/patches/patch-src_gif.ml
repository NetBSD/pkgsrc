$NetBSD: patch-src_gif.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Update for immutable strings.

--- src/gif.ml.orig	2011-06-22 18:04:32.000000000 +0000
+++ src/gif.ml
@@ -58,7 +58,7 @@ external dGifGetRecordType : in_channel 
     = "dGifGetRecordType";;
 external dGifGetImageDesc : in_channel -> gif_desc
     = "dGifGetImageDesc";;
-external dGifGetLine : in_channel -> string
+external dGifGetLine : in_channel -> Bytes.t
     = "dGifGetLine";;
 external dGifGetExtension : in_channel -> int * string list (* reversed!!! *)
     = "dGifGetExtension";;
@@ -200,7 +200,8 @@ let load filename opts =
            let rec loop src dest dest_step =
              if dest >= desc.desc_height then src else begin
                let line = dGifGetLine ic in
-               Index8.set_scanline img dest line;
+               (* safe: set_scanline copies it *)
+               Index8.set_scanline img dest (Bytes.unsafe_to_string line);
                incr lines;
                begin match prog with
                | Some p -> p (float !lines /. float desc.desc_height)
@@ -216,7 +217,8 @@ let load filename opts =
          let normal_reader () =
            for y = 0 to desc.desc_height - 1 do
              let line = dGifGetLine ic in
-             Index8.set_scanline img y line;
+             (* safe: set_scanline copies it *)
+             Index8.set_scanline img y (Bytes.unsafe_to_string line);
              begin match prog with
              | Some p -> p (float (y + 1) /. float desc.desc_height)
              | None -> ()
@@ -345,12 +347,12 @@ let save filename opts sequence =
     (* write loops *)
     let loop_written = ref false in
     if sequence.loops <> 0 then begin
-      let str = String.create 3 in
-      str.[0] <- '\001';
-      str.[1] <- char_of_int (sequence.loops mod 256);
-      str.[2] <- char_of_int (sequence.loops / 256);
+      let str = Bytes.create 3 in
+      Bytes.set str 0 '\001';
+      Bytes.set str 1 (char_of_int (sequence.loops mod 256));
+      Bytes.set str 2 (char_of_int (sequence.loops / 256));
       eGifPutExtension oc
-        (gif_make_extension (GifApplication ["NETSCAPE2.0"; str]));
+        (gif_make_extension (GifApplication ["NETSCAPE2.0"; Bytes.to_string str]));
       loop_written := true
     end;
 
@@ -382,18 +384,18 @@ let save filename opts sequence =
          frame.frame_bitmap.transparent <> -1 then begin
         let str =
           match !graphics_ext with
-          | Some str -> str
-          | None -> String.make 4 '\000' in
+          | Some str -> Bytes.of_string str
+          | None -> Bytes.make 4 '\000' in
         if frame.frame_bitmap.transparent <> -1 then begin
-          str.[0] <- char_of_int (int_of_char str.[0] lor 0x01);
-          str.[3] <- char_of_int frame.frame_bitmap.transparent
+          Bytes.set str 0 (char_of_int (int_of_char (Bytes.get str 0) lor 0x01));
+          Bytes.set str 3 (char_of_int frame.frame_bitmap.transparent)
         end else begin
-          str.[0] <- char_of_int (int_of_char str.[0] land 0xfe);
-          str.[3] <- '\000'
+          Bytes.set str 0 (char_of_int (int_of_char (Bytes.get str 0) land 0xfe));
+          Bytes.set str 3 '\000'
         end;
-        str.[1] <- char_of_int (frame.frame_delay mod 256);
-        str.[2] <- char_of_int (frame.frame_delay / 256);
-        eGifPutExtension oc (gif_make_extension (GifGraphics [str]))
+        Bytes.set str 1 (char_of_int (frame.frame_delay mod 256));
+        Bytes.set str 2 (char_of_int (frame.frame_delay / 256));
+        eGifPutExtension oc (gif_make_extension (GifGraphics [Bytes.to_string str]))
       end;
 
       let bmp = frame.frame_bitmap in
@@ -456,13 +458,13 @@ let check_header filename =
   let len = 10 in
   let ic = open_in_bin filename in
   try
-    let str = String.create len in
+    let str = Bytes.create len in
     really_input ic str 0 len;
     close_in ic;
-    match String.sub str 0 6 with
+    match Bytes.sub_string str 0 6 with
     | "GIF87a" | "GIF89a" -> {
-         header_width = int_of_char str.[6] + int_of_char str.[7] * 256;
-         header_height = int_of_char str.[8] + int_of_char str.[9] * 256;
+         header_width = int_of_char (Bytes.get str 6) + int_of_char (Bytes.get str 7) * 256;
+         header_height = int_of_char (Bytes.get str 8) + int_of_char (Bytes.get str 9) * 256;
          header_infos = [];
        }
     | _ -> raise Wrong_file_type
