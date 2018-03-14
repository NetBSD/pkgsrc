$NetBSD: patch-fileutil.ml,v 1.1 2018/03/14 11:16:15 dholland Exp $

Fix build with ocaml 4.06.

--- fileutil.ml~	2009-05-02 02:31:27.000000000 +0000
+++ fileutil.ml
@@ -21,14 +21,14 @@ let backslashes2forwardslashes s0 =
   try
     ignore(String.index s0 '\\'); (* avoid alloc if possible *)
     let n = String.length s0 in
-    let s = String.create n in
+    let s = Bytes.create n in
     for i = 0 to n-1 do
       let c = String.get s0 i in
       if c = '\\'
-      then String.set s i '/'
-      else String.set s i c
+      then Bytes.set s i '/'
+      else Bytes.set s i c
     done;
-    s
+    Bytes.to_string s
   with Not_found -> s0
 
 let rec removeTrailingSlashes s =
