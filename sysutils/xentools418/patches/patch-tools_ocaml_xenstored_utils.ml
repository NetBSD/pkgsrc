$NetBSD: patch-tools_ocaml_xenstored_utils.ml,v 1.1 2023/11/21 11:37:03 bouyer Exp $

--- tools/ocaml/xenstored/utils.ml.orig	2023-10-06 19:17:42.000000000 +0200
+++ tools/ocaml/xenstored/utils.ml	2023-10-11 16:21:27.581933766 +0200
@@ -86,7 +86,7 @@
   let buf = Bytes.make 20 '\000' in
   let sz = Unix.read fd buf 0 20 in
   Unix.close fd;
-  int_of_string (Bytes.sub_string buf 0 sz)
+  int_of_string (String.trim (Bytes.sub_string buf 0 sz))
 
 (* @path may be guest data and needs its length validating.  @connection_path
  * is generated locally in xenstored and always of the form "/local/domain/$N/" *)
