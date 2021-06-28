$NetBSD: patch-src_ucm_ucm__exec.c,v 1.1 2021/06/28 10:10:50 wiz Exp $

Add missing header and remove undefined variable.

--- src/ucm/ucm_exec.c.orig	2021-06-14 10:28:44.000000000 +0000
+++ src/ucm/ucm_exec.c
@@ -32,6 +32,7 @@
 #include <sys/wait.h>
 #include <limits.h>
 #include <dirent.h>
+#include <signal.h>
 
 static pthread_mutex_t fork_lock = PTHREAD_MUTEX_INITIALIZER;
 
@@ -252,7 +253,7 @@ int uc_mgr_exec(const char *prog)
 		signal(SIGINT, SIG_DFL);
 		signal(SIGQUIT, SIG_DFL);
 
-		execve(prog, argv, environ);
+		execve(prog, argv, NULL);
 		exit(1);
 	}
 
