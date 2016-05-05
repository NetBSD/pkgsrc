$NetBSD: patch-driver_compenv.ml,v 1.3 2016/05/05 08:12:01 jaapb Exp $

pkgsrc_runtime flag

--- driver/compenv.ml.orig	2016-04-01 12:53:41.000000000 +0000
+++ driver/compenv.ml
@@ -217,6 +217,7 @@ let read_one_param ppf position name v =
 
   | "pp" -> preprocessor := Some v
   | "runtime-variant" -> runtime_variant := v
+  | "pkgsrc-runtime" -> set "pkgsrc-runtime" [ pkgsrc_runtime ] v
   | "cc" -> c_compiler := Some v
 
   | "clambda-checks" -> set "clambda-checks" [ clambda_checks ] v
