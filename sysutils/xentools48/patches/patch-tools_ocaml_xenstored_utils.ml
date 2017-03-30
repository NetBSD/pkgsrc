$NetBSD: patch-tools_ocaml_xenstored_utils.ml,v 1.1 2017/03/30 09:15:10 bouyer Exp $

--- tools/ocaml/xenstored/utils.ml.orig	2016-12-05 13:03:27.000000000 +0100
+++ tools/ocaml/xenstored/utils.ml	2017-03-24 17:31:22.000000000 +0100
@@ -87,7 +87,7 @@
 	let buf = String.make 20 (char_of_int 0) in
 	let sz = Unix.read fd buf 0 20 in
 	Unix.close fd;
-	int_of_string (String.sub buf 0 sz)
+	int_of_string (String.trim (String.sub buf 0 sz))
 
 let path_complete path connection_path =
 	if String.get path 0 <> '/' then
