$NetBSD: patch-tools_ocaml_xenstored_utils.ml,v 1.1 2020/05/26 11:12:11 bouyer Exp $

--- ./tools/ocaml/xenstored/utils.ml.orig	2018-07-09 15:47:19.000000000 +0200
+++ ./tools/ocaml/xenstored/utils.ml	2018-07-16 13:50:03.000000000 +0200
@@ -86,7 +86,7 @@
 	let buf = Bytes.make 20 '\000' in
 	let sz = Unix.read fd buf 0 20 in
 	Unix.close fd;
-	int_of_string (Bytes.sub_string buf 0 sz)
+	int_of_string (String.trim (String.sub buf 0 sz))
 
 let path_complete path connection_path =
 	if String.get path 0 <> '/' then
