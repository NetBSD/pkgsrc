$NetBSD: patch-unicode.ml,v 1.1 2018/03/14 11:16:15 dholland Exp $

Fix build with ocaml 4.06.

--- unicode.ml~	2010-05-20 09:08:30.000000000 +0000
+++ unicode.ml
@@ -21,8 +21,9 @@ exception Invalid
 
 let fail () = raise Invalid
 
-let get s i = Char.code (String.unsafe_get s i)
-let set s i v = String.unsafe_set s i (Char.unsafe_chr v)
+let get' s i = Char.code (String.unsafe_get s i)
+let get s i = Char.code (Bytes.unsafe_get s i)
+let set s i v = Bytes.unsafe_set s i (Char.unsafe_chr v)
 
 (****)
 
@@ -773,9 +774,9 @@ let combining_property_bitmap = "\
 
 let combining_class c =
   if c > 0xffff then 0 else
-  let v = get combining_property_bitmap (c lsr 8) in
+  let v = get' combining_property_bitmap (c lsr 8) in
   if v = 0 then 0 else
-  get combining_property_bitmap (v lsl 8 + c land 0xff)
+  get' combining_property_bitmap (v lsl 8 + c land 0xff)
 
 let rec find_loc s i l p =
   if i = 0 then i else
@@ -818,14 +819,14 @@ and cont s i l j p v =
     (* move char to the right location *)
     let k = find_loc s i l p' in
     let d = j - i in
-    let s' = String.sub s i d in
-    String.blit s k s (k + d) (i - k);
-    String.blit s' 0 s k d;
+    let s' = Bytes.sub s i d in
+    Bytes.blit s k s (k + d) (i - k);
+    Bytes.blit s' 0 s k d;
     scan s j l p
   end
 
 let order s =
-  scan s 0 (String.length s) 0
+  scan s 0 (Bytes.length s) 0
 
 (****)
 
@@ -845,42 +846,42 @@ let set_char_3 s i c =
   set s (i + 1) ((c lsr 6) land 0x3f + 0x80);
   set s (i + 2) (c land 0x3f + 0x80)
 
-let rec norm s i l s' j =
+let rec norm (s: string) i l s' j =
   if i < l then begin
-    let c = get s i in
+    let c = get' s i in
     if c < 0x80 then begin
-      set s' j (get norm_ascii c);
+      set s' j (get' norm_ascii c);
       norm s (i + 1) l s' (j + 1)
     end else if c < 0xE0 then begin
       (* 80 - 7FF *)
       if c < 0xc2 || i + 1 >= l then raise Invalid;
-      let c1 = get s (i + 1) in
+      let c1 = get' s (i + 1) in
       if c1 land 0xc0 <> 0x80 then raise Invalid;
-      let idx = get norm_prim (c - 0xc0) in
+      let idx = get' norm_prim (c - 0xc0) in
       let idx = idx lsl 6 + c1 - 0x80 in
-      let k = get norm_second_high idx in
+      let k = get' norm_second_high idx in
       if k = 0 then begin
         set s' j c;
         set s' (j + 1) c1;
         norm s (i + 2) l s' (j + 2)
       end else begin
-        let k = (k - 2) lsl 8 + get norm_second_low idx in
-        let n = get norm_repl k in
+        let k = (k - 2) lsl 8 + get' norm_second_low idx in
+        let n = get' norm_repl k in
         String.blit norm_repl (k + 1) s' j n;
         norm s (i + 2) l s' (j + n)
       end
     end else if c < 0xF0 then begin
       (* 800 - FFFF *)
       if i + 2 >= l then raise Invalid;
-      let c1 = get s (i + 1) in
+      let c1 = get' s (i + 1) in
       if c1 land 0xc0 <> 0x80 then raise Invalid;
       let idx = c lsl 6 + c1 - 0x3880 in
       if idx < 0x20 then raise Invalid;
-      let c2 = get s (i + 2) in
+      let c2 = get' s (i + 2) in
       if c2 land 0xc0 <> 0x80 then raise Invalid;
-      let idx = get norm_prim idx in
+      let idx = get' norm_prim idx in
       let idx = idx lsl 6 + c2 - 0x80 in
-      let k = get norm_second_high idx in
+      let k = get' norm_second_high idx in
       if k = 0 then begin
         set s' j c;
         set s' (j + 1) c1;
@@ -905,17 +906,17 @@ let rec norm s i l s' j =
           end
         end
       end else begin
-        let k = (k - 2) lsl 8 + get norm_second_low idx in
-        let n = get norm_repl k in
+        let k = (k - 2) lsl 8 + get' norm_second_low idx in
+        let n = get' norm_repl k in
         String.blit norm_repl (k + 1) s' j n;
         norm s (i + 3) l s' (j + n)
       end
     end else begin
       (* 10000 - 10FFFF *)
       if i + 3 >= l then raise Invalid;
-      let c1 = get s (i + 1) in
-      let c2 = get s (i + 2) in
-      let c3 = get s (i + 3) in
+      let c1 = get' s (i + 1) in
+      let c2 = get' s (i + 2) in
+      let c3 = get' s (i + 3) in
       if (c1 lor c2 lor c3) land 0xc0 <> 0x80 then raise Invalid;
       let v = c lsl 18 + c1 lsl 12 + c2 lsl 6 + c3 - 0x03c82080 in
       if v < 0x10000 || v > 0x10ffff then raise Invalid;
@@ -926,58 +927,58 @@ let rec norm s i l s' j =
       norm s (i + 4) l s' (j + 4)
     end
   end else
-    String.sub s' 0 j
+    Bytes.sub s' 0 j
 
 let normalize s =
   let l = String.length s in
-  let s' = String.create (3 * l) in
+  let s' = Bytes.create (3 * l) in
   try
-    let s' = norm s 0 l s' 0 in order s'; s'
+    let s' = norm s 0 l s' 0 in order s'; Bytes.to_string s'
   with Invalid ->
     (* We need a comparison function which is coherent (transitive)
        also with non-unicode strings.  The optimization below assumes
        a case-insensitive comparison on ASCII characters, thus we
        translate the string to lowercase *)
-    String.lowercase s
+    String.lowercase_ascii s
 
 (****)
 
-let rec decomp s i l s' j =
+let rec decomp (s: string) i l s' j =
   if i < l then begin
-    let c = get s i in
+    let c = get' s i in
     if c < 0x80 then begin
-      set s' j (get decomp_ascii c);
+      set s' j (get' decomp_ascii c);
       decomp s (i + 1) l s' (j + 1)
     end else if c < 0xE0 then begin
       (* 80 - 7FF *)
       if c < 0xc2 || i + 1 >= l then raise Invalid;
-      let c1 = get s (i + 1) in
+      let c1 = get' s (i + 1) in
       if c1 land 0xc0 <> 0x80 then raise Invalid;
-      let idx = get decomp_prim (c - 0xc0) in
+      let idx = get' decomp_prim (c - 0xc0) in
       let idx = idx lsl 6 + c1 - 0x80 in
-      let k = get decomp_second_high idx in
+      let k = get' decomp_second_high idx in
       if k = 0 then begin
         set s' j c;
         set s' (j + 1) c1;
         decomp s (i + 2) l s' (j + 2)
       end else begin
-        let k = (k - 2) lsl 8 + get decomp_second_low idx in
-        let n = get decomp_repl k in
+        let k = (k - 2) lsl 8 + get' decomp_second_low idx in
+        let n = get' decomp_repl k in
         String.blit decomp_repl (k + 1) s' j n;
         decomp s (i + 2) l s' (j + n)
       end
     end else if c < 0xF0 then begin
       (* 800 - FFFF *)
       if i + 2 >= l then raise Invalid;
-      let c1 = get s (i + 1) in
+      let c1 = get' s (i + 1) in
       if c1 land 0xc0 <> 0x80 then raise Invalid;
       let idx = c lsl 6 + c1 - 0x3880 in
       if idx < 0x20 then raise Invalid;
-      let c2 = get s (i + 2) in
+      let c2 = get' s (i + 2) in
       if c2 land 0xc0 <> 0x80 then raise Invalid;
-      let idx = get decomp_prim idx in
+      let idx = get' decomp_prim idx in
       let idx = idx lsl 6 + c2 - 0x80 in
-      let k = get decomp_second_high idx in
+      let k = get' decomp_second_high idx in
       if k = 0 then begin
         set s' j c;
         set s' (j + 1) c1;
@@ -1002,17 +1003,17 @@ let rec decomp s i l s' j =
           end
         end
       end else begin
-        let k = (k - 2) lsl 8 + get decomp_second_low idx in
-        let n = get decomp_repl k in
+        let k = (k - 2) lsl 8 + get' decomp_second_low idx in
+        let n = get' decomp_repl k in
         String.blit decomp_repl (k + 1) s' j n;
         decomp s (i + 3) l s' (j + n)
       end
     end else begin
       (* 10000 - 10FFFF *)
       if i + 3 >= l then raise Invalid;
-      let c1 = get s (i + 1) in
-      let c2 = get s (i + 2) in
-      let c3 = get s (i + 3) in
+      let c1 = get' s (i + 1) in
+      let c2 = get' s (i + 2) in
+      let c3 = get' s (i + 3) in
       if (c1 lor c2 lor c3) land 0xc0 <> 0x80 then raise Invalid;
       let v = c lsl 18 + c1 lsl 12 + c2 lsl 6 + c3 - 0x03c82080 in
       if v < 0x10000 || v > 0x10ffff then raise Invalid;
@@ -1023,13 +1024,13 @@ let rec decomp s i l s' j =
       decomp s (i + 4) l s' (j + 4)
     end
   end else
-    String.sub s' 0 j
+    Bytes.sub s' 0 j
 
 let decompose s =
   let l = String.length s in
-  let s' = String.create (3 * l) in
+  let s' = Bytes.create (3 * l) in
   try
-    let s' = decomp s 0 l s' 0 in order s'; s'
+    let s' = decomp s 0 l s' 0 in order s'; Bytes.to_string s'
   with Invalid ->
     s
 
@@ -1041,10 +1042,10 @@ let rec compare_rec s s' i l =
     if l < String.length s' then -1 else
     0
   end else begin
-    let c = get s i in
-    let c' = get s' i in
+    let c = get' s i in
+    let c' = get' s' i in
     if c < 0x80 && c' < 0x80 then begin
-      let v = compare (get norm_ascii c) (get norm_ascii c') in
+      let v = compare (get' norm_ascii c) (get' norm_ascii c') in
       if v <> 0 then v else compare_rec s s' (i + 1) l
     end else
       compare (normalize s) (normalize s')
@@ -1061,8 +1062,8 @@ let rec compare_cs_rec s s' i l =
     if l < String.length s' then -1 else
     0
   end else begin
-    let c = get s i in
-    let c' = get s' i in
+    let c = get' s i in
+    let c' = get' s' i in
     if c < 0x80 && c' < 0x80 then begin
       let v = compare c c' in
       if v <> 0 then v else compare_cs_rec s s' (i + 1) l
@@ -1457,12 +1458,12 @@ let uniCharCombiningBitmap = "\
 let bitmap_test base bitmap character =
   character >= base && character < 0x10000
     &&
-  (let value = get bitmap ((character lsr 8) land 0xFF) in
+  (let value = get' bitmap ((character lsr 8) land 0xFF) in
    value = 0xFF
       ||
    (value <> 0
        &&
-    get bitmap ((value - 1) * 32 + 256 + (character land 0xFF) / 8)
+    get' bitmap ((value - 1) * 32 + 256 + (character land 0xFF) / 8)
       land (1 lsl (character land 7)) <> 0))
 
 let unicode_combinable character =
@@ -1547,8 +1548,8 @@ let rec scan d s i l =
     end
   end else begin
     let (i1, i2) = d in
-    String.blit s i2 s i1 (l - i2);
-    String.sub s 0 (i1 + l - i2)
+    Bytes.blit s i2 s i1 (l - i2);
+    Bytes.sub s 0 (i1 + l - i2)
   end
 
 and cont d s i l j v' =
@@ -1560,7 +1561,7 @@ and cont d s i l j v' =
       scan d s j l
     else begin
       let (i1, i2) = d in
-      String.blit s i2 s i1 (i - i2);
+      Bytes.blit s i2 s i1 (i - i2);
       let i1 = i1 + i - i2 in
       let (v'', i) = compose_rec s j l v'' in
       let i1 = encode_char s i1 l v'' in
@@ -1584,7 +1585,10 @@ and compose_rec s i l v =
     (v, i)
 
 let compose s =
-  try scan (0, 0) (String.copy s) 0 (String.length s) with Invalid -> s
+  try
+    let s' = scan (0, 0) (Bytes.of_string s) 0 (String.length s) in
+    Bytes.to_string s'
+  with Invalid -> s
 
 (***)
 
@@ -1594,23 +1598,23 @@ let set_2 s i v =
 
 let get_2 s i = (get s (i + 1)) lsl 8 + get s i
 
-let rec scan s' j s i l =
+let rec scan s' j (s: string) i l =
   if i < l then begin
-    let c = get s i in
+    let c = get' s i in
     if c < 0x80 then
       cont s' j s (i + 1) l c
     else if c < 0xE0 then begin
       (* 80 - 7FF *)
       if c < 0xc2 || i + 1 >= l then fail () else
-      let c1 = get s (i + 1) in
+      let c1 = get' s (i + 1) in
       if c1 land 0xc0 <> 0x80 then fail () else
       let v = c lsl 6 + c1 - 0x3080 in
       cont s' j s (i + 2) l v
     end else if c < 0xF0 then begin
       (* 800 - FFFF *)
       if i + 2 >= l then fail () else
-      let c1 = get s (i + 1) in
-      let c2 = get s (i + 2) in
+      let c1 = get' s (i + 1) in
+      let c2 = get' s (i + 2) in
       if (c1 lor c2) land 0xc0 <> 0x80 then fail () else
       let v = c lsl 12 + c1 lsl 6 + c2 - 0xe2080 in
       if v < 0x800 then fail () else
@@ -1618,9 +1622,9 @@ let rec scan s' j s i l =
     end else begin
       (* 10000 - 10FFFF *)
       if i + 3 >= l then fail () else
-      let c1 = get s (i + 1) in
-      let c2 = get s (i + 2) in
-      let c3 = get s (i + 3) in
+      let c1 = get' s (i + 1) in
+      let c2 = get' s (i + 2) in
+      let c3 = get' s (i + 3) in
       if (c1 lor c2 lor c3) land 0xc0 <> 0x80 then fail () else
       let v = c lsl 18 + c1 lsl 12 + c2 lsl 6 + c3 - 0x03c82080 in
       if v < 0x10000 || v > 0x10ffff then fail () else
@@ -1630,7 +1634,7 @@ let rec scan s' j s i l =
       scan s' (j + 4) s (i + 4) l
     end
   end else
-    String.sub s' 0 (j + 2)
+    Bytes.sub s' 0 (j + 2)
 
 and cont s' j s i l v =
   set_2 s' j v;
@@ -1638,8 +1642,8 @@ and cont s' j s i l v =
 
 let to_utf_16 s =
   let l = String.length s in
-  let s' = String.make (2 * l + 2) '\000' in
-  scan s' 0 s 0 l
+  let s' = Bytes.make (2 * l + 2) '\000' in
+  Bytes.to_string (scan s' 0 s 0 l)
 
 (***)
 
@@ -1665,13 +1669,13 @@ let set_2 s i v =
   set s i (v land 0xff);
   set s (i + 1) (v lsr 8)
 
-let get_2 s i = (get s (i + 1)) lsl 8 + get s i
+let get_2 s i = (get' s (i + 1)) lsl 8 + get' s i
 
-let end_of_name s i l = let i' = i + 1 in i' = l || get s i' = 0x2f (*'/'*)
+let end_of_name s i l = let i' = i + 1 in i' = l || get' s i' = 0x2f (*'/'*)
 
-let rec scan s' j s i l =
+let rec scan s' j (s: string) i l =
   if i < l then begin
-    let c = get s i in
+    let c = get' s i in
     if c < 0x80 then
       cont s' j s (i + 1) l
         (if c = 0x20 && end_of_name s i l then 0xf028
@@ -1680,15 +1684,15 @@ let rec scan s' j s i l =
     else if c < 0xE0 then begin
       (* 80 - 7FF *)
       if c < 0xc2 || i + 1 >= l then fail () else
-      let c1 = get s (i + 1) in
+      let c1 = get' s (i + 1) in
       if c1 land 0xc0 <> 0x80 then fail () else
       let v = c lsl 6 + c1 - 0x3080 in
       cont s' j s (i + 2) l v
     end else if c < 0xF0 then begin
       (* 800 - FFFF *)
       if i + 2 >= l then fail () else
-      let c1 = get s (i + 1) in
-      let c2 = get s (i + 2) in
+      let c1 = get' s (i + 1) in
+      let c2 = get' s (i + 2) in
       if (c1 lor c2) land 0xc0 <> 0x80 then fail () else
       let v = c lsl 12 + c1 lsl 6 + c2 - 0xe2080 in
       if v < 0x800 then fail () else
@@ -1696,9 +1700,9 @@ let rec scan s' j s i l =
     end else begin
       (* 10000 - 10FFFF *)
       if i + 3 >= l then fail () else
-      let c1 = get s (i + 1) in
-      let c2 = get s (i + 2) in
-      let c3 = get s (i + 3) in
+      let c1 = get' s (i + 1) in
+      let c2 = get' s (i + 2) in
+      let c3 = get' s (i + 3) in
       if (c1 lor c2 lor c3) land 0xc0 <> 0x80 then fail () else
       let v = c lsl 18 + c1 lsl 12 + c2 lsl 6 + c3 - 0x03c82080 in
       if v < 0x10000 || v > 0x10ffff then fail () else
@@ -1708,7 +1712,7 @@ let rec scan s' j s i l =
       scan s' (j + 4) s (i + 4) l
     end
   end else
-    String.sub s' 0 (j + 2)
+    Bytes.sub s' 0 (j + 2)
 
 and cont s' j s i l v =
   set_2 s' j v;
@@ -1716,16 +1720,16 @@ and cont s' j s i l v =
 
 let to_utf_16_filename s =
   let l = String.length s in
-  let s' = String.make (2 * l + 2) '\000' in
-  scan s' 0 s 0 l
+  let s' = Bytes.make (2 * l + 2) '\000' in
+  Bytes.to_string (scan s' 0 s 0 l)
 
 (****)
 
-let rec scan s' i' l' s i l =
+let rec scan s' i' l' (s: string) i l =
   if i + 2 <= l then begin
     let v = get_2 s i in
     if v = 0 then
-      String.sub s' 0 i'  (* null *)
+      Bytes.sub s' 0 i'  (* null *)
     else if v < 0xD800 || v > 0xDFFF then
       let i' = encode_char s' i' l' v in
       scan s' i' l' s (i + 2) l
@@ -1748,13 +1752,13 @@ let rec scan s' i' l' s i l =
   end else if i < l then
     fail () (* Odd number of chars *)
   else
-    String.sub s' 0 i'
+    Bytes.sub s' 0 i'
 
 let from_utf_16 s =
   let l = String.length s in
   let l' = 3 * l / 2 in
-  let s' = String.create l' in
-  scan s' 0 l' s 0 l
+  let s' = Bytes.create l' in
+  Bytes.to_string (scan s' 0 l' s 0 l)
 
 (****)
 
@@ -1772,7 +1776,7 @@ let rec scan s' i' l' s i l =
   if i + 2 <= l then begin
     let v = get_2 s i in
     if v = 0 then
-      String.sub s' 0 i'  (* null *)
+      Bytes.sub s' 0 i'  (* null *)
     else if v < 0xD800 then
       let i' = encode_char s' i' l' v in
       scan s' i' l' s (i + 2) l
@@ -1781,7 +1785,7 @@ let rec scan s' i' l' s i l =
         if v > 0xf000 && v <= 0xf029 then
           if v = 0xf028 && end_of_name s i l then 0x20
           else if v = 0xf029 && end_of_name s i l then 0x2e
-          else get sfm_decode (v - 0xf000)
+          else get' sfm_decode (v - 0xf000)
         else
           v
       in
@@ -1806,34 +1810,34 @@ let rec scan s' i' l' s i l =
   end else if i < l then
     fail () (* Odd number of chars *)
   else
-    String.sub s' 0 i'
+    Bytes.sub s' 0 i'
 
 (* NOTE: we MUST have to_utf_16_filename (from_utf_16 s) = s for any
    Windows valid filename s *)
 let from_utf_16_filename s =
   let l = String.length s in
   let l' = 3 * l / 2 in
-  let s' = String.create l' in
-  scan s' 0 l' s 0 l
+  let s' = Bytes.create l' in
+  Bytes.to_string (scan s' 0 l' s 0 l)
 
 (****)
 
 let rec scan s i l =
   i = l ||
-  let c = get s i in
+  let c = get' s i in
   if c < 0x80 then
     c <> 0 && scan s (i + 1) l
   else if c < 0xE0 then begin
     (* 80 - 7FF *)
     c >= 0xc2 && i + 1 < l &&
-    let c1 = get s (i + 1) in
+    let c1 = get' s (i + 1) in
     c1 land 0xc0 = 0x80 &&
     scan s (i + 2) l
   end else if c < 0xF0 then begin
     (* 800 - FFFF *)
     i + 2 < l &&
-    let c1 = get s (i + 1) in
-    let c2 = get s (i + 2) in
+    let c1 = get' s (i + 1) in
+    let c2 = get' s (i + 2) in
     (c1 lor c2) land 0xc0 = 0x80 &&
     let v = c lsl 12 + c1 lsl 6 + c2 - 0xe2080 in
     v >= 0x800 && (v < 0xd800 || (v > 0xdfff && v <> 0xfffe && v <> 0xffff)) &&
@@ -1841,9 +1845,9 @@ let rec scan s i l =
   end else begin
     (* 10000 - 10FFFF *)
     i + 3 < l &&
-    let c1 = get s (i + 1) in
-    let c2 = get s (i + 2) in
-    let c3 = get s (i + 3) in
+    let c1 = get' s (i + 1) in
+    let c2 = get' s (i + 2) in
+    let c3 = get' s (i + 3) in
     (c1 lor c2 lor c3) land 0xc0 = 0x80 &&
     let v = c lsl 18 + c1 lsl 12 + c2 lsl 6 + c3 - 0x03c82080 in
     v >= 0x10000 && v <= 0x10ffff &&
