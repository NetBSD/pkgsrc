$NetBSD: patch-zip.ml,v 1.1 2016/05/05 11:27:47 jaapb Exp $

Remove redundant definition
--- zip.ml.orig	2012-10-12 03:36:07.000000000 +0000
+++ zip.ml
@@ -73,7 +73,7 @@ type out_file =
     mutable of_entries: entry list;
     of_comment: string }
 
-exception Error of string * string * string
+(* exception Error of string * string * string *)
 
 (* Return the position of the last occurrence of s1 in s2, or -1 if not
    found. *)
