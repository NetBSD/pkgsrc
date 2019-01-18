$NetBSD: patch-sshd.c,v 1.10 2019/01/18 20:13:37 tnn Exp $

* Interix support
* Revive tcp_wrappers support.

--- sshd.c.orig	2018-10-17 00:01:20.000000000 +0000
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
@@ -225,7 +232,11 @@ int *startup_pipes = NULL;
 int startup_pipe;		/* in child */
 
 /* variables used for privilege separation */
+#ifdef HAVE_INTERIX
+int use_privsep = 0;
+#else
 int use_privsep = -1;
+#endif
 struct monitor *pmonitor = NULL;
 int privsep_is_preauth = 1;
 static int privsep_chroot = 1;
@@ -556,10 +567,15 @@ privsep_preauth_child(void)
 		/* Drop our privileges */
 		debug3("privsep user:group %u:%u", (u_int)privsep_pw->pw_uid,
 		    (u_int)privsep_pw->pw_gid);
+#ifdef HAVE_INTERIX
+	if (setuser(privsep_pw->pw_name, NULL, SU_COMPLETE))
+		fatal("setuser: %.100s", strerror(errno));
+#else
 		gidset[0] = privsep_pw->pw_gid;
 		if (setgroups(1, gidset) < 0)
 			fatal("setgroups: %.100s", strerror(errno));
 		permanently_set_uid(privsep_pw);
+#endif /* HAVE_INTERIX */
 	}
 }
 
@@ -623,10 +639,17 @@ privsep_preauth(Authctxt *authctxt)
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
@@ -638,7 +661,7 @@ privsep_postauth(Authctxt *authctxt)
 #ifdef DISABLE_FD_PASSING
 	if (1) {
 #else
-	if (authctxt->pw->pw_uid == 0) {
+	if (authctxt->pw->pw_uid == ROOTUID) {
 #endif
 		/* File descriptor passing is broken or root login */
 		use_privsep = 0;
@@ -1504,8 +1527,10 @@ main(int ac, char **av)
 	av = saved_argv;
 #endif
 
-	if (geteuid() == 0 && setgroups(0, NULL) == -1)
+#ifndef HAVE_INTERIX
+	if (geteuid() == ROOTUID && setgroups(0, NULL) == -1)
 		debug("setgroups(): %.200s", strerror(errno));
+#endif
 
 	/* Ensure that fds 0, 1 and 2 are open or directed to /dev/null */
 	sanitise_stdfd();
@@ -1730,7 +1755,7 @@ main(int ac, char **av)
 	);
 
 	/* Store privilege separation user for later use if required. */
-	privsep_chroot = use_privsep && (getuid() == 0 || geteuid() == 0);
+	privsep_chroot = use_privsep && (getuid() == ROOTUID || geteuid() == ROOTUID);
 	if ((privsep_pw = getpwnam(SSH_PRIVSEP_USER)) == NULL) {
 		if (privsep_chroot || options.kerberos_authentication)
 			fatal("Privilege separation user %s does not exist",
@@ -1871,7 +1896,7 @@ main(int ac, char **av)
 		    (st.st_uid != getuid () ||
 		    (st.st_mode & (S_IWGRP|S_IWOTH)) != 0))
 #else
-		if (st.st_uid != 0 || (st.st_mode & (S_IWGRP|S_IWOTH)) != 0)
+		if (st.st_uid != ROOTUID || (st.st_mode & (S_IWGRP|S_IWOTH)) != 0)
 #endif
 			fatal("%s must be owned by root and not group or "
 			    "world-writable.", _PATH_PRIVSEP_CHROOT_DIR);
@@ -1899,8 +1924,10 @@ main(int ac, char **av)
 	 * to create a file, and we can't control the code in every
 	 * module which might be used).
 	 */
+#ifndef HAVE_INTERIX
 	if (setgroups(0, NULL) < 0)
 		debug("setgroups() failed: %.200s", strerror(errno));
+#endif
 
 	if (rexec_flag) {
 		if (rexec_argc < 0)
@@ -2093,6 +2120,25 @@ main(int ac, char **av)
 	audit_connection_from(remote_ip, remote_port);
 #endif
 
+#ifdef LIBWRAP
+	allow_severity = options.log_facility|LOG_INFO;
+	deny_severity = options.log_facility|LOG_WARNING;
+	/* Check whether logins are denied from this host. */
+	if (packet_connection_is_on_socket()) {
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
