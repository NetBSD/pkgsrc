$NetBSD: patch-tools_qemu-xen-traditional_net.c,v 1.1 2017/03/30 09:15:10 bouyer Exp $
--- tools/qemu-xen-traditional/net.c.orig	2016-11-29 17:36:38.000000000 +0100
+++ tools/qemu-xen-traditional/net.c	2017-03-29 18:16:54.000000000 +0200
@@ -990,6 +990,7 @@
 #define DEFAULT_NETWORK_DOWN_SCRIPT ""
 #endif
 
+#if !defined(CONFIG_STUBDOM)
 static int launch_script(const char *setup_script, const char *ifname,
                          const char *script_arg, int fd)
 {
@@ -1028,6 +1029,7 @@
         }
     return 0;
 }
+#endif
 
 static int net_tap_init(VLANState *vlan, const char *model,
                         const char *name, const char *ifname1,
@@ -1048,12 +1050,14 @@
 
     if (!setup_script || !strcmp(setup_script, "no"))
         setup_script = "";
+#if !defined(CONFIG_STUBDOM)
     if (setup_script[0] != '\0') {
 	if (launch_script(setup_script, ifname, script_arg, fd)) {
 	    close(fd);
 	    return -1;
 	}
     }
+#endif
     s = net_tap_fd_init(vlan, model, name, fd);
     if (!s)
         return -1;
@@ -1965,9 +1969,11 @@
             if (vc->fd_read == tap_receive) {
                 TAPState *s = vc->opaque;
 
+#ifndef CONFIG_STUBDOM
                 if (s->down_script[0])
                     launch_script(s->down_script, s->down_script_arg,
 				  s->script_arg, s->fd);
+#endif
             }
 #if defined(CONFIG_VDE)
             if (vc->fd_read == vde_from_qemu) {
