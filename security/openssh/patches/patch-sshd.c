$NetBSD: patch-sshd.c,v 1.7 2016/03/15 20:54:07 bsiegert Exp $

* Interix support
* Revive tcp_wrappers support.

--- sshd.c.orig	2016-03-09 18:04:48.000000000 +0000
+++ sshd.c
@@ -125,6 +125,13 @@
 #include "version.h"
 #include "ssherr.h"
 
+#ifdef LIBWRAP
+#include <tcpd.h>
+#include <syslog.h>
+int allow_severity;
+int deny_severity;
+#endif /* LIBWRAP */
+
 #ifndef O_NOCTTY
 #define O_NOCTTY	0
 #endif
@@ -236,7 +243,11 @@ int *startup_pipes = NULL;
 int startup_pipe;		/* in child */
 
 /* variables used for privilege separation */
+#ifdef HAVE_INTERIX
+int use_privsep = 0;
+#else
 int use_privsep = -1;
+#endif
 struct monitor *pmonitor = NULL;
 int privsep_is_preauth = 1;
 
@@ -632,7 +643,7 @@ privsep_preauth_child(void)
 	demote_sensitive_data();
 
 	/* Demote the child */
-	if (getuid() == 0 || geteuid() == 0) {
+	if (getuid() == ROOTUID || geteuid() == ROOTUID) {
 		/* Change our root directory */
 		if (chroot(_PATH_PRIVSEP_CHROOT_DIR) == -1)
 			fatal("chroot(\"%s\"): %s", _PATH_PRIVSEP_CHROOT_DIR,
@@ -643,10 +654,15 @@ privsep_preauth_child(void)
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
 
@@ -713,10 +729,17 @@ privsep_preauth(Authctxt *authctxt)
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
@@ -730,7 +753,7 @@ privsep_postauth(Authctxt *authctxt)
 #ifdef DISABLE_FD_PASSING
 	if (1) {
 #else
-	if (authctxt->pw->pw_uid == 0 || options.use_login) {
+	if (authctxt->pw->pw_uid == ROOTUID || options.use_login) {
 #endif
 		/* File descriptor passing is broken or root login */
 		use_privsep = 0;
@@ -1497,8 +1520,10 @@ main(int ac, char **av)
 	av = saved_argv;
 #endif
 
-	if (geteuid() == 0 && setgroups(0, NULL) == -1)
+#ifndef HAVE_INTERIX
+	if (geteuid() == ROOTUID && setgroups(0, NULL) == -1)
 		debug("setgroups(): %.200s", strerror(errno));
+#endif
 
 	/* Ensure that fds 0, 1 and 2 are open or directed to /dev/null */
 	sanitise_stdfd();
@@ -1925,7 +1950,7 @@ main(int ac, char **av)
 		    (st.st_uid != getuid () ||
 		    (st.st_mode & (S_IWGRP|S_IWOTH)) != 0))
 #else
-		if (st.st_uid != 0 || (st.st_mode & (S_IWGRP|S_IWOTH)) != 0)
+		if (st.st_uid != ROOTUID || (st.st_mode & (S_IWGRP|S_IWOTH)) != 0)
 #endif
 			fatal("%s must be owned by root and not group or "
 			    "world-writable.", _PATH_PRIVSEP_CHROOT_DIR);
@@ -1948,8 +1973,10 @@ main(int ac, char **av)
 	 * to create a file, and we can't control the code in every
 	 * module which might be used).
 	 */
+#ifndef HAVE_INTERIX
 	if (setgroups(0, NULL) < 0)
 		debug("setgroups() failed: %.200s", strerror(errno));
+#endif
 
 	if (rexec_flag) {
 		rexec_argv = xcalloc(rexec_argc + 2, sizeof(char *));
@@ -2145,6 +2172,25 @@ main(int ac, char **av)
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
 	/* Log the connection. */
 	laddr = get_local_ipaddr(sock_in);
 	verbose("Connection from %s port %d on %s port %d",
