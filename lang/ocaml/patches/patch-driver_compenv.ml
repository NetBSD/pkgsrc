$NetBSD: patch-driver_compenv.ml,v 1.2 2015/12/29 23:34:53 dholland Exp $

pkgsrc_runtime flag

--- driver/compenv.ml.orig	2014-08-28 16:24:52.000000000 +0000
+++ driver/compenv.ml
@@ -185,6 +185,7 @@ let read_OCAMLPARAM ppf position =
 
       | "pp" -> preprocessor := Some v
       | "runtime-variant" -> runtime_variant := v
+      | "pkgsrc-runtime" -> set "pkgsrc-runtime" [ pkgsrc_runtime ] v
       | "cc" -> c_compiler := Some v
 
       (* assembly sources *)
