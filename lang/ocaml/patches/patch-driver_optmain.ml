$NetBSD: patch-driver_optmain.ml,v 1.3 2016/05/05 08:12:01 jaapb Exp $

pkgsrc_runtime flag

--- driver/optmain.ml.orig	2016-04-25 13:36:01.000000000 +0000
+++ driver/optmain.ml
@@ -203,6 +203,7 @@ module Options = Main_args.Make_optcomp_
   let _no_rectypes = clear recursive_types
   let _remove_unused_arguments = set remove_unused_arguments
   let _runtime_variant s = runtime_variant := s
+  let _pkgsrc_runtime = set pkgsrc_runtime
   let _safe_string = clear unsafe_string
   let _short_paths = clear real_paths
   let _strict_sequence = set strict_sequence
