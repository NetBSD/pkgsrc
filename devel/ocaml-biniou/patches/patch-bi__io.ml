$NetBSD: patch-bi__io.ml,v 1.1 2018/03/11 02:30:34 dholland Exp $

Fix up mutable strings to make it build with ocaml 4.06.

--- bi_io.ml~	2017-05-04 17:38:05.000000000 +0000
+++ bi_io.ml
@@ -89,13 +89,13 @@ let write_hashtag ob h has_arg =
   let h = mask_31bit h in
   let pos = Bi_outbuf.alloc ob 4 in
   let s = ob.o_s in
-  String.unsafe_set s (pos+3) (Char.chr (h land 0xff));
+  Bytes.unsafe_set s (pos+3) (Char.chr (h land 0xff));
   let h = h lsr 8 in
-  String.unsafe_set s (pos+2) (Char.chr (h land 0xff));
+  Bytes.unsafe_set s (pos+2) (Char.chr (h land 0xff));
   let h = h lsr 8 in
-  String.unsafe_set s (pos+1) (Char.chr (h land 0xff));
+  Bytes.unsafe_set s (pos+1) (Char.chr (h land 0xff));
   let h = h lsr 8 in
-  String.unsafe_set s pos (
+  Bytes.unsafe_set s pos (
     Char.chr (
       if has_arg then h lor 0x80
       else h
@@ -110,12 +110,12 @@ let string_of_hashtag h has_arg =
 let read_hashtag ib cont =
   let i = Bi_inbuf.read ib 4 in
   let s = ib.i_s in
-  let x0 = Char.code s.[i] in
+  let x0 = Char.code (Bytes.get s i) in
   let has_arg = x0 >= 0x80 in
   let x1 = (x0 land 0x7f) lsl 24 in
-  let x2 = (Char.code s.[i+1]) lsl 16 in
-  let x3 = (Char.code s.[i+2]) lsl 8 in
-  let x4 = Char.code s.[i+3] in
+  let x2 = (Char.code (Bytes.get s (i+1))) lsl 16 in
+  let x3 = (Char.code (Bytes.get s (i+2))) lsl 8 in
+  let x4 = Char.code (Bytes.get s (i+3)) in
   let h = make_signed (x1 lor x2 lor x3 lor x4) in
 
   cont ib h has_arg
@@ -124,13 +124,13 @@ let read_hashtag ib cont =
 let read_field_hashtag ib =
   let i = Bi_inbuf.read ib 4 in
   let s = ib.i_s in
-  let x0 = Char.code (String.unsafe_get s i) in
+  let x0 = Char.code (Bytes.unsafe_get s i) in
   if x0 < 0x80 then
     Bi_util.error "Corrupted data (invalid field hashtag)";
   let x1 = (x0 land 0x7f) lsl 24 in
-  let x2 = (Char.code (String.unsafe_get s (i+1))) lsl 16 in
-  let x3 = (Char.code (String.unsafe_get s (i+2))) lsl 8 in
-  let x4 = Char.code (String.unsafe_get s (i+3)) in
+  let x2 = (Char.code (Bytes.unsafe_get s (i+1))) lsl 16 in
+  let x3 = (Char.code (Bytes.unsafe_get s (i+2))) lsl 8 in
+  let x4 = Char.code (Bytes.unsafe_get s (i+3)) in
   make_signed (x1 lor x2 lor x3 lor x4)
 
 
@@ -147,7 +147,7 @@ let write_numtag ob i has_arg =
 
 let read_numtag ib cont =
   let i = Bi_inbuf.read ib 1 in
-  let x = Char.code ib.i_s.[i] in
+  let x = Char.code (Bytes.get ib.i_s i) in
   let has_arg = x >= 0x80 in
   cont ib (x land 0x7f) has_arg
 
@@ -219,11 +219,11 @@ let read_untagged_float64 ib =
   (match Lazy.force float_endianness with
        `Little ->
 	 for j = 0 to 7 do
-	   String.unsafe_set (Obj.obj x) (7-j) (String.unsafe_get s (i+j))
+	   Bytes.unsafe_set (Obj.obj x) (7-j) (Bytes.unsafe_get s (i+j))
 	 done
      | `Big ->
 	 for j = 0 to 7 do
-	   String.unsafe_set (Obj.obj x) j (String.unsafe_get s (i+j))
+	   Bytes.unsafe_set (Obj.obj x) j (Bytes.unsafe_get s (i+j))
 	 done
   );
   (Obj.obj x : float)
@@ -234,11 +234,11 @@ let write_untagged_float64 ob x =
   (match Lazy.force float_endianness with
        `Little ->
 	 for j = 0 to 7 do
-	   String.unsafe_set s (i+j) (String.unsafe_get (Obj.magic x) (7-j))
+	   Bytes.unsafe_set s (i+j) (Bytes.unsafe_get (Obj.magic x) (7-j))
 	 done
      | `Big ->
 	 for j = 0 to 7 do
-	   String.unsafe_set s (i+j) (String.unsafe_get (Obj.magic x) j)
+	   Bytes.unsafe_set s (i+j) (Bytes.unsafe_get (Obj.magic x) j)
 	 done
   )
 
@@ -526,16 +526,16 @@ let read_untagged_int8 ib =
 let read_untagged_int16 ib =
   let i = Bi_inbuf.read ib 2 in
   let s = ib.i_s in
-  ((Char.code s.[i]) lsl 8) lor (Char.code s.[i+1])
+  ((Char.code (Bytes.get s i)) lsl 8) lor (Char.code (Bytes.get s (i+1)))
 
 
 let read_untagged_int32 ib =
   let i = Bi_inbuf.read ib 4 in
   let s = ib.i_s in
   let x1 =
-    Int32.of_int (((Char.code s.[i  ]) lsl 8) lor (Char.code s.[i+1])) in
+    Int32.of_int (((Char.code (Bytes.get s (i  ))) lsl 8) lor (Char.code (Bytes.get s (i+1)))) in
   let x2 =
-    Int32.of_int (((Char.code s.[i+2]) lsl 8) lor (Char.code s.[i+3])) in
+    Int32.of_int (((Char.code (Bytes.get s (i+2))) lsl 8) lor (Char.code (Bytes.get s (i+3)))) in
   Int32.logor (Int32.shift_left x1 16) x2
 
 let read_untagged_float32 ib =
@@ -565,7 +565,7 @@ let read_untagged_int64 ib =
 
 let read_untagged_string ib =
   let len = Bi_vint.read_uvint ib in
-  let str = String.create len in
+  let str = Bytes.create len in
   let pos = ref 0 in
   let rem = ref len in
   while !rem > 0 do
@@ -573,13 +573,13 @@ let read_untagged_string ib =
     if bytes_read = 0 then
       Bi_util.error "Corrupted data (string)"
     else (
-      String.blit ib.i_s ib.i_pos str !pos bytes_read;
+      Bytes.blit ib.i_s ib.i_pos str !pos bytes_read;
       ib.i_pos <- ib.i_pos + bytes_read;
       pos := !pos + bytes_read;
       rem := !rem - bytes_read
     )
   done;
-  str
+  Bytes.to_string str
 
 let read_untagged_uvint = Bi_vint.read_uvint
 let read_untagged_svint = Bi_vint.read_svint
