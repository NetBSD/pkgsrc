$NetBSD: patch-tools_ocamloptp.ml,v 1.2 2015/12/29 23:34:53 dholland Exp $

pkgsrc_runtime flag

--- tools/ocamloptp.ml.orig	2014-08-28 16:24:52.000000000 +0000
+++ tools/ocamloptp.ml
@@ -82,6 +82,7 @@ module Options = Main_args.Make_optcomp_
   let _principal = option "-principal"
   let _rectypes = option "-rectypes"
   let _runtime_variant s = option_with_arg "-runtime-variant" s
+  let _pkgsrc_runtime = option "-pkgsrc-runtime"
   let _S = option "-S"
   let _safe_string = option "-safe-string"
   let _short_paths = option "-short-paths"
