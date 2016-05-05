$NetBSD: patch-tools_ocamloptp.ml,v 1.3 2016/05/05 08:12:01 jaapb Exp $

pkgsrc_runtime flag

--- tools/ocamloptp.ml.orig	2016-04-25 13:36:01.000000000 +0000
+++ tools/ocamloptp.ml
@@ -108,6 +108,7 @@ module Options = Main_args.Make_optcomp_
   let _output_complete_obj = option "-output-complete-obj"
   let _p = option "-p"
   let _pack = option "-pack"
+  let _pkgsrc_runtime = option "-pkgsrc-runtime"
   let _pp _s = incompatible "-pp"
   let _ppx _s = incompatible "-ppx"
   let _principal = option "-principal"
