$NetBSD: patch-utils_clflags.mli,v 1.1 2015/01/20 14:12:25 jaapb Exp $

pkgsrc_runtime flag
--- utils/clflags.mli.orig	2014-08-28 16:24:52.000000000 +0000
+++ utils/clflags.mli
@@ -90,6 +90,7 @@ val std_include_dir : unit -> string lis
 val shared : bool ref
 val dlcode : bool ref
 val runtime_variant : string ref
+val pkgsrc_runtime : bool ref
 val force_slash : bool ref
 val keep_locs : bool ref
 val unsafe_string : bool ref
