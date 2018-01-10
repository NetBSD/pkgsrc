$NetBSD: patch-ppx_ppx__reflect.ml,v 1.1 2018/01/10 16:48:21 jaapb Exp $

Quick patch to compile with OCaml 4.06
--- ppx/ppx_reflect.ml.orig	2017-03-03 16:33:22.000000000 +0000
+++ ppx/ppx_reflect.ml
@@ -446,7 +446,8 @@ let emit_module () =
     ] else []
   end @
 
-  List.map Combi.(let_ AC.pvar (tuple2 str (list str))) !reflected_variants
+  List.map Combi.(let_ AC.pvar (tuple2 str (list str)))
+	(List.map (fun (a, (b, c)) -> (a, (b.txt, List.map (fun x -> x.txt) c))) !reflected_variants)
 
 
 (* Crude I/O tools to read a signature and output a structure.
