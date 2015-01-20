$NetBSD: patch-driver_main.ml,v 1.1 2015/01/20 14:12:25 jaapb Exp $

pkgsrc_runtime flag
--- driver/main.ml.orig	2014-08-28 16:24:52.000000000 +0000
+++ driver/main.ml
@@ -112,6 +112,7 @@ module Options = Main_args.Make_bytecomp
   let _principal = set principal
   let _rectypes = set recursive_types
   let _runtime_variant s = runtime_variant := s
+  let _pkgsrc_runtime = set pkgsrc_runtime
   let _safe_string = unset unsafe_string
   let _short_paths = unset real_paths
   let _strict_sequence = set strict_sequence
