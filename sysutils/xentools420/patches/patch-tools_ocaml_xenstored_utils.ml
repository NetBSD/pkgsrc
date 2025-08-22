$NetBSD: patch-tools_ocaml_xenstored_utils.ml,v 1.1 2025/08/22 09:00:13 bouyer Exp $

--- tools/ocaml/xenstored/utils.ml.orig	2025-08-04 15:22:34.000000000 +0200
+++ tools/ocaml/xenstored/utils.ml	2025-08-21 16:25:53.106883352 +0200
@@ -92,7 +92,7 @@
   let buf = Bytes.make 20 '\000' in
   let sz = Unix.read fd buf 0 20 in
   Unix.close fd;
-  int_of_string_exn (Bytes.sub_string buf 0 sz)
+  int_of_string_exn (String.trim (Bytes.sub_string buf 0 sz))
 
 (* @path may be guest data and needs its length validating.  @connection_path
  * is generated locally in xenstored and always of the form "/local/domain/$N/" *)
