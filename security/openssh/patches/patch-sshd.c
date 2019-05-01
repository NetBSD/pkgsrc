$NetBSD: patch-sshd.c,v 1.11 2019/05/01 17:59:56 maya Exp $

--- sshd.c.orig	2019-04-17 22:52:57.000000000 +0000
+++ sshd.c
@@ -123,6 +123,13 @@
 #include "version.h"
 #include "ssherr.h"
 
+#ifdef LIBWRAP
+#include <tcpd.h>
+#include <syslog.h>
+int allow_severity;
+int deny_severity;
+#endif /* LIBWRAP */
+
 /* Re-exec fds */
 #define REEXEC_DEVCRYPTO_RESERVED_FD	(STDERR_FILENO + 1)
 #define REEXEC_STARTUP_PIPE_FD		(STDERR_FILENO + 2)
@@ -534,10 +541,17 @@ privsep_preauth(struct ssh *ssh)
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
@@ -2053,6 +2067,25 @@ main(int ac, char **av)
 	audit_connection_from(remote_ip, remote_port);
 #endif
 
+#ifdef LIBWRAP
+	allow_severity = options.log_facility|LOG_INFO;
+	deny_severity = options.log_facility|LOG_WARNING;
+	/* Check whether logins are denied from this host. */
+	if (ssh_packet_connection_is_on_socket(ssh)) {
+		struct request_info req;
+
+		request_init(&req, RQ_DAEMON, __progname, RQ_FILE, sock_in, 0);
+		fromhost(&req);
+
+		if (!hosts_access(&req)) {
+			debug("Connection refused by tcp wrapper");
+			refuse(&req);
+			/* NOTREACHED */
+			fatal("libwrap refuse returns");
+		}
+	}
+#endif /* LIBWRAP */
+
 	rdomain = ssh_packet_rdomain_in(ssh);
 
 	/* Log the connection. */
