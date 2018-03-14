$NetBSD: patch-src_utils_lib_unix32.ml,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/lib/unix32.ml~	2011-03-13 17:45:32.000000000 +0000
+++ src/utils/lib/unix32.ml
@@ -318,7 +318,7 @@ module FDCache = struct
         file_pos
         len
         string_pos
-        (String.length string)
+        (Bytes.length string)
         (Printexc2.to_string e);
       raise e
 
@@ -327,7 +327,7 @@ module FDCache = struct
       check_destroyed t2;
       let buffer_len = 128 * 1024 in
       let buffer_len64 = Int64.of_int buffer_len in
-      let buffer = String.make buffer_len '\001' in
+      let buffer = Bytes.make buffer_len '\001' in
       let rec iter remaining pos1 pos2 =
         let len64 = min remaining buffer_len64 in
         let len = Int64.to_int len64 in
@@ -363,8 +363,8 @@ module type File =   sig
     val mtime64 : t -> float
     val exists : t -> bool
     val remove : t -> unit
-    val read : t -> int64 -> string -> int -> int -> unit
-    val write : t -> int64 -> string -> int -> int -> unit
+    val read : t -> int64 -> bytes -> int -> int -> unit
+    val write : t -> int64 -> bytes -> int -> int -> unit
     val destroy : t -> unit
     val is_closed : t -> bool
   end
@@ -648,7 +648,7 @@ module MultiFile = struct
       let possible_len = Int64.to_int possible_len64 in
       if possible_len64 > zero then
         FDCache.read file.fd in_file_pos s in_string_pos possible_len;
-      String.fill s (in_string_pos + possible_len) (len - possible_len) '\000'
+      Bytes.fill s (in_string_pos + possible_len) (len - possible_len) '\000'
 
     let io f t chunk_begin string string_pos len =
       let (file, tail) = find_file t chunk_begin in
@@ -1039,7 +1039,7 @@ module SparseFile = struct
           len = zero;
           fd = fd;
         } in
-        let new_array = Array.create (nchunks+1) chunk in
+        let new_array = Array.make (nchunks+1) chunk in
         Array.blit t.chunks 0 new_array 0 nchunks;
         t.chunks <- new_array
 
@@ -1055,7 +1055,7 @@ module SparseFile = struct
             len = zero;
             fd = fd;
           } in
-          let new_array = Array.create (nchunks+1) chunk in
+          let new_array = Array.make (nchunks+1) chunk in
           Array.blit t.chunks 0 new_array 0 index;
           Array.blit t.chunks index new_array (index+1) (nchunks-index);
           t.chunks <- new_array;
@@ -1226,7 +1226,7 @@ let flush_buffer t offset =
   let len = String.length s in
   try
     if !verbose then lprintf_nl "seek64 %Ld" offset;
-    if len > 0 then write t offset s 0 len;
+    if len > 0 then write t offset (Bytes.of_string s) 0 len;
 (*
     let fd, offset =  fd_of_chunk t offset (Int64.of_int len) in
     let final_pos = Unix2.c_seek64 fd offset Unix.SEEK_SET in
@@ -1349,7 +1349,7 @@ let copy_chunk t1 t2 pos1 pos2 len =
   flush_fd t1;
   flush_fd t2;
   let buffer_size = 128 * 1024 in
-  let buffer = String.make buffer_size '\001' in
+  let buffer = Bytes.make buffer_size '\001' in
   let rec iter remaining pos1 pos2 =
     let len = mini remaining buffer_size in
     if len > 0 then begin
