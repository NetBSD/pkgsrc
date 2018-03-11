$NetBSD: patch-bi__util.ml,v 1.1 2018/03/11 02:30:34 dholland Exp $

Fix up mutable strings to make it build with ocaml 4.06.

--- bi_util.ml~	2017-05-04 17:38:05.000000000 +0000
+++ bi_util.ml
@@ -8,18 +8,18 @@ let error s = raise (Error s)
 *)
 
 let string8_of_int x =
-  let s = String.create 8 in
+  let s = Bytes.create 8 in
   for i = 0 to 7 do
-    s.[7-i] <- Char.chr (0xff land (x lsr (8 * i)))
+    Bytes.set s (7-i) (Char.chr (0xff land (x lsr (8 * i))))
   done;
-  s
+  Bytes.to_string s
 
 let string4_of_int x =
-  let s = String.create 4 in
+  let s = Bytes.create 4 in
   for i = 0 to 3 do
-    s.[3-i] <- Char.chr (0xff land (x lsr (8 * i)))
+    Bytes.set s (3-i) (Char.chr (0xff land (x lsr (8 * i))))
   done;
-  s
+  Bytes.to_string s
 
 let print_bits ?(pos = 0) ?len s =
   let slen = String.length s in
@@ -33,16 +33,16 @@ let print_bits ?(pos = 0) ?len s =
           else len
   in
 
-  let r = String.create (len * 9) in
+  let r = Bytes.create (len * 9) in
   for i = 0 to len - 1 do
     let k = i * 9 in
     let x = Char.code s.[pos+i] in
     for j = 0 to 7 do
-      r.[k+j] <- if (x lsr (7 - j)) land 1 = 0 then '0' else '1'
+      Bytes.set r (k+j) (if (x lsr (7 - j)) land 1 = 0 then '0' else '1')
     done;
-    r.[k+8] <- if (i + 1) mod 8 = 0 then '\n' else ' '
+    Bytes.set r (k+8) (if (i + 1) mod 8 = 0 then '\n' else ' ')
   done;
-  r
+  Bytes.to_string r
 
 (* int size in bits *)
 let int_size =
