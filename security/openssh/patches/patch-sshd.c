$NetBSD: patch-sshd.c,v 1.2 2013/12/01 06:11:41 taca Exp $

Interix support

--- sshd.c.orig	2013-07-20 03:21:53.000000000 +0000
+++ sshd.c
@@ -243,7 +243,11 @@ int *startup_pipes = NULL;
 int startup_pipe;		/* in child */
 
 /* variables used for privilege separation */
+#ifdef HAVE_INTERIX
 int use_privsep = -1;
+#else
+int use_privsep = 0;
+#endif
 struct monitor *pmonitor = NULL;
 int privsep_is_preauth = 1;
 
@@ -631,10 +635,15 @@ privsep_preauth_child(void)
 	/* XXX not ready, too heavy after chroot */
 	do_setusercontext(privsep_pw);
 #else
+#ifdef HAVE_INTERIX
+	if (setuser(privsep_pw->pw_name, NULL, SU_COMPLETE))
+		fatal("setuser: %.100s", strerror(errno));
+#else
 	gidset[0] = privsep_pw->pw_gid;
 	if (setgroups(1, gidset) < 0)
 		fatal("setgroups: %.100s", strerror(errno));
 	permanently_set_uid(privsep_pw);
+#endif /* HAVE_INTERIX */
 #endif
 }
 
@@ -696,7 +705,7 @@ privsep_preauth(Authctxt *authctxt)
 		set_log_handler(mm_log_handler, pmonitor);
 
 		/* Demote the child */
-		if (getuid() == 0 || geteuid() == 0)
+		if (getuid() == ROOTUID || geteuid() == ROOTUID)
 			privsep_preauth_child();
 		setproctitle("%s", "[net]");
 		if (box != NULL)
@@ -714,7 +723,7 @@ privsep_postauth(Authctxt *authctxt)
 #ifdef DISABLE_FD_PASSING
 	if (1) {
 #else
-	if (authctxt->pw->pw_uid == 0 || options.use_login) {
+	if (authctxt->pw->pw_uid == ROOTUID || options.use_login) {
 #endif
 		/* File descriptor passing is broken or root login */
 		use_privsep = 0;
@@ -1390,8 +1399,10 @@ main(int ac, char **av)
 	av = saved_argv;
 #endif
 
-	if (geteuid() == 0 && setgroups(0, NULL) == -1)
+#ifndef HAVE_INTERIX
+	if (geteuid() == ROOTUID && setgroups(0, NULL) == -1)
 		debug("setgroups(): %.200s", strerror(errno));
+#endif
 
 	/* Ensure that fds 0, 1 and 2 are open or directed to /dev/null */
 	sanitise_stdfd();
@@ -1790,7 +1801,7 @@ main(int ac, char **av)
 		    (st.st_uid != getuid () ||
 		    (st.st_mode & (S_IWGRP|S_IWOTH)) != 0))
 #else
-		if (st.st_uid != 0 || (st.st_mode & (S_IWGRP|S_IWOTH)) != 0)
+		if (st.st_uid != ROOTUID || (st.st_mode & (S_IWGRP|S_IWOTH)) != 0)
 #endif
 			fatal("%s must be owned by root and not group or "
 			    "world-writable.", _PATH_PRIVSEP_CHROOT_DIR);
@@ -1813,8 +1824,10 @@ main(int ac, char **av)
 	 * to create a file, and we can't control the code in every
 	 * module which might be used).
 	 */
+#ifndef HAVE_INTERIX
 	if (setgroups(0, NULL) < 0)
 		debug("setgroups() failed: %.200s", strerror(errno));
+#endif
 
 	if (rexec_flag) {
 		rexec_argv = xcalloc(rexec_argc + 2, sizeof(char *));
