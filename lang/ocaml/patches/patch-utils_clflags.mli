$NetBSD: patch-utils_clflags.mli,v 1.4 2016/05/05 08:12:01 jaapb Exp $

pkgsrc_runtime flag

--- utils/clflags.mli.orig	2016-04-01 12:53:41.000000000 +0000
+++ utils/clflags.mli
@@ -174,6 +174,7 @@ val shared : bool ref
 val dlcode : bool ref
 val pic_code : bool ref
 val runtime_variant : string ref
+val pkgsrc_runtime : bool ref
 val force_slash : bool ref
 val keep_docs : bool ref
 val keep_locs : bool ref
