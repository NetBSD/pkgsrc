$NetBSD: patch-recon.ml,v 1.1 2019/10/18 09:45:27 pho Exp $

Replace deprecated sort function

--- recon.ml.orig	2009-05-02 02:31:27.000000000 +0000
+++ recon.ml
@@ -455,8 +455,8 @@ let rec reconcile path ui1 ui2 counter e
 
 (* Sorts the paths so that they will be displayed in order                   *)
 let sortPaths pathUpdatesList =
-  Sort.list
-    (fun (p1, _) (p2, _) -> Path.compare p1 p2 <= 0)
+  List.sort
+    (fun (p1, _) (p2, _) -> Path.compare p1 p2)
     pathUpdatesList
 
 let rec enterPath p t =
