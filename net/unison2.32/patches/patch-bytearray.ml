$NetBSD: patch-bytearray.ml,v 1.1 2018/03/14 10:16:03 dholland Exp $

Fix build with ocaml 4.06.

--- bytearray.ml~	2009-05-29 14:00:18.000000000 +0000
+++ bytearray.ml
@@ -36,17 +36,20 @@ let unsafe_blit_to_string a i s j l =
 *)
 
 external unsafe_blit_from_string : string -> int -> t -> int -> int -> unit
-  = "ml_blit_string_to_bigarray" "noalloc"
+  = "ml_blit_string_to_bigarray" [@@noalloc]
 
-external unsafe_blit_to_string : t -> int -> string -> int -> int -> unit
-  = "ml_blit_bigarray_to_string" "noalloc"
+external unsafe_blit_from_bytes : bytes -> int -> t -> int -> int -> unit
+  = "ml_blit_bytes_to_bigarray" [@@noalloc]
+
+external unsafe_blit_to_bytes : t -> int -> bytes -> int -> int -> unit
+  = "ml_blit_bigarray_to_bytes" [@@noalloc]
 
 let to_string a =
   let l = length a in
   if l > Sys.max_string_length then invalid_arg "Bytearray.to_string" else
-  let s = String.create l in
-  unsafe_blit_to_string a 0 s 0 l;
-  s
+  let s = Bytes.create l in
+  unsafe_blit_to_bytes a 0 s 0 l;
+  Bytes.to_string s
 
 let of_string s =
   let l = String.length s in
@@ -60,9 +63,9 @@ let sub a ofs len =
   then
     invalid_arg "Bytearray.sub"
   else begin
-    let s = String.create len in
-    unsafe_blit_to_string a ofs s 0 len;
-    s
+    let s = Bytes.create len in
+    unsafe_blit_to_bytes a ofs s 0 len;
+    Bytes.to_string s
   end
 
 let rec prefix_rec a i a' i' l =
@@ -81,11 +84,17 @@ let blit_from_string s i a j l =
   then invalid_arg "Bytearray.blit_from_string"
   else unsafe_blit_from_string s i a j l
 
-let blit_to_string a i s j l =
+let blit_from_bytes s i a j l =
+  if l < 0 || i < 0 || i > Bytes.length s - l
+           || j < 0 || j > length a - l
+  then invalid_arg "Bytearray.blit_from_bytes"
+  else unsafe_blit_from_bytes s i a j l
+
+let blit_to_bytes a i s j l =
   if l < 0 || i < 0 || i > length a - l
-           || j < 0 || j > String.length s - l
-  then invalid_arg "Bytearray.blit_to_string"
-  else unsafe_blit_to_string a i s j l
+           || j < 0 || j > Bytes.length s - l
+  then invalid_arg "Bytearray.blit_to_bytes"
+  else unsafe_blit_to_bytes a i s j l
 
 external marshal : 'a -> Marshal.extern_flags list -> t
   = "ml_marshal_to_bigarray"
