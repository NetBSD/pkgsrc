$NetBSD: patch-priv.c,v 1.2 2021/02/16 09:42:06 kim Exp $

Use setusercontext(3), which is needed for per-user tmp to work.

Do not directly pass user input to a printf function.

--- priv.c.orig	2004-02-09 04:37:07.000000000 +0000
+++ priv.c
@@ -318,6 +318,17 @@ main(int argc, char **argv, char **envp)
 	}
 
 	/* Set up the permissions */
+#ifdef HAVE_LOGIN_CAP_H
+	if (setusercontext(NULL, pw, pw->pw_uid, LOGIN_SETGROUP |
+	    LOGIN_SETPRIORITY | LOGIN_SETRESOURCES | LOGIN_SETUMASK |
+	    LOGIN_SETUSER) != 0) {
+		sverr = errno;
+		syslog(LOG_NOTICE, "%s: not ok: setusercontext failed: %m",
+		    myfullname);
+		errno = sverr;
+		err(EXIT_VAL, "setusercontext failed");
+	}
+#else
 	if (setgid(pw->pw_gid) < 0) {
 		sverr = errno;
 		syslog(LOG_NOTICE, "%s: not ok: setgid failed: %m", myfullname);
@@ -337,6 +348,7 @@ main(int argc, char **argv, char **envp)
 		errno = sverr;
 		err(EXIT_VAL, "setuid failed");
 	}
+#endif
 
 	/* Check for sym-link */
 	if (!(nflags & F_SYMLINK)) {
@@ -370,8 +382,8 @@ main(int argc, char **argv, char **envp)
 	}
 
 	/* All's well so far, get ready to execute the command. */
-	syslog(LOG_INFO, build_log_message(myfullname, argv + 1, realprog,
-	    nflags));
+	syslog(LOG_INFO, "%s",
+	    build_log_message(myfullname, argv + 1, realprog, nflags));
 	envp = lockdown(nflags, realprog, pw, envp);
 	execve(realprog, argv + 1, envp);
 	sverr = errno;
