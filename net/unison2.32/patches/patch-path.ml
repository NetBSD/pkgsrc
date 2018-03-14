$NetBSD: patch-path.ml,v 1.1 2018/03/14 10:16:03 dholland Exp $

Fix build with ocaml 4.06.

--- path.ml~	2009-05-02 02:31:27.000000000 +0000
+++ path.ml
@@ -30,11 +30,11 @@ let concat p p' =
   if l = 0 then p' else
   let l' = String.length p' in
   if l' = 0 then p else
-  let p'' = String.create (l + l' + 1) in
+  let p'' = Bytes.create (l + l' + 1) in
   String.blit p 0 p'' 0 l;
-  p''.[l] <- pathSeparatorChar;
+  Bytes.set p'' l pathSeparatorChar;
   String.blit p' 0 p'' (l + 1) l';
-  p''
+  Bytes.to_string p''
 
 let empty = ""
 
@@ -182,11 +182,11 @@ let addPrefixToFinalName path prefix =
     let i = String.rindex path pathSeparatorChar + 1 in
     let l = String.length path in
     let l' = String.length prefix in
-    let p = String.create (l + l') in
+    let p = Bytes.create (l + l') in
     String.blit path 0 p 0 i;
     String.blit prefix 0 p i l';
     String.blit path i p (i + l') (l - i);
-    p
+    Bytes.to_string p
   with Not_found ->
     assert (not (isEmpty path));
     prefix ^ path
