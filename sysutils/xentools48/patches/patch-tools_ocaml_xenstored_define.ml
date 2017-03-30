$NetBSD: patch-tools_ocaml_xenstored_define.ml,v 1.1 2017/03/30 09:15:10 bouyer Exp $

--- tools/ocaml/xenstored/define.ml.orig	2016-12-05 13:03:27.000000000 +0100
+++ tools/ocaml/xenstored/define.ml	2017-03-24 17:29:24.000000000 +0100
@@ -17,7 +17,7 @@
 let xenstored_major = 1
 let xenstored_minor = 0
 
-let xenstored_proc_kva = "/proc/xen/xsd_kva"
+let xenstored_proc_kva = "@PROCDEV@/xen/xsd_kva"
 let xenstored_proc_port = "/proc/xen/xsd_port"
 
 let xs_daemon_socket = Paths.xen_run_stored ^ "/socket"
