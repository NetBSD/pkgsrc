$NetBSD: patch-utils_clflags.ml,v 1.5 2018/01/10 14:30:35 jaapb Exp $

pkgsrc_runtime flag

--- utils/clflags.ml.orig	2017-10-03 08:35:25.000000000 +0000
+++ utils/clflags.ml
@@ -154,7 +154,8 @@ let pic_code = ref (match Config.archite
                      | "amd64" -> true
                      | _       -> false)
 
-let runtime_variant = ref "";;      (* -runtime-variant *)
+let runtime_variant = ref ""           (* -runtime-variant *)
+let pkgsrc_runtime = ref false;;       (* -pkgsrc-runtime *)
 
 let keep_docs = ref false              (* -keep-docs *)
 let keep_locs = ref true               (* -keep-locs *)
