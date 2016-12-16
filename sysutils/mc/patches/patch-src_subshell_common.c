$NetBSD: patch-src_subshell_common.c,v 1.1 2016/12/16 00:02:28 joerg Exp $

Report error from read since tcsetattr can replace errno.
Recognize /bin/sh as valid shell and don't complain about it.

--- src/subshell/common.c.orig	2016-09-22 18:24:12.000000000 +0000
+++ src/subshell/common.c
@@ -303,6 +303,7 @@ init_subshell_child (const char *pty_nam
 
     case SHELL_ASH_BUSYBOX:
     case SHELL_DASH:
+    case SHELL_SH:
         /* Do we have a custom init file ~/.local/share/mc/ashrc? */
         init_file = mc_config_get_full_path ("ashrc");
 
@@ -496,7 +497,7 @@ static gboolean
 feed_subshell (int how, gboolean fail_on_error)
 {
     fd_set read_set;            /* For 'select' */
-    int bytes;                  /* For the return value from 'read' */
+    int serrno, bytes;                  /* For the return value from 'read' */
     int i;                      /* Loop counter */
 
     struct timeval wtime;       /* Maximum time we wait for the subshell */
@@ -551,15 +552,16 @@ feed_subshell (int how, gboolean fail_on
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
                 tcsetattr (STDOUT_FILENO, TCSANOW, &shell_mode);
-                fprintf (stderr, "read (subshell_pty...): %s\r\n", unix_error_string (errno));
+                fprintf (stderr, "read (subshell_pty...): %s\r\n", unix_error_string (serrno));
                 exit (EXIT_FAILURE);
             }
 
