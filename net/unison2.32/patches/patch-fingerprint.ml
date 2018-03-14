$NetBSD: patch-fingerprint.ml,v 1.1 2018/03/14 10:16:03 dholland Exp $

Fix build with ocaml 4.06.

--- fingerprint.ml~	2009-05-02 02:31:27.000000000 +0000
+++ fingerprint.ml
@@ -66,13 +66,13 @@ let hexaCode theChar =
 
 let toString md5 =
   let length = String.length md5 in
-  let string = String.create (length * 2) in
+  let string = Bytes.create (length * 2) in
   for i=0 to (length - 1) do
     let c1, c2 =  hexaCode (md5.[i]) in
-    string.[2*i] <- c1;
-    string.[2*i + 1] <- c2;
+    Bytes.set string (2*i) c1;
+    Bytes.set string (2*i + 1) c2;
   done;
-  string
+  Bytes.to_string string
 
 let string = Digest.string
 
