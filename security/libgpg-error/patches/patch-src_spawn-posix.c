$NetBSD: patch-src_spawn-posix.c,v 1.2 2024/09/29 18:58:37 schmonz Exp $

Avoid nonportable environ global.
Via <https://dev.gnupg.org/T7169#190989>

--- src/spawn-posix.c.orig	2024-06-19 07:33:41.000000000 +0000
+++ src/spawn-posix.c
@@ -341,9 +341,6 @@ my_exec (const char *pgmname, const char
   /* Close all other files.  */
   _gpgrt_close_all_fds (3, act->except_fds);
 
-  if (act->environ)
-    environ = act->environ;
-
   if (act->atfork)
     act->atfork (act->atfork_arg);
 
@@ -351,7 +348,11 @@ my_exec (const char *pgmname, const char
   if (pgmname == NULL)
     return 0;
 
-  execv (pgmname, (char *const *)argv);
+  if (act->environ)
+    execve (pgmname, (char *const *)argv, act->environ);
+  else
+    execv (pgmname, (char *const *)argv);
+
   /* No way to print anything, as we have may have closed all streams. */
   _exit (127);
   return -1;
