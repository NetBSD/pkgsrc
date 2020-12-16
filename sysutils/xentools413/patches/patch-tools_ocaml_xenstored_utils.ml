$NetBSD: patch-tools_ocaml_xenstored_utils.ml,v 1.2 2020/12/16 17:17:08 bouyer Exp $

--- tools/ocaml/xenstored/utils.ml.orig	2020-12-16 15:52:12.099100673 +0100
+++ tools/ocaml/xenstored/utils.ml	2020-12-16 15:54:33.692088910 +0100
@@ -86,7 +86,7 @@
 	let buf = Bytes.make 20 '\000' in
 	let sz = Unix.read fd buf 0 20 in
 	Unix.close fd;
-	int_of_string (Bytes.sub_string buf 0 sz)
+	int_of_string (String.trim (Bytes.sub_string buf 0 sz))
 
 (* @path may be guest data and needs its length validating.  @connection_path
  * is generated locally in xenstored and always of the form "/local/domain/$N/" *)
