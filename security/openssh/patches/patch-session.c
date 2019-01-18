$NetBSD: patch-session.c,v 1.9 2019/01/18 20:13:37 tnn Exp $

* Interix support.

--- session.c.orig	2018-10-17 00:01:20.000000000 +0000
+++ session.c
@@ -959,7 +959,7 @@ read_etc_default_login(char ***env, u_in
 	if (tmpenv == NULL)
 		return;
 
-	if (uid == 0)
+	if (uid == ROOTUID)
 		var = child_get_env(tmpenv, "SUPATH");
 	else
 		var = child_get_env(tmpenv, "PATH");
@@ -1077,7 +1077,7 @@ do_setup_env(struct ssh *ssh, Session *s
 #  endif /* HAVE_ETC_DEFAULT_LOGIN */
 	if (path == NULL || *path == '\0') {
 		child_set_env(&env, &envsize, "PATH",
-		    s->pw->pw_uid == 0 ?  SUPERUSER_PATH : _PATH_STDPATH);
+		    s->pw->pw_uid == ROOTUID ?  SUPERUSER_PATH : _PATH_STDPATH);
 	}
 # endif /* HAVE_CYGWIN */
 #endif /* HAVE_LOGIN_CAP */
@@ -1209,6 +1209,17 @@ do_setup_env(struct ssh *ssh, Session *s
 		child_set_env(&env, &envsize, "SSH_ORIGINAL_COMMAND",
 		    original_command);
 
+#ifdef HAVE_INTERIX
+	{
+		/* copy standard Windows environment, then apply changes */
+		env_t *winenv = env_login(pw);
+		env_putarray(winenv, env, ENV_OVERRIDE);
+
+		/* swap over to altered environment as a traditional array */
+		env = env_array(winenv);
+	}
+#endif
+
 	if (debug_flag) {
 		/* dump the environment */
 		fprintf(stderr, "Environment:\n");
@@ -1400,11 +1411,13 @@ do_setusercontext(struct passwd *pw)
 			perror("setgid");
 			exit(1);
 		}
+# if !defined(HAVE_INTERIX)
 		/* Initialize the group list. */
 		if (initgroups(pw->pw_name, pw->pw_gid) < 0) {
 			perror("initgroups");
 			exit(1);
 		}
+# endif /* !HAVE_INTERIX */
 		endgrent();
 #endif
 
@@ -2275,7 +2288,7 @@ session_pty_cleanup2(Session *s)
 		record_logout(s->pid, s->tty, s->pw->pw_name);
 
 	/* Release the pseudo-tty. */
-	if (getuid() == 0)
+	if (getuid() == ROOTUID)
 		pty_release(s->tty);
 
 	/*
