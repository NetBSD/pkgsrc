$NetBSD: patch-expand.ml,v 1.1 2019/12/31 19:46:12 markd Exp $

fixed compilation with recent versions of OCaml 
git commit 8f25afb95a839c9f9522a34013d5c905af14378b 

--- expand.ml.orig	2014-07-04 07:51:21.000000000 +0000
+++ expand.ml
@@ -174,7 +174,7 @@ let date_compare el e1 e2 =
 
 (*s Access to the fields. *)
 
-let get_field (_,_,f) s = List.assoc (String.lowercase s) f
+let get_field (_,_,f) s = List.assoc (String.lowercase_ascii s) f
 let get_lowercase_field (_,_,f) s = List.assoc s f
 
 let get_title e = get_lowercase_field e "title"
