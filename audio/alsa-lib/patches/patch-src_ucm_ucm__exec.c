$NetBSD: patch-src_ucm_ucm__exec.c,v 1.2 2023/11/23 16:15:04 ryoon Exp $

Add missing header and remove undefined variable.

--- src/ucm/ucm_exec.c.orig	2023-05-04 07:16:16.000000000 +0000
+++ src/ucm/ucm_exec.c
@@ -32,6 +32,7 @@
 #include <sys/wait.h>
 #include <limits.h>
 #include <dirent.h>
+#include <signal.h>
 
 #if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <signal.h>
@@ -261,7 +262,7 @@ int uc_mgr_exec(const char *prog)
 		signal(SIGINT, SIG_DFL);
 		signal(SIGQUIT, SIG_DFL);
 
-		execve(prog, argv, environ);
+		execve(prog, argv, NULL);
 		exit(1);
 	}
 
