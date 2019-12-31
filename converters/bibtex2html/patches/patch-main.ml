$NetBSD: patch-main.ml,v 1.1 2019/12/31 19:46:12 markd Exp $

fixed compilation with recent versions of OCaml 
git commit 8f25afb95a839c9f9522a34013d5c905af14378b 

--- main.ml.orig	2014-07-04 07:51:21.000000000 +0000
+++ main.ml
@@ -89,7 +89,7 @@ let sort_entries entries bibitems =
   in
   let sl =
     if !sort = By_date then
-      Sort.list (fun (_,_,e1) (_,_,e2) -> Expand.date_order entries e1 e2) el
+      List.sort (fun (_,_,e1) (_,_,e2) -> Expand.date_compare entries e1 e2) el
     else
       el
   in
