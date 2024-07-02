$NetBSD: patch-sshd-session.c,v 1.1.2.2 2024/07/02 06:32:11 bsiegert Exp $

Apple change based on
https://github.com/macports/macports-ports/blob/master/net/openssh/files/patch-sshd.c-apple-sandbox-named-external.diff

--- sshd-session.c.orig	2024-07-01 08:27:04.662426784 +0000
+++ sshd-session.c
@@ -376,10 +383,17 @@ privsep_preauth(struct ssh *ssh)
 		/* Arrange for logging to be sent to the monitor */
 		set_log_handler(mm_log_handler, pmonitor);
 
+#ifdef  __APPLE_SANDBOX_NAMED_EXTERNAL__
+		/* We need to do this before we chroot() so we can read sshd.sb */
+		if (box != NULL)
+			ssh_sandbox_child(box);
+#endif
 		privsep_preauth_child();
 		setproctitle("%s", "[net]");
+#ifndef __APPLE_SANDBOX_NAMED_EXTERNAL__
 		if (box != NULL)
 			ssh_sandbox_child(box);
+#endif
 
 		return 0;
 	}
