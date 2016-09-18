$NetBSD: patch-session.c,v 1.7 2016/09/18 17:30:11 taca Exp $

* Interix support.

--- session.c.orig	2016-07-27 22:54:27.000000000 +0000
+++ session.c
@@ -1120,7 +1120,7 @@ read_etc_default_login(char ***env, u_in
 	if (tmpenv == NULL)
 		return;
 
-	if (uid == 0)
+	if (uid == ROOTUID)
 		var = child_get_env(tmpenv, "SUPATH");
 	else
 		var = child_get_env(tmpenv, "PATH");
@@ -1230,7 +1230,7 @@ do_setup_env(Session *s, const char *she
 #  endif /* HAVE_ETC_DEFAULT_LOGIN */
 		if (path == NULL || *path == '\0') {
 			child_set_env(&env, &envsize, "PATH",
-			    s->pw->pw_uid == 0 ?
+			    s->pw->pw_uid == ROOTUID ?
 				SUPERUSER_PATH : _PATH_STDPATH);
 		}
 # endif /* HAVE_CYGWIN */
@@ -1346,6 +1346,18 @@ do_setup_env(Session *s, const char *she
 		    strcmp(pw->pw_dir, "/") ? pw->pw_dir : "");
 		read_environment_file(&env, &envsize, buf);
 	}
+
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
@@ -1537,11 +1549,13 @@ do_setusercontext(struct passwd *pw)
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
 
@@ -2388,7 +2402,7 @@ session_pty_cleanup2(Session *s)
 		record_logout(s->pid, s->tty, s->pw->pw_name);
 
 	/* Release the pseudo-tty. */
-	if (getuid() == 0)
+	if (getuid() == ROOTUID)
 		pty_release(s->tty);
 
 	/*
