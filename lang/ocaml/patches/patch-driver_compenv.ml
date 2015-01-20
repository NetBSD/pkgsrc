$NetBSD: patch-driver_compenv.ml,v 1.1 2015/01/20 14:12:25 jaapb Exp $

pkgsrc_runtime flag
--- driver/compenv.ml.orig	2014-08-28 16:24:52.000000000 +0000
+++ driver/compenv.ml
@@ -185,6 +185,7 @@ let read_OCAMLPARAM ppf position =
 
       | "pp" -> preprocessor := Some v
       | "runtime-variant" -> runtime_variant := v
+      | "pkgsrc-runtime" -> set "pkgsrc-runtime" [ pkgsrc_runtime ] v
       | "cc" -> c_compiler := Some v
 
       (* assembly sources *)
