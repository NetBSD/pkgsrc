$NetBSD: patch-src_files.ml,v 1.1 2019/07/29 18:07:10 wiz Exp $

Replace deprecated sort function
--- src/files.ml.orig	2018-01-27 21:12:13.000000000 +0000
+++ src/files.ml
@@ -734,7 +734,7 @@ let get_files_in_directory dir =
   with End_of_file ->
     dirh.System.closedir ()
   end;
-  Sort.list (<) !files
+  List.sort String.compare !files
 
 let ls dir pattern =
   Util.convertUnixErrorsToTransient
