$NetBSD: patch-filter_mupdftoraster.c,v 1.1 2016/11/06 11:21:19 leot Exp $

execvpe(3) appeared only on NetBSD 8.0, use execve(3) instead (like
cups-filters-1.11.4).

--- filter/mupdftoraster.c.orig	2016-10-27 22:50:52.000000000 +0000
+++ filter/mupdftoraster.c
@@ -215,7 +215,7 @@ mutool_spawn (const char *filename,
 
   if ((pid = fork()) == 0) {
     /* Execute Mutool command line ... */
-    execvpe(filename, mutoolargv, envp);
+    execve(filename, mutoolargv, envp);
     perror(filename);
     goto out;
   }
