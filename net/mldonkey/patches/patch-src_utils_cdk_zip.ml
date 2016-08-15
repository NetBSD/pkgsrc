$NetBSD: patch-src_utils_cdk_zip.ml,v 1.1 2016/08/15 15:48:19 jaapb Exp $

Compile with OCaml 4.03
--- src/utils/cdk/zip.ml.orig	2007-02-06 22:26:59.000000000 +0000
+++ src/utils/cdk/zip.ml
@@ -72,8 +72,6 @@ type out_file =
     mutable of_entries: entry list;
     of_comment: string }
 
-exception Error of string * string * string
-
 (* Return the position of the last occurrence of s1 in s2, or -1 if not
    found. *)
 
