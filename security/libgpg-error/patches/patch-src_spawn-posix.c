$NetBSD: patch-src_spawn-posix.c,v 1.4 2026/02/03 09:53:23 wiz Exp $

Fix NetBSD.
https://dev.gnupg.org/T8065

--- src/spawn-posix.c.orig	2025-11-19 11:08:27.000000000 +0000
+++ src/spawn-posix.c
@@ -460,9 +460,9 @@ spawn_detached (const char *pgmname, const char *argv[
 
   _gpgrt_pre_syscall ();
   pid = fork ();
-  _gpgrt_post_syscall ();
   if (pid == (pid_t)(-1))
     {
+      _gpgrt_post_syscall ();
       ec = _gpg_err_code_from_syserror ();
       _gpgrt_log_info (_("error forking process: %s\n"), _gpg_strerror (ec));
       xfree (argv);
@@ -486,6 +486,7 @@ spawn_detached (const char *pgmname, const char *argv[
       /*NOTREACHED*/
     }
 
+  _gpgrt_post_syscall ();
   xfree (argv);
   _gpgrt_pre_syscall ();
   if (waitpid (pid, NULL, 0) == -1)
@@ -752,9 +753,9 @@ _gpgrt_process_spawn (const char *pgmname, const char 
 
   _gpgrt_pre_syscall ();
   pid = fork ();
-  _gpgrt_post_syscall ();
   if (pid == (pid_t)(-1))
     {
+      _gpgrt_post_syscall ();
       ec = _gpg_err_code_from_syserror ();
       _gpgrt_log_info (_("error forking process: %s\n"), _gpg_strerror (ec));
       if (fd_in[0] >= 0 && fd_in[0] != 0)
@@ -802,6 +803,7 @@ _gpgrt_process_spawn (const char *pgmname, const char 
       /*NOTREACHED*/
     }
 
+  _gpgrt_post_syscall ();
   xfree (argv);
   process->pid = pid;
 
