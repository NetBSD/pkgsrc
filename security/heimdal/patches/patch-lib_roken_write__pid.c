$NetBSD: patch-lib_roken_write__pid.c,v 1.1 2026/08/10 14:05:14 adam Exp $

Fix conflict with pidfile_path from NetBSD 12.

--- lib/roken/write_pid.c.orig	2026-08-10 13:59:32.827558106 +0000
+++ lib/roken/write_pid.c
@@ -80,14 +80,14 @@ pid_file_delete(char **filename)
     }
 }
 
-static char *pidfile_path;
+static char *roken_pidfile_path;
 static pid_t pidfile_pid;
 
 static void
 pidfile_cleanup(void)
 {
-    if (pidfile_path != NULL && pidfile_pid == getpid())
-	pid_file_delete(&pidfile_path);
+    if (roken_pidfile_path != NULL && pidfile_pid == getpid())
+	pid_file_delete(&roken_pidfile_path);
 }
 
 ROKEN_LIB_FUNCTION void ROKEN_LIB_CALL
@@ -102,17 +102,17 @@ rk_pidfile(const char *bname)
     pidfile(bname);
 #endif
 
-    if (pidfile_path != NULL)
+    if (roken_pidfile_path != NULL)
 	return;
     if (bname == NULL)
 	bname = getprogname();
-    pidfile_path = pid_file_write(bname);
+    roken_pidfile_path = pid_file_write(bname);
     pidfile_pid = getpid();
 #if defined(HAVE_ATEXIT)
-    if (pidfile_path != NULL)
+    if (roken_pidfile_path != NULL)
         atexit(pidfile_cleanup);
 #elif defined(HAVE_ON_EXIT)
-    if (pidfile_path != NULL)
+    if (roken_pidfile_path != NULL)
         on_exit(pidfile_cleanup);
 #endif
 }
