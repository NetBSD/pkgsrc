$NetBSD: patch-files.ml,v 1.1 2019/10/18 09:59:26 pho Exp $

Replace deprecated sort function

--- files.ml.orig	2010-04-15 17:29:31.000000000 +0000
+++ files.ml
@@ -679,7 +679,7 @@ let get_files_in_directory dir =
   with End_of_file ->
     dirh.System.closedir ()
   end;
-  Sort.list (<) !files
+  List.sort String.compare !files
 
 let ls dir pattern =
   Util.convertUnixErrorsToTransient
