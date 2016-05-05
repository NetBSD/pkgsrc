$NetBSD: patch-utils_clflags.ml,v 1.4 2016/05/05 08:12:01 jaapb Exp $

pkgsrc_runtime flag

--- utils/clflags.ml.orig	2016-04-01 12:53:41.000000000 +0000
+++ utils/clflags.ml
@@ -148,7 +148,8 @@ let pic_code = ref (match Config.archite
                      | "amd64" -> true
                      | _       -> false)
 
-let runtime_variant = ref "";;      (* -runtime-variant *)
+let runtime_variant = ref ""        (* -runtime-variant *)
+let pkgsrc_runtime = ref false;;    (* -pkgsrc-runtime *)
 
 let keep_docs = ref false              (* -keep-docs *)
 let keep_locs = ref false              (* -keep-locs *)
