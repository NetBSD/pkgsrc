$NetBSD: patch-fspath.ml,v 1.1 2018/03/14 11:16:15 dholland Exp $

Fix build with ocaml 4.06.

--- fspath.ml.orig	2012-09-17 14:09:03.000000000 +0000
+++ fspath.ml
@@ -55,7 +55,7 @@ let winRootFix d =
 (* least distinguishing suffixes of two fspaths, for displaying in the user  *)
 (* interface.                                                                *)
 let differentSuffix (Fspath f1) (Fspath f2) =
-  if isRootDir f1 or isRootDir f2 then (f1,f2)
+  if isRootDir f1 || isRootDir f2 then (f1,f2)
   else begin
     (* We use the invariant that neither f1 nor f2 ends in slash             *)
     let len1 = String.length f1 in
@@ -92,12 +92,12 @@ let appleDouble (Fspath f) =
   let len = String.length f in
   try
     let i = 1 + String.rindex f '/' in
-    let res = String.create (len + 2) in
+    let res = Bytes.create (len + 2) in
     String.blit f 0 res 0 i;
-    res.[i] <- '.';
-    res.[i + 1] <- '_';
+    Bytes.set res i '.';
+    Bytes.set res (i + 1) '_';
     String.blit f i res (i + 2) (len - i);
-    Fspath res
+    Fspath (Bytes.to_string res)
   with Not_found ->
     assert false
 
@@ -192,11 +192,11 @@ let concat fspath path =
       let p = Path.toString path in
       let l = String.length fspath in
       let l' = String.length p in
-      let s = String.create (l + l' + 1) in
+      let s = Bytes.create (l + l' + 1) in
       String.blit fspath 0 s 0 l;
-      s.[l] <- '/';
+      Bytes.set s l '/';
       String.blit p 0 s (l + 1) l';
-      Fspath s
+      Fspath (Bytes.to_string s)
   end
 
 (* Filename.dirname is screwed up in Windows so we use this function.  It    *)
