$NetBSD: patch-filter_gstoraster.c,v 1.2 2018/02/27 17:48:20 leot Exp $

execvpe(3) appeared only on NetBSD 8.0, use execve(3) instead (like
cups-filters-1.11.4).

--- filter/gstoraster.c.orig	2018-02-07 22:08:42.000000000 +0000
+++ filter/gstoraster.c
@@ -503,7 +503,7 @@ gs_spawn (const char *filename,
     }
 
     /* Execute Ghostscript command line ... */
-    execvpe(filename, gsargv, envp);
+    execve(filename, gsargv, envp);
     fprintf(stderr, "ERROR: Unable to launch Ghostscript: %s: %s\n", filename, strerror(errno));
     goto out;
   }
