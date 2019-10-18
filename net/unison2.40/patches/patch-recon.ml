$NetBSD: patch-recon.ml,v 1.1 2019/10/18 09:59:26 pho Exp $

Replace deprecated sort function

--- recon.ml.orig	2010-10-08 15:44:59.000000000 +0000
+++ recon.ml
@@ -622,8 +622,8 @@ let rec reconcile
 
 (* Sorts the paths so that they will be displayed in order                   *)
 let sortPaths pathUpdatesList =
-  Sort.list
-    (fun (p1, _) (p2, _) -> Path.compare p1 p2 <= 0)
+  List.sort
+    (fun (p1, _) (p2, _) -> Path.compare p1 p2)
     pathUpdatesList
 
 let rec enterPath p1 p2 t =
