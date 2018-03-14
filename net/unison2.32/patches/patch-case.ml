$NetBSD: patch-case.ml,v 1.1 2018/03/14 10:16:03 dholland Exp $

Fix build with ocaml 4.06.

--- case.ml~	2009-05-29 12:54:25.000000000 +0000
+++ case.ml
@@ -56,19 +56,19 @@ let needNormalization s =
 
 let removeTrailingDots s =
   let len = String.length s in
-  let s' = String.create len in
+  let s' = Bytes.create len in
   let pos = ref (len - 1) in
   let pos' = ref (len - 1) in
   while !pos >= 0 do
     while !pos >= 0 && s.[!pos] = '.' do decr pos done;
     while !pos >= 0 && s.[!pos] <> '/' do
-      s'.[!pos'] <- s.[!pos]; decr pos; decr pos'
+      Bytes.set s' !pos' s.[!pos]; decr pos; decr pos'
     done;
     while !pos >= 0 && s.[!pos] = '/' do
-      s'.[!pos'] <- s.[!pos]; decr pos; decr pos'
+      Bytes.set s' !pos' s.[!pos]; decr pos; decr pos'
     done
   done;
-  String.sub s' (!pos' + 1) (len - !pos' - 1)
+  Bytes.to_string (Bytes.sub s' (!pos' + 1) (len - !pos' - 1))
 
 (* Dots are ignored at the end of filenames under Windows. *)
 let normalize s =
