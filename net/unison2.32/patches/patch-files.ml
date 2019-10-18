$NetBSD: patch-files.ml,v 1.1 2019/10/18 09:45:27 pho Exp $

Replace deprecated sort function

--- files.ml.orig	2009-06-09 15:46:38.000000000 +0000
+++ files.ml
@@ -569,7 +569,7 @@ let get_files_in_directory dir =
   with End_of_file ->
     Unix.closedir dirh
   end;
-  Sort.list (<) !files
+  List.sort String.compare !files
 
 let ls dir pattern =
   Util.convertUnixErrorsToTransient
