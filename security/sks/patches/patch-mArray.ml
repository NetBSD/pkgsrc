$NetBSD: patch-mArray.ml,v 1.1 2013/11/11 15:14:13 is Exp $

--- mArray.ml.orig	2012-10-07 19:59:39.000000000 +0000
+++ mArray.ml
@@ -57,7 +57,7 @@ let for_all ~f:test array =
   Array.fold_left ~f:(fun a b -> a && (test b)) ~init:true array
 
 let exists ~f:test array =
-  Array.fold_left ~f:(fun a b -> a or (test b)) ~init:false array
+  Array.fold_left ~f:(fun a b -> a || (test b)) ~init:false array
 
 let mem el array =
   let length = Array.length array in
