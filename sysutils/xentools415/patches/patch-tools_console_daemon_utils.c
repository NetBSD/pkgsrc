$NetBSD: patch-tools_console_daemon_utils.c,v 1.1 2021/04/18 12:31:26 bouyer Exp $

--- tools/console/daemon/utils.c.orig	2020-12-08 15:28:31.000000000 +0100
+++ tools/console/daemon/utils.c	2020-12-09 16:22:49.947276738 +0100
@@ -107,13 +107,15 @@
 	xs = xs_open(0);
 	if (xs == NULL) {
 		dolog(LOG_ERR,
-		      "Failed to contact xenstore (%m).  Is it running?");
+		      "Failed to contact xenstore (%s).  Is it running?",
+			  strerror(errno));
 		goto out;
 	}
 
 	xc = xc_interface_open(0,0,0);
 	if (!xc) {
-		dolog(LOG_ERR, "Failed to contact hypervisor (%m)");
+		dolog(LOG_ERR, "Failed to contact hypervisor (%s)",
+		    strerror(errno));
 		goto out;
 	}
 
