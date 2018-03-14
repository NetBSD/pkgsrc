$NetBSD: patch-src_utils_cdk_gzip.ml,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/cdk/gzip.ml~	2010-11-07 15:01:40.000000000 +0000
+++ src/utils/cdk/gzip.ml
@@ -21,14 +21,14 @@ let buffer_size = 1024
 
 type in_channel =
   { in_chan: IO.input;
-    in_buffer: string;
+    in_buffer: bytes;
     mutable in_pos: int;
     mutable in_avail: int;
     mutable in_eof: bool;
     in_stream: Zlib.stream;
     mutable in_size: int32;
     mutable in_crc: int32;
-    char_buffer: string }
+    char_buffer: bytes }
 
 let open_in ic =
   (* Superficial parsing of header *)
@@ -66,14 +66,14 @@ let open_in ic =
     raise(Error("premature end of input, not a gzip stream"))
   end;
   { in_chan = ic;
-    in_buffer = String.create buffer_size;
+    in_buffer = Bytes.create buffer_size;
     in_pos = 0;
     in_avail = 0;
     in_eof = false;
     in_stream = Zlib.inflate_init false;
     in_size = Int32.zero;
     in_crc = Int32.zero;
-    char_buffer = String.create 1 }
+    char_buffer = Bytes.create 1 }
 
 let open_in_file filename =
   let ic = Pervasives.open_in_bin filename in
@@ -84,11 +84,11 @@ let open_in_file filename =
 let read_byte iz =
   if iz.in_avail = 0 then begin
     let n = IO.input iz.in_chan iz.in_buffer 0
-                             (String.length iz.in_buffer) in
+                             (Bytes.length iz.in_buffer) in
     iz.in_pos <- 0;
     iz.in_avail <- n
   end;
-  let c = iz.in_buffer.[iz.in_pos] in
+  let c = Bytes.get iz.in_buffer iz.in_pos in
   iz.in_pos <- iz.in_pos + 1;
   iz.in_avail <- iz.in_avail - 1;
   Char.code c
@@ -104,12 +104,12 @@ let read_int32 iz =
                    (Int32.shift_left (Int32.of_int b4) 24)))
 
 let rec input iz buf pos len =
-  if pos < 0 || len < 0 || pos + len > String.length buf then
+  if pos < 0 || len < 0 || pos + len > Bytes.length buf then
     invalid_arg "Gzip_stream.input";
   if iz.in_eof then 0 else begin
     if iz.in_avail = 0 then begin
       let n = try IO.input iz.in_chan iz.in_buffer 0
-                               (String.length iz.in_buffer) 
+                               (Bytes.length iz.in_buffer) 
               with IO.No_more_input -> raise(Error("truncated stream"))
       in
       iz.in_pos <- 0;
@@ -123,7 +123,7 @@ let rec input iz buf pos len =
         raise(Error("error during decompression")) in
     iz.in_pos <- iz.in_pos + used_in;
     iz.in_avail <- iz.in_avail - used_in;
-    iz.in_crc <- Zlib.update_crc iz.in_crc buf pos used_out;
+    iz.in_crc <- Zlib.update_crc iz.in_crc (Bytes.to_string buf) pos used_out;
     iz.in_size <- Int32.add iz.in_size (Int32.of_int used_out);
     if finished then begin
       try
@@ -152,7 +152,7 @@ let rec really_input iz buf pos len =
   end
 
 let input_char iz =
-  if input iz iz.char_buffer 0 1 = 0 then raise End_of_file else iz.char_buffer.[0]
+  if input iz iz.char_buffer 0 1 = 0 then raise End_of_file else Bytes.get iz.char_buffer 0
 
 let input_byte iz =
   Char.code (input_char iz)
@@ -167,13 +167,13 @@ let close_in iz =
 
 type 'a out_channel =
   { out_chan: 'a IO.output;
-    out_buffer: string;
+    out_buffer: bytes;
     mutable out_pos: int;
     mutable out_avail: int;
     out_stream: Zlib.stream;
     mutable out_size: int32;
     mutable out_crc: int32;
-    char_buffer: string }
+    char_buffer: bytes }
 
 let open_out ?(level = 6) oc =
   if level < 1 || level > 9 then invalid_arg "Gzip_stream.open_output: bad level";
@@ -186,13 +186,13 @@ let open_out ?(level = 6) oc =
   IO.write_byte oc 0;                     (* xflags *)
   IO.write_byte oc 0xFF;                  (* OS (unknown) *)
   { out_chan = oc;
-    out_buffer = String.create buffer_size;
+    out_buffer = Bytes.create buffer_size;
     out_pos = 0;
     out_avail = buffer_size;
     out_stream = Zlib.deflate_init level false;
     out_size = Int32.zero;
     out_crc = Int32.zero;
-    char_buffer = String.create 1 }
+    char_buffer = Bytes.create 1 }
 
 let open_out_file ?level filename =
   let oc = Pervasives.open_out_bin filename in
@@ -202,13 +202,13 @@ let open_out_file ?level filename =
     exn -> Pervasives.close_out oc; raise exn
 
 let rec output oz buf pos len =
-  if pos < 0 || len < 0 || pos + len > String.length buf then
+  if pos < 0 || len < 0 || pos + len > Bytes.length buf then
     invalid_arg "Gzip_stream.output";
   (* If output buffer is full, flush it *)
   if oz.out_avail = 0 then begin
-    ignore (IO.really_output oz.out_chan oz.out_buffer 0 oz.out_pos);
+    ignore (IO.really_output oz.out_chan (Bytes.to_string oz.out_buffer) 0 oz.out_pos);
     oz.out_pos <- 0;
-    oz.out_avail <- String.length oz.out_buffer
+    oz.out_avail <- Bytes.length oz.out_buffer
   end;
   let (_, used_in, used_out) =
     try
@@ -220,11 +220,11 @@ let rec output oz buf pos len =
   oz.out_pos <- oz.out_pos + used_out;
   oz.out_avail <- oz.out_avail - used_out;
   oz.out_size <- Int32.add oz.out_size (Int32.of_int used_in);
-  oz.out_crc <- Zlib.update_crc oz.out_crc buf pos used_in;
+  oz.out_crc <- Zlib.update_crc oz.out_crc (Bytes.to_string buf) pos used_in;
   if used_in < len then output oz buf (pos + used_in) (len - used_in)
 
 let output_char oz c =
-  oz.char_buffer.[0] <- c;
+  Bytes.set oz.char_buffer 0 c;
   output oz oz.char_buffer 0 1
 
 let output_byte oz b =
@@ -241,9 +241,9 @@ let flush oz =
   let rec do_flush () =
     (* If output buffer is full, flush it *)
     if oz.out_avail = 0 then begin
-      ignore (IO.really_output oz.out_chan oz.out_buffer 0 oz.out_pos);
+      ignore (IO.really_output oz.out_chan (Bytes.to_string oz.out_buffer) 0 oz.out_pos);
       oz.out_pos <- 0;
-      oz.out_avail <- String.length oz.out_buffer
+      oz.out_avail <- Bytes.length oz.out_buffer
     end;
     let (finished, _, used_out) =
       Zlib.deflate oz.out_stream oz.out_buffer 0 0
@@ -255,7 +255,7 @@ let flush oz =
   do_flush();
   (* Final data flush *)
   if oz.out_pos > 0 then
-    ignore (IO.really_output oz.out_chan oz.out_buffer 0 oz.out_pos);
+    ignore (IO.really_output oz.out_chan (Bytes.to_string oz.out_buffer) 0 oz.out_pos);
   (* Write CRC and size *)
   write_int32 oz.out_chan oz.out_crc;
   write_int32 oz.out_chan oz.out_size;
@@ -277,7 +277,7 @@ let output_io io =
   let oz = open_out io in
   IO.create_out
     ~write:(output_char oz)
-    ~output:(fun s o l -> output oz s o l; l)
+    ~output:(fun s o l -> output oz (Bytes.of_string s) o l; l)
     ~flush:(fun () -> IO.flush io)
     ~close:(fun () -> close_out oz)
 
