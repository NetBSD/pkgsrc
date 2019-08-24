$NetBSD: patch-driver_compenv.ml,v 1.4 2019/08/24 10:54:23 jaapb Exp $

pkgsrc_runtime flag

--- driver/compenv.ml.orig	2019-02-08 14:34:09.000000000 +0000
+++ driver/compenv.ml
@@ -235,6 +235,7 @@ let read_one_param ppf position name v =
 
   | "pp" -> preprocessor := Some v
   | "runtime-variant" -> runtime_variant := v
+  | "pkgsrc-runtime" -> set "pkgsrc-runtime" [ pkgsrc_runtime ] v
   | "open" ->
       open_modules := List.rev_append (String.split_on_char ',' v) !open_modules
   | "cc" -> c_compiler := Some v
