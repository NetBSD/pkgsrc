$NetBSD: patch-lib_Proc_Daemon.pm,v 1.1 2013/12/20 15:43:51 wen Exp $
Fix CVE-2013-7135.
--- lib/Proc/Daemon.pm.orig	2013-12-20 23:35:20.000000000 +0000
+++ lib/Proc/Daemon.pm
@@ -152,7 +152,7 @@ sub Init {
             die "Can't <chdir> to $self->{work_dir}: $!" unless chdir $self->{work_dir};
 
             # Clear the file creation mask.
-            umask 0;
+            umask 066;
 
             # Detach the child from the terminal (no controlling tty), make it the
             # session-leader and the process-group-leader of a new process group.
@@ -633,4 +633,4 @@ sub get_pid_by_proc_table_attr {
     return $pid;
 }
 
-1;
\ No newline at end of file
+1;
