$NetBSD: patch-console_daemon_utils.c,v 1.1.1.1 2016/07/04 07:30:51 jnemeth Exp $

--- console/daemon/utils.c.orig	2015-06-22 13:41:35.000000000 +0000
+++ console/daemon/utils.c
@@ -113,13 +113,15 @@ bool xen_setup(void)
 	xs = xs_daemon_open();
 	if (xs == NULL) {
 		dolog(LOG_ERR,
-		      "Failed to contact xenstore (%m).  Is it running?");
+		      "Failed to contact xenstore (%s).  Is it running?",
+		      strerror(errno));
 		goto out;
 	}
 
 	xc = xc_interface_open(0,0,0);
 	if (!xc) {
-		dolog(LOG_ERR, "Failed to contact hypervisor (%m)");
+		dolog(LOG_ERR, "Failed to contact hypervisor (%s)",
+		      strerror(errno));
 		goto out;
 	}
 
