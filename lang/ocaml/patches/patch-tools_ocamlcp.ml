$NetBSD: patch-tools_ocamlcp.ml,v 1.3 2016/05/05 08:12:01 jaapb Exp $

pkgsrc_runtime flag

--- tools/ocamlcp.ml.orig	2016-04-25 13:36:01.000000000 +0000
+++ tools/ocamlcp.ml
@@ -86,6 +86,7 @@ module Options = Main_args.Make_bytecomp
   let _output_obj = option "-output-obj"
   let _output_complete_obj = option "-output-complete-obj"
   let _pack = option "-pack"
+  let _pkgsrc_runtime = option "-pkgsrc-runtime"
   let _pp _s = incompatible "-pp"
   let _ppx _s = incompatible "-ppx"
   let _principal = option "-principal"
