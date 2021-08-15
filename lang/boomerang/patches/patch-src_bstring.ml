$NetBSD: patch-src_bstring.ml,v 1.1 2021/08/15 06:38:38 dholland Exp $

Fix build with current ocaml.

--- src/bstring.ml~	2009-08-26 19:28:59.000000000 +0000
+++ src/bstring.ml
@@ -236,12 +236,12 @@ let dist_limit_aux limit s t =
 
 let rev_s s =
   let n = String.length s in
-  let t = String.make n '\000' in
+  let t = Bytes.make n '\000' in
   let rec loop x y =
     if x >= n
-    then t
+    then Bytes.to_string t
     else (
-      String.set t x s.[y];
+      Bytes.set t x (String.get s y);
       loop (succ x) (pred y)
     )
   in
