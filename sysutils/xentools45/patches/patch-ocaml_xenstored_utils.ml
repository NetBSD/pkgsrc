$NetBSD: patch-ocaml_xenstored_utils.ml,v 1.1 2015/01/20 16:42:13 bouyer Exp $

--- ocaml/xenstored/utils.ml.orig	2015-01-12 17:53:24.000000000 +0100
+++ ocaml/xenstored/utils.ml	2015-01-19 13:16:38.000000000 +0100
@@ -94,7 +94,7 @@
 	let buf = String.make 20 (char_of_int 0) in
 	let sz = Unix.read fd buf 0 20 in
 	Unix.close fd;
-	int_of_string (String.sub buf 0 sz)
+	int_of_string (String.trim (String.sub buf 0 sz))
 
 let path_complete path connection_path =
 	if String.get path 0 <> '/' then
