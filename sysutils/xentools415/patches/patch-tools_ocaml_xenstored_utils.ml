$NetBSD: patch-tools_ocaml_xenstored_utils.ml,v 1.1 2021/04/18 12:31:26 bouyer Exp $

--- tools/ocaml/xenstored/utils.ml.orig	2021-01-10 18:02:05.000000000 +0100
+++ tools/ocaml/xenstored/utils.ml	2021-01-10 20:20:53.433611357 +0100
@@ -86,7 +86,7 @@
 	let buf = Bytes.make 20 '\000' in
 	let sz = Unix.read fd buf 0 20 in
 	Unix.close fd;
-	int_of_string (Bytes.sub_string buf 0 sz)
+	int_of_string (String.trim (Bytes.sub_string buf 0 sz))
 
 (* @path may be guest data and needs its length validating.  @connection_path
  * is generated locally in xenstored and always of the form "/local/domain/$N/" *)
