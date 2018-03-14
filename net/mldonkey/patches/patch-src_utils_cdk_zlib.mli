$NetBSD: patch-src_utils_cdk_zlib.mli,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/cdk/zlib.ml~	2007-02-11 13:15:49.000000000 +0000
+++ src/utils/cdk/zlib.ml
@@ -13,14 +13,14 @@ type flush_command =
 
 external deflate_init: int -> bool -> stream = "camlzip_deflateInit"
 external deflate:
-  stream -> string -> int -> int -> string -> int -> int -> flush_command
+  stream -> bytes -> int -> int -> bytes -> int -> int -> flush_command
          -> bool * int * int
   = "camlzip_deflate_bytecode" "camlzip_deflate"
 external deflate_end: stream -> unit = "camlzip_deflateEnd"
 
 external inflate_init: bool -> stream = "camlzip_inflateInit"
 external inflate:
-  stream -> string -> int -> int -> string -> int -> int -> flush_command
+  stream -> bytes -> int -> int -> bytes -> int -> int -> flush_command
          -> bool * int * int
   = "camlzip_inflate_bytecode" "camlzip_inflate"
 external inflate_end: stream -> unit = "camlzip_inflateEnd"
@@ -40,8 +40,8 @@ let zlib_version_num () =
 let buffer_size = 1024
 
 let compress ?(level = 6) ?(header = true) refill flush =
-  let inbuf = String.create buffer_size
-  and outbuf = String.create buffer_size in
+  let inbuf = Bytes.create buffer_size
+  and outbuf = Bytes.create buffer_size in
   let zs = deflate_init level header in
   let rec compr inpos inavail =
     if inavail = 0 then begin
@@ -63,15 +63,15 @@ let compress ?(level = 6) ?(header = tru
     deflate_end zs
 
 let grow_buffer s =
-  let s' = String.create (2 * String.length s) in
-  String.blit s 0 s' 0 (String.length s);
+  let s' = Bytes.create (2 * Bytes.length s) in
+  Bytes.blit s 0 s' 0 (Bytes.length s);
   s'
 
 let compress_string ?(level = 6) inbuf =
   let zs = deflate_init level true in
   let rec compr inpos outbuf outpos =
-    let inavail = String.length inbuf - inpos in
-    let outavail = String.length outbuf - outpos in
+    let inavail = Bytes.length inbuf - inpos in
+    let outavail = Bytes.length outbuf - outpos in
     if outavail = 0
     then compr inpos (grow_buffer outbuf) outpos
     else begin
@@ -79,11 +79,11 @@ let compress_string ?(level = 6) inbuf =
         deflate zs inbuf inpos inavail outbuf outpos outavail
                    (if inavail = 0 then Z_FINISH else Z_NO_FLUSH) in
       if finished then 
-        String.sub outbuf 0 (outpos + used_out)
+        Bytes.sub outbuf 0 (outpos + used_out)
       else
         compr (inpos + used_in) outbuf (outpos + used_out)
     end in
-  let res = compr 0 (String.create (String.length inbuf)) 0 in
+  let res = compr 0 (Bytes.create (Bytes.length inbuf)) 0 in
   deflate_end zs;
   res
 
@@ -95,22 +95,22 @@ let gzip_string ?(level = 6) inbuf =
   let out_crc = ref Int32.zero in
   let rec compr inpos outbuf outpos =
     let inavail = String.length inbuf - inpos in
-    let outavail = String.length outbuf - outpos in
+    let outavail = Bytes.length outbuf - outpos in
     if outavail = 0
     then compr inpos (grow_buffer outbuf) outpos
     else begin 
       let (finished, used_in, used_out) =
-        deflate zs inbuf inpos inavail outbuf outpos outavail
+        deflate zs (Bytes.of_string inbuf) inpos inavail outbuf outpos outavail
                    (if inavail = 0 then Z_FINISH else Z_NO_FLUSH) in
          out_crc := update_crc !out_crc inbuf inpos used_in;
       if finished then 
-        String.sub outbuf 0 (outpos + used_out)
+        Bytes.sub outbuf 0 (outpos + used_out)
       else
         compr (inpos + used_in) outbuf (outpos + used_out)
     end in
-  let res = compr 0 (String.create (String.length inbuf)) 0 in
+  let res = compr 0 (Bytes.create (String.length inbuf)) 0 in
   deflate_end zs; 
-  let buf = Buffer.create (18 + String.length res) in
+  let buf = Buffer.create (18 + Bytes.length res) in
   let write_int wbuf n =
     Buffer.add_char wbuf (char_of_int n)
   in
@@ -128,15 +128,15 @@ let gzip_string ?(level = 6) inbuf =
   for i = 1 to 4 do write_int buf 0 done;
   write_int buf 0;
   write_int buf 0xFF;
-  Buffer.add_string buf res;
+  Buffer.add_bytes buf res;
   write_int32 buf !out_crc;
   write_int32 buf (Int32.of_int (String.length inbuf));
   Buffer.contents buf
   end
 
 let uncompress ?(header = true) refill flush =
-  let inbuf = String.create buffer_size
-  and outbuf = String.create buffer_size in
+  let inbuf = Bytes.create buffer_size
+  and outbuf = Bytes.create buffer_size in
   let zs = inflate_init header in
   let rec uncompr inpos inavail =
     if inavail = 0 then begin
@@ -164,19 +164,19 @@ let uncompress ?(header = true) refill f
 let uncompress_string2 inbuf =
   let zs = inflate_init true in
   let rec uncompr inpos outbuf outpos =
-    let inavail = String.length inbuf - inpos in
-    let outavail = String.length outbuf - outpos in
+    let inavail = Bytes.length inbuf - inpos in
+    let outavail = Bytes.length outbuf - outpos in
     if outavail = 0
     then uncompr inpos (grow_buffer outbuf) outpos
     else begin
       let (finished, used_in, used_out) =
         inflate zs inbuf inpos inavail outbuf outpos outavail Z_SYNC_FLUSH in
       if finished then 
-        String.sub outbuf 0 (outpos + used_out)
+        Bytes.sub outbuf 0 (outpos + used_out)
       else
         uncompr (inpos + used_in) outbuf (outpos + used_out)
     end in
-  let res = uncompr 0 (String.create (2 * String.length inbuf)) 0 in
+  let res = uncompr 0 (Bytes.create (2 * Bytes.length inbuf)) 0 in
   inflate_end zs;
   res
 
@@ -185,11 +185,11 @@ let uncompress_string s =
   let pos = ref 0 in
   let len = String.length s in
   uncompress ~header: true (fun b ->
-      let n = min (String.length b) (len - !pos) in
+      let n = min (Bytes.length b) (len - !pos) in
       if n < 1 then 0 else begin
       String.blit s !pos b 0 n;
       pos := !pos + n;
       n end
-  ) (fun s len -> Buffer.add_string buf (String.sub s 0 len));
+  ) (fun s len -> Buffer.add_bytes buf (Bytes.sub s 0 len));
   Buffer.contents buf
   
