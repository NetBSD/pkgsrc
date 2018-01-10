$NetBSD: patch-lib_deriving__interned.ml,v 1.1 2018/01/10 14:57:35 jaapb Exp $

Patch to compile with safe-string.
--- lib/deriving_interned.ml.orig	2016-05-25 16:51:52.000000000 +0000
+++ lib/deriving_interned.ml
@@ -14,15 +14,16 @@ type t = int * string
     deriving (Show)
 
 let intern s =
-  try BytesMap.find s !map
+	let bs = Bytes.of_string s in
+  try BytesMap.find bs !map
   with Not_found ->
-    let fresh = (!counter, Bytes.of_string s) in begin
-      map := BytesMap.add s fresh !map;
+    let fresh = (!counter, s) in begin
+      map := BytesMap.add bs fresh !map;
       incr counter;
       fresh
     end
 
-let to_string (_,s) = Bytes.to_string s
+let to_string (_,s) = s
 let name = snd
 let compare (l,_) (r,_) = compare l r
 let eq (l,_) (r,_) = l = r
