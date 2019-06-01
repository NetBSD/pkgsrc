$NetBSD: patch-filter_mupdftoraster.c,v 1.2 2019/06/01 17:39:05 leot Exp $

execvpe(3) appeared only on NetBSD 8.0, use execve(3) instead (like
cups-filters-1.11.4).

--- filter/mupdftoraster.c.orig	2019-05-16 13:02:29.000000000 +0000
+++ filter/mupdftoraster.c
@@ -202,7 +202,7 @@ mutool_spawn (const char *filename,
 
   if ((pid = fork()) == 0) {
     /* Execute mutool command line ... */
-    execvpe(filename, mutoolargv, envp);
+    execve(filename, mutoolargv, envp);
     perror(filename);
     goto out;
   }
