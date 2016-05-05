$NetBSD: patch-driver_main.ml,v 1.3 2016/05/05 08:12:01 jaapb Exp $

pkgsrc_runtime flag

--- driver/main.ml.orig	2016-04-25 13:36:01.000000000 +0000
+++ driver/main.ml
@@ -129,6 +129,7 @@ module Options = Main_args.Make_bytecomp
   let _rectypes = set recursive_types
   let _no_rectypes = unset recursive_types
   let _runtime_variant s = runtime_variant := s
+  let _pkgsrc_runtime = set pkgsrc_runtime
   let _safe_string = unset unsafe_string
   let _short_paths = unset real_paths
   let _strict_sequence = set strict_sequence
