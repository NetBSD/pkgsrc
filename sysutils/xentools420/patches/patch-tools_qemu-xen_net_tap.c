$NetBSD: patch-tools_qemu-xen_net_tap.c,v 1.1 2025/08/22 09:00:14 bouyer Exp $

From Roman Shaposhnik via xen-devel: pass bridge name to ifup script

--- tools/qemu-xen/net/tap.c.orig	2025-08-21 14:25:20.000000000 +0200
+++ tools/qemu-xen/net/tap.c	2025-08-21 16:30:35.628585691 +0200
@@ -64,7 +64,7 @@
     Notifier exit;
 } TAPState;
 
-static void launch_script(const char *setup_script, const char *ifname,
+static void launch_script(const char *setup_script, const char *ifname, const char *bridge,
                           int fd, Error **errp);
 
 static void tap_send(void *opaque);
@@ -279,7 +279,7 @@
     Error *err = NULL;
 
     if (s->down_script[0]) {
-        launch_script(s->down_script, s->down_script_arg, s->fd, &err);
+        launch_script(s->down_script, s->down_script_arg, "bn1", s->fd, &err);
         if (err) {
             error_report_err(err);
         }
@@ -403,7 +403,7 @@
     qemu_close_all_open_fd(skip_fd, nskip);
 }
 
-static void launch_script(const char *setup_script, const char *ifname,
+static void launch_script(const char *setup_script, const char *ifname, const char *bridge,
                           int fd, Error **errp)
 {
     int pid, status;
@@ -422,6 +422,7 @@
         parg = args;
         *parg++ = (char *)setup_script;
         *parg++ = (char *)ifname;
+	*parg++ = (char *)bridge;
         *parg = NULL;
         execv(setup_script, args);
         _exit(1);
@@ -609,7 +610,7 @@
 
 static int net_tap_init(const NetdevTapOptions *tap, int *vnet_hdr,
                         const char *setup_script, char *ifname,
-                        size_t ifname_sz, int mq_required, Error **errp)
+                        size_t ifname_sz, const char *bridge, int mq_required, Error **errp)
 {
     Error *err = NULL;
     int fd, vnet_hdr_required;
@@ -631,7 +632,7 @@
     if (setup_script &&
         setup_script[0] != '\0' &&
         strcmp(setup_script, "no") != 0) {
-        launch_script(setup_script, ifname, fd, &err);
+        launch_script(setup_script, ifname, bridge, fd, &err);
         if (err) {
             error_propagate(errp, err);
             close(fd);
@@ -952,7 +953,9 @@
 
         for (i = 0; i < queues; i++) {
             fd = net_tap_init(tap, &vnet_hdr, i >= 1 ? "no" : script,
-                              ifname, sizeof ifname, queues > 1, errp);
+                              ifname, sizeof ifname, 
+			      tap->br != NULL ? tap->br : "bn1",
+			      queues > 1, errp);
             if (fd == -1) {
                 return -1;
             }
