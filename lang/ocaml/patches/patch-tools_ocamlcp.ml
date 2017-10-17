$NetBSD: patch-tools_ocamlcp.ml,v 1.5 2017/10/17 08:26:05 wiz Exp $

pkgsrc_runtime flag

--- tools/ocamlcp.ml.orig	2016-09-05 13:19:52.000000000 +0000
+++ tools/ocamlcp.ml
@@ -86,6 +86,7 @@ module Options = Main_args.Make_bytecomp
   let _output_obj = option "-output-obj"
   let _output_complete_obj = option "-output-complete-obj"
   let _pack = option "-pack"
+  let _pkgsrc_runtime = option "-pkgsrc-runtime"
   let _plugin = option_with_arg "-plugin"
   let _pp _s = incompatible "-pp"
   let _ppx _s = incompatible "-ppx"
