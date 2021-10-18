$NetBSD: patch-src_subshell_common.c,v 1.3 2021/10/18 13:36:45 nia Exp $

Report error from read since tcsetattr can replace errno.
Recognize /bin/sh as valid shell and don't complain about it.

--- src/subshell/common.c.orig	2021-08-01 16:45:58.000000000 +0000
+++ src/subshell/common.c
@@ -345,6 +345,7 @@ init_subshell_child (const char *pty_nam
 
     case SHELL_ASH_BUSYBOX:
     case SHELL_DASH:
+    case SHELL_SH:
         /* Do we have a custom init file ~/.local/share/mc/ashrc? */
         init_file = mc_config_get_full_path (MC_ASHRC_FILE);
 
@@ -740,7 +741,7 @@ static gboolean
 feed_subshell (int how, gboolean fail_on_error)
 {
     fd_set read_set;            /* For 'select' */
-    int bytes;                  /* For the return value from 'read' */
+    int serrno, bytes;                  /* For the return value from 'read' */
     int i;                      /* Loop counter */
 
     struct timeval wtime;       /* Maximum time we wait for the subshell */
@@ -774,6 +775,7 @@ feed_subshell (int how, gboolean fail_on
 
         if (select (maxfdp + 1, &read_set, NULL, NULL, wptr) == -1)
         {
+            serrno = errno;
             /* Despite using SA_RESTART, we still have to check for this */
             if (errno == EINTR)
             {
@@ -784,7 +786,7 @@ feed_subshell (int how, gboolean fail_on
             }
             tcsetattr (STDOUT_FILENO, TCSANOW, &shell_mode);
             fprintf (stderr, "select (FD_SETSIZE, &read_set...): %s\r\n",
-                     unix_error_string (errno));
+                     unix_error_string (serrno));
             exit (EXIT_FAILURE);
         }
 
@@ -797,19 +799,20 @@ feed_subshell (int how, gboolean fail_on
             /* for (i=0; i<5; ++i)  * FIXME -- experimental */
         {
             bytes = read (mc_global.tty.subshell_pty, pty_buffer, sizeof (pty_buffer));
+            serrno = errno;
 
             /* The subshell has died */
-            if (bytes == -1 && errno == EIO && !subshell_alive)
+            if (((bytes == -1 && errno == EIO) || bytes == 0) && !subshell_alive)
                 return FALSE;
 
-            if (bytes <= 0)
+            if (bytes < 0)
             {
 #ifdef PTY_ZEROREAD
                 /* On IBM i, read(1) can return 0 for a non-closed fd */
                 continue;
 #else
                 tcsetattr (STDOUT_FILENO, TCSANOW, &shell_mode);
-                fprintf (stderr, "read (subshell_pty...): %s\r\n", unix_error_string (errno));
+                fprintf (stderr, "read (subshell_pty...): %s\r\n", unix_error_string (serrno));
                 exit (EXIT_FAILURE);
 #endif
             }
@@ -827,9 +830,10 @@ feed_subshell (int how, gboolean fail_on
             bytes = read (subshell_pipe[READ], subshell_cwd, sizeof (subshell_cwd));
             if (bytes <= 0)
             {
+                serrno = errno;
                 tcsetattr (STDOUT_FILENO, TCSANOW, &shell_mode);
                 fprintf (stderr, "read (subshell_pipe[READ]...): %s\r\n",
-                         unix_error_string (errno));
+                         unix_error_string (serrno));
                 exit (EXIT_FAILURE);
             }
 
@@ -854,9 +858,10 @@ feed_subshell (int how, gboolean fail_on
             bytes = read (STDIN_FILENO, pty_buffer, sizeof (pty_buffer));
             if (bytes <= 0)
             {
+                serrno = errno;
                 tcsetattr (STDOUT_FILENO, TCSANOW, &shell_mode);
                 fprintf (stderr,
-                         "read (STDIN_FILENO, pty_buffer...): %s\r\n", unix_error_string (errno));
+                         "read (STDIN_FILENO, pty_buffer...): %s\r\n", unix_error_string (serrno));
                 exit (EXIT_FAILURE);
             }
 
