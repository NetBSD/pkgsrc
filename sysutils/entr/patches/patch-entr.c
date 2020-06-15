$NetBSD: patch-entr.c,v 1.1 2020/06/15 16:55:07 leot Exp $

Always wait childs to avoid zombies.

--- entr.c.orig	2020-04-20 16:02:05.000000000 +0000
+++ entr.c
@@ -254,8 +254,8 @@ void
 proc_exit(int sig) {
 	int status;
 
+	xwaitpid(child_pid, &status, 0);
 	if ((oneshot_opt == 1) && (terminating == 0)) {
-		xwaitpid(child_pid, &status, 0);
 		if ((shell_opt == 1) && (restart_opt == 0)) {
 			fprintf(stdout, "%s returned exit code %d\n",
 			    basename(getenv("SHELL")), WEXITSTATUS(status));
