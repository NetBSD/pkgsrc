$NetBSD: patch-ocaml_xenstored_define.ml,v 1.1.1.1 2016/07/04 07:30:52 jnemeth Exp $

--- ocaml/xenstored/define.ml.orig	2015-01-12 17:53:24.000000000 +0100
+++ ocaml/xenstored/define.ml	2015-01-19 13:16:38.000000000 +0100
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
