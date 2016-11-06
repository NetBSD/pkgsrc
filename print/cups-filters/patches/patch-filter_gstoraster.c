$NetBSD: patch-filter_gstoraster.c,v 1.1 2016/11/06 11:21:19 leot Exp $

execvpe(3) appeared only on NetBSD 8.0, use execve(3) instead (like
cups-filters-1.11.4).

--- filter/gstoraster.c.orig	2016-10-27 22:50:52.000000000 +0000
+++ filter/gstoraster.c
@@ -502,7 +502,7 @@ gs_spawn (const char *filename,
     }
 
     /* Execute Ghostscript command line ... */
-    execvpe(filename, gsargv, envp);
+    execve(filename, gsargv, envp);
     perror(filename);
     goto out;
   }
