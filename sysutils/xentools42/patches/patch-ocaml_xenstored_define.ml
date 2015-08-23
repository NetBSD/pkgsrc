$NetBSD: patch-ocaml_xenstored_define.ml,v 1.2 2015/08/23 16:17:12 spz Exp $

--- ocaml/xenstored/define.ml.orig	2014-09-02 06:22:57.000000000 +0000
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
