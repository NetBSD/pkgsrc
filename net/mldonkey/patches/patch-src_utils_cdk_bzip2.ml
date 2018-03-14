$NetBSD: patch-src_utils_cdk_bzip2.ml,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/cdk/bzip2.ml~	2006-03-05 10:41:06.000000000 +0000
+++ src/utils/cdk/bzip2.ml
@@ -7,7 +7,7 @@ let buffer_size = 1024
 
 type in_channel =
   { in_chan: Pervasives.in_channel;
-    in_buffer: string;
+    in_buffer: bytes;
     mutable in_pos: int;
     mutable in_avail: int;
     mutable in_eof: bool;
@@ -16,7 +16,7 @@ type in_channel =
 
 let open_in_chan ic =
   { in_chan = ic;
-    in_buffer = String.create buffer_size;
+    in_buffer = Bytes.create buffer_size;
     in_pos = 0;
     in_avail = 0;
     in_eof = false;
@@ -32,12 +32,12 @@ let open_in filename =
 let read_byte iz =
   if iz.in_avail = 0 then begin
     let n = Pervasives.input iz.in_chan iz.in_buffer 0
-                             (String.length iz.in_buffer) in
+                             (Bytes.length iz.in_buffer) in
     if n = 0 then raise End_of_file;
     iz.in_pos <- 0;
     iz.in_avail <- n
   end;
-  let c = iz.in_buffer.[iz.in_pos] in
+  let c = Bytes.get iz.in_buffer iz.in_pos in
   iz.in_pos <- iz.in_pos + 1;
   iz.in_avail <- iz.in_avail - 1;
   Char.code c
@@ -53,19 +53,19 @@ let read_int32 iz =
                    (Int32.shift_left (Int32.of_int b4) 24)))
 
 let rec input iz buf pos len =
-  if pos < 0 || len < 0 || pos + len > String.length buf then
+  if pos < 0 || len < 0 || pos + len > Bytes.length buf then
     invalid_arg "Bzip2.input";
   if iz.in_eof then 0 else begin
     if iz.in_avail = 0 then begin
       let n = Pervasives.input iz.in_chan iz.in_buffer 0
-                               (String.length iz.in_buffer) in
+                               (Bytes.length iz.in_buffer) in
       if n = 0 then raise(Error("truncated file"));
       iz.in_pos <- 0;
       iz.in_avail <- n
     end;
     let (finished, used_in, used_out) =
       try
-        Bzlib.decompress iz.in_stream iz.in_buffer iz.in_pos iz.in_avail
+        Bzlib.decompress iz.in_stream (Bytes.to_string iz.in_buffer) iz.in_pos iz.in_avail
                                    buf pos len
       with Bzlib.Error(_, e) ->
         raise(Error(Bzlib.string_of_error e)) in
@@ -88,10 +88,10 @@ let rec really_input iz buf pos len =
     really_input iz buf (pos + n) (len - n)
   end
 
-let char_buffer = String.create 1
+let char_buffer = Bytes.create 1
 
 let input_char iz =
-  if input iz char_buffer 0 1 = 0 then raise End_of_file else char_buffer.[0]
+  if input iz char_buffer 0 1 = 0 then raise End_of_file else Bytes.get char_buffer 0
 
 let input_byte iz =
   Char.code (input_char iz)
@@ -106,7 +106,7 @@ let close_in iz =
 
 type out_channel =
   { out_chan: Pervasives.out_channel;
-    out_buffer: string;
+    out_buffer: bytes;
     mutable out_pos: int;
     mutable out_avail: int;
     out_stream: Bzlib.stream;
@@ -115,7 +115,7 @@ type out_channel =
 let open_out_chan ?(level = 6) oc =
   if level < 1 || level > 9 then invalid_arg "Bzip2.open_out: bad level";
   { out_chan = oc;
-    out_buffer = String.create buffer_size;
+    out_buffer = Bytes.create buffer_size;
     out_pos = 0;
     out_avail = buffer_size;
     out_stream = Bzlib.compress_init level 0 0;
@@ -132,7 +132,7 @@ let rec output oz buf pos len =
   (* Printf.printf "Flushing out_avail\n"; *)
     Pervasives.output oz.out_chan oz.out_buffer 0 oz.out_pos;
     oz.out_pos <- 0;
-    oz.out_avail <- String.length oz.out_buffer
+    oz.out_avail <- Bytes.length oz.out_buffer
   end;
   let (_, used_in, used_out) =
     try
@@ -147,8 +147,8 @@ let rec output oz buf pos len =
   if used_in < len then output oz buf (pos + used_in) (len - used_in)
 
 let output_char oz c =
-  char_buffer.[0] <- c;
-  output oz char_buffer 0 1
+  let s = String.make 1 c in
+  output oz s 0 1
 
 let output_byte oz b =
   output_char oz (Char.unsafe_chr b)
@@ -159,10 +159,10 @@ let flush oz =
     if oz.out_avail = 0 then begin
       Pervasives.output oz.out_chan oz.out_buffer 0 oz.out_pos;
       oz.out_pos <- 0;
-      oz.out_avail <- String.length oz.out_buffer
+      oz.out_avail <- Bytes.length oz.out_buffer
     end;
     let (finished, _, used_out) =
-      Bzlib.compress oz.out_stream oz.out_buffer 0 0
+      Bzlib.compress oz.out_stream (Bytes.to_string oz.out_buffer) 0 0
                                  oz.out_buffer oz.out_pos oz.out_avail
                                  Bzlib.BZ_FINISH in
     oz.out_pos <- oz.out_pos + used_out;
