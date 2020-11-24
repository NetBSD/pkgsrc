$NetBSD: patch-pscp.c,v 1.1 2020/11/24 15:38:36 ryoon Exp $

* Fix https://www.chiark.greenend.org.uk/~sgtatham/putty/wishlist/pscp-port-0.html

--- pscp.c.orig	2020-06-21 17:30:46.000000000 +0000
+++ pscp.c
@@ -330,7 +330,7 @@ static void do_cmd(char *host, char *use
      * Force use of SSH. (If they got the protocol wrong we assume the
      * port is useless too.)
      */
-    if (conf_get_int(conf, CONF_protocol) != PROT_SSH) {
+    if (!backend_vt_from_proto(conf_get_int(conf, CONF_protocol))) {
         conf_set_int(conf, CONF_protocol, PROT_SSH);
         conf_set_int(conf, CONF_port, 22);
     }
@@ -454,7 +454,9 @@ static void do_cmd(char *host, char *use
 
     platform_psftp_pre_conn_setup();
 
-    err = backend_init(&ssh_backend, pscp_seat, &backend, logctx, conf,
+    err = backend_init(backend_vt_from_proto(
+                           conf_get_int(conf, CONF_protocol)),
+                       pscp_seat, &backend, logctx, conf,
                        conf_get_str(conf, CONF_host),
                        conf_get_int(conf, CONF_port),
                        &realhost, 0,
@@ -2240,8 +2242,6 @@ int psftp_main(int argc, char *argv[])
     int i;
     bool sanitise_stderr = true;
 
-    default_protocol = PROT_SSH;
-
     flags = 0
 #ifdef FLAG_SYNCAGENT
         | FLAG_SYNCAGENT
