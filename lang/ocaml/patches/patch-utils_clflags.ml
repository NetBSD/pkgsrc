$NetBSD: patch-utils_clflags.ml,v 1.1 2015/01/20 14:12:25 jaapb Exp $

pkgsrc_runtime flag
--- utils/clflags.ml.orig	2014-08-28 16:24:52.000000000 +0000
+++ utils/clflags.ml
@@ -106,7 +106,8 @@ let std_include_dir () =
 let shared = ref false (* -shared *)
 let dlcode = ref true (* not -nodynlink *)
 
-let runtime_variant = ref "";;      (* -runtime-variant *)
+let runtime_variant = ref ""           (* -runtime-variant *)
+let pkgsrc_runtime = ref false;;       (* -pkgsrc-runtime *)      
 
 let keep_locs = ref false              (* -keep-locs *)
 let unsafe_string = ref true;;         (* -safe-string / -unsafe-string *)
