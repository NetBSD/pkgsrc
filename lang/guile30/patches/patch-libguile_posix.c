$NetBSD: patch-libguile_posix.c,v 1.1 2024/04/23 16:34:09 jperkin Exp $

Wrap dprintf() in HAVE_DPRINTF.

--- libguile/posix.c.orig	2024-04-23 15:53:58.536124795 +0000
+++ libguile/posix.c
@@ -1573,8 +1573,10 @@ piped_process (pid_t *pid, SCM prog, SCM
       default:    /* ENOENT, etc. */
         /* Report the error on the console (before switching to
            'posix_spawn', the child process would do exactly that.)  */
+#ifdef HAVE_DPRINTF
         dprintf (err, "In execvp of %s: %s\n", exec_file,
                  strerror (errno_save));
+#endif
       }
 
   free (exec_file);
