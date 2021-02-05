$NetBSD: patch-priv.c,v 1.1 2021/02/05 13:27:42 nia Exp $

Do not directly pass user input to a printf function.

--- priv.c.orig	2004-02-09 04:37:07.000000000 +0000
+++ priv.c
@@ -370,8 +370,8 @@ main(int argc, char **argv, char **envp)
 	}
 
 	/* All's well so far, get ready to execute the command. */
-	syslog(LOG_INFO, build_log_message(myfullname, argv + 1, realprog,
-	    nflags));
+	syslog(LOG_INFO, "%s",
+	    build_log_message(myfullname, argv + 1, realprog, nflags));
 	envp = lockdown(nflags, realprog, pw, envp);
 	execve(realprog, argv + 1, envp);
 	sverr = errno;
