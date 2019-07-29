$NetBSD: patch-src_recon.ml,v 1.1 2019/07/29 18:07:10 wiz Exp $

Replace deprecated sort function
--- src/recon.ml.orig	2018-01-27 21:12:13.000000000 +0000
+++ src/recon.ml
@@ -661,8 +661,8 @@ let rec reconcile
 
 (* Sorts the paths so that they will be displayed in order                   *)
 let sortPaths pathUpdatesList =
-  Sort.list
-    (fun (p1, _) (p2, _) -> Path.compare p1 p2 <= 0)
+  List.sort
+    Path.compare
     pathUpdatesList
 
 let rec enterPath p1 p2 t =
