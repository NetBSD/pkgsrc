$NetBSD: patch-ocaml_xenstored_define.ml,v 1.1 2013/05/15 06:58:50 jnemeth Exp $

--- ocaml/xenstored/define.ml.orig	2012-12-17 15:01:22.000000000 +0000
+++ ocaml/xenstored/define.ml
@@ -17,13 +17,13 @@
 let xenstored_major = 1
 let xenstored_minor = 0
 
-let xenstored_proc_kva = "/proc/xen/xsd_kva"
+let xenstored_proc_kva = "@PROCDEV@/xsd_kva"
 let xenstored_proc_port = "/proc/xen/xsd_port"
 
 let xs_daemon_socket = "/var/run/xenstored/socket"
 let xs_daemon_socket_ro = "/var/run/xenstored/socket_ro"
 
-let default_config_dir = "/etc/xen"
+let default_config_dir = "@XENDCONFDIR@"
 
 let maxwatch = ref (50)
 let maxtransaction = ref (20)
