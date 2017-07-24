$NetBSD: patch-console_daemon_utils.c,v 1.1 2017/07/24 11:37:49 maya Exp $

Avoid GNU extension %m in printf

--- console/daemon/utils.c.orig	2014-09-02 06:22:57.000000000 +0000
+++ console/daemon/utils.c
@@ -113,13 +113,13 @@ bool xen_setup(void)
 	xs = xs_daemon_open();
 	if (xs == NULL) {
 		dolog(LOG_ERR,
-		      "Failed to contact xenstore (%m).  Is it running?");
+		      "Failed to contact xenstore (%s).  Is it running?", strerror(errno));
 		goto out;
 	}
 
 	xc = xc_interface_open(0,0,0);
 	if (!xc) {
-		dolog(LOG_ERR, "Failed to contact hypervisor (%m)");
+		dolog(LOG_ERR, "Failed to contact hypervisor (%s)", strerror(errno));
 		goto out;
 	}
 
