$NetBSD: patch-utils_clflags.ml,v 1.3 2015/12/29 23:34:53 dholland Exp $

pkgsrc_runtime flag

--- utils/clflags.ml.orig	2015-05-12 15:31:26.000000000 +0000
+++ utils/clflags.ml
@@ -108,7 +108,8 @@ let std_include_dir () =
 let shared = ref false (* -shared *)
 let dlcode = ref true (* not -nodynlink *)
 
-let runtime_variant = ref "";;      (* -runtime-variant *)
+let runtime_variant = ref ""        (* -runtime-variant *)
+let pkgsrc_runtime = ref false;;     (* -pkgsrc-runtime *)
 
 let keep_docs = ref false              (* -keep-docs *)
 let keep_locs = ref false              (* -keep-locs *)
