$NetBSD: patch-execute_cmd.c,v 1.1 2013/02/12 23:31:41 tcort Exp $

Allow bash to compile with JOB_CONTROL disabled.

http://ftp.gnu.org/gnu/bash/bash-4.2-patches/bash42-018

--- execute_cmd.c.orig	Wed Feb  9 22:32:25 2011
+++ execute_cmd.c	Tue Feb 12 11:48:00 2013
@@ -2196,6 +2196,7 @@
   if (ignore_return && cmd)
     cmd->flags |= CMD_IGNORE_RETURN;
 
+#if defined (JOB_CONTROL)
   lastpipe_flag = 0;
   begin_unwind_frame ("lastpipe-exec");
   lstdin = -1;
@@ -2219,11 +2220,14 @@
     }	  
   if (prev >= 0)
     add_unwind_protect (close, prev);
+#endif
 
   exec_result = execute_command_internal (cmd, asynchronous, prev, pipe_out, fds_to_close);
 
+#if defined (JOB_CONTROL)
   if (lstdin > 0)
     restore_stdin (lstdin);
+#endif
 
   if (prev >= 0)
     close (prev);
