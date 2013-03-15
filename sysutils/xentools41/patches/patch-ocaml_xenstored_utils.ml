$NetBSD: patch-ocaml_xenstored_utils.ml,v 1.1 2013/03/15 16:10:58 is Exp $

--- ocaml/xenstored/utils.ml.orig
+++ ocaml/xenstored/utils.ml
@@ -87,7 +83,7 @@ let read_file_single_integer filename =
 	let buf = String.make 20 (char_of_int 0) in
 	let sz = Unix.read fd buf 0 20 in
 	Unix.close fd;
-	int_of_string (String.sub buf 0 sz)
+	int_of_string (String.trim (String.sub buf 0 sz))
 
 let path_complete path connection_path =
 	if String.get path 0 <> '/' then
