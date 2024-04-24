$NetBSD: patch-libguile_posix.c,v 1.2 2024/04/24 06:47:55 wiz Exp $

Wrap dprintf() in HAVE_DPRINTF.

--- libguile/posix.c.orig	2023-01-23 10:47:35.000000000 +0000
+++ libguile/posix.c
@@ -1573,8 +1573,11 @@ piped_process (pid_t *pid, SCM prog, SCM
       default:    /* ENOENT, etc. */
         /* Report the error on the console (before switching to
            'posix_spawn', the child process would do exactly that.)  */
+#ifdef HAVE_DPRINTF
         dprintf (err, "In execvp of %s: %s\n", exec_file,
                  strerror (errno_save));
+#endif
+	break;
       }
 
   free (exec_file);
