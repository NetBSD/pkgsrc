$NetBSD: patch-src_utils_cdk_zip.ml,v 1.2 2018/03/14 14:05:37 dholland Exp $

Compile with OCaml 4.03 (the exception Error block)
and again with 4.06 (the rest)

--- src/utils/cdk/zip.ml.orig	2007-02-06 22:26:59.000000000 +0000
+++ src/utils/cdk/zip.ml
@@ -27,8 +27,8 @@ let read4_int ic =
   if hw > max_int lsr 16 then raise (Error("", "", "32-bit data too large"));
   lw lor (hw lsl 16)
 let readstring ic n =
-  let s = String.create n in
-  really_input ic s 0 n; s
+  let s = Bytes.create n in
+  really_input ic s 0 n; Bytes.to_string s
 
 let write1 = output_byte
 let write2 oc n =
@@ -40,7 +40,7 @@ let write4_int oc n =
   write2 oc n;
   write2 oc (n lsr 16)
 let writestring oc s =
-  output oc s 0 (String.length s)
+  output oc (Bytes.of_string s) 0 (String.length s)
 
 type compression_method = Stored | Deflated
 
@@ -72,8 +72,6 @@ type out_file =
     mutable of_entries: entry list;
     of_comment: string }
 
-exception Error of string * string * string
-
 (* Return the position of the last occurrence of s1 in s2, or -1 if not
    found. *)
 
@@ -81,7 +79,7 @@ let strrstr pattern buf ofs len =
   let rec search i j =
     if i < ofs then -1
     else if j >= String.length pattern then i
-    else if pattern.[j] = buf.[i + j] then search i (j+1)
+    else if pattern.[j] = Bytes.get buf (i + j) then search i (j+1)
     else search (i-1) 0
   in search (ofs + len - String.length pattern) 0
 
@@ -116,7 +114,7 @@ let dostime_of_unixtime t =
 (* Read end of central directory record *)
 
 let read_ecd filename ic =
-  let buf = String.create 256 in
+  let buf = Bytes.create 256 in
   let filelen = in_channel_length ic in
   let rec find_ecd pos len =
     (* On input, bytes 0 ... len - 1 of buf reflect what is at pos in ic *)
@@ -125,7 +123,7 @@ let read_ecd filename ic =
                    "end of central directory not found, not a ZIP file"));
     let toread = min pos 128 in
     (* Make room for "toread" extra bytes, and read them *)
-    String.blit buf 0 buf toread (256 - toread);
+    Bytes.blit buf 0 buf toread (256 - toread);
     let newpos = pos - toread in
     seek_in ic newpos;
     really_input ic buf 0 toread;
@@ -134,7 +132,7 @@ let read_ecd filename ic =
     let ofs = strrstr "PK\005\006" buf 0 newlen in
     if ofs < 0 || newlen < 22 || 
        (let comment_len = 
-          Char.code buf.[ofs + 20] lor (Char.code buf.[ofs + 21] lsl 8) in
+          Char.code (Bytes.get buf (ofs + 20)) lor (Char.code (Bytes.get buf (ofs + 21)) lsl 8) in
         newpos + ofs + 22 + comment_len <> filelen) then
       find_ecd newpos newlen
     else
@@ -268,14 +266,14 @@ let goto_entry ifile e =
 let read_entry ifile e =
   try
     goto_entry ifile e;
-    let res = String.create e.uncompressed_size in
+    let res = Bytes.create e.uncompressed_size in
     match e.methd with
       Stored ->
         if e.compressed_size <> e.uncompressed_size then
           raise (Error(ifile.if_filename, e.filename,
                        "wrong size for stored entry"));
         really_input ifile.if_channel res 0 e.uncompressed_size;
-        res
+        Bytes.to_string res
     | Deflated ->
         let in_avail = ref e.compressed_size in
         let out_pos = ref 0 in
@@ -283,25 +281,25 @@ let read_entry ifile e =
           Zlib.uncompress ~header:false
             (fun buf ->
               let read = input ifile.if_channel buf 0
-                               (min !in_avail (String.length buf)) in
+                               (min !in_avail (Bytes.length buf)) in
               in_avail := !in_avail - read;
               read)
             (fun buf len ->
-              if !out_pos + len > String.length res then
+              if !out_pos + len > Bytes.length res then
                 raise (Error(ifile.if_filename, e.filename,
                              "wrong size for deflated entry (too much data)"));
-              String.blit buf 0 res !out_pos len;
+              Bytes.blit buf 0 res !out_pos len;
               out_pos := !out_pos + len)
         with Zlib.Error(_, _) ->
           raise (Error(ifile.if_filename, e.filename, "decompression error"))
         end;
-        if !out_pos <> String.length res then
+        if !out_pos <> Bytes.length res then
           raise (Error(ifile.if_filename, e.filename,
                        "wrong size for deflated entry (not enough data)"));
-        let crc = Zlib.update_crc Int32.zero res 0 (String.length res) in
+        let crc = Zlib.update_crc Int32.zero (Bytes.to_string res) 0 (Bytes.length res) in
         if crc <> e.crc then
           raise (Error(ifile.if_filename, e.filename, "CRC mismatch"));
-        res
+        Bytes.to_string res
   with End_of_file ->
     raise (Error(ifile.if_filename, e.filename, "truncated data"))
     
@@ -315,10 +313,10 @@ let copy_entry_to_channel ifile e oc =
         if e.compressed_size <> e.uncompressed_size then
           raise (Error(ifile.if_filename, e.filename,
                        "wrong size for stored entry"));
-        let buf = String.create 4096 in
+        let buf = Bytes.create 4096 in
         let rec copy n =
           if n > 0 then begin
-            let r = input ifile.if_channel buf 0 (min n (String.length buf)) in
+            let r = input ifile.if_channel buf 0 (min n (Bytes.length buf)) in
             output oc buf 0 r;
             copy (n - r)
           end in
@@ -330,12 +328,12 @@ let copy_entry_to_channel ifile e oc =
           Zlib.uncompress ~header:false
             (fun buf ->
               let read = input ifile.if_channel buf 0
-                               (min !in_avail (String.length buf)) in
+                               (min !in_avail (Bytes.length buf)) in
               in_avail := !in_avail - read;
               read)
             (fun buf len ->
               output oc buf 0 len;
-              crc := Zlib.update_crc !crc buf 0 len)
+              crc := Zlib.update_crc !crc (Bytes.to_string buf) 0 len)
         with Zlib.Error(_, _) ->
           raise (Error(ifile.if_filename, e.filename, "decompression error"))
         end;
@@ -475,7 +473,7 @@ let add_entry data ofile ?(extra = "") ?
   let compr_size =
     match level with
       0 ->
-        output ofile.of_channel data 0 (String.length data);
+        output ofile.of_channel (Bytes.of_string data) 0 (String.length data);
         String.length data
     | _ ->
         let in_pos = ref 0 in
@@ -484,7 +482,7 @@ let add_entry data ofile ?(extra = "") ?
           Zlib.compress ~header:false
             (fun buf ->
                let n = min (String.length data - !in_pos)
-                           (String.length buf) in
+                           (Bytes.length buf) in
                String.blit data !in_pos buf 0 n;
                in_pos := !in_pos + n;
                n)
@@ -506,11 +504,11 @@ let copy_channel_to_entry ic ofile ?(ext
   let (compr_size, uncompr_size) =
     match level with
       0 ->
-        let buf = String.create 4096 in
+        let buf = Bytes.create 4096 in
         let rec copy sz =
-          let r = input ic buf 0 (String.length buf) in
+          let r = input ic buf 0 (Bytes.length buf) in
           if r = 0 then sz else begin
-            crc := Zlib.update_crc !crc buf 0 r;
+            crc := Zlib.update_crc !crc (Bytes.to_string buf) 0 r;
             output ofile.of_channel buf 0 r;
             copy (sz + r)
           end in
@@ -522,8 +520,8 @@ let copy_channel_to_entry ic ofile ?(ext
         try
           Zlib.compress ~header:false
             (fun buf ->
-               let r = input ic buf 0 (String.length buf) in
-               crc := Zlib.update_crc !crc buf 0 r;
+               let r = input ic buf 0 (Bytes.length buf) in
+               crc := Zlib.update_crc !crc (Bytes.to_string buf) 0 r;
                in_pos := !in_pos + r;
                r)
             (fun buf n ->            
