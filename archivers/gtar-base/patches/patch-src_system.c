$NetBSD: patch-src_system.c,v 1.2 2015/01/26 12:41:53 jperkin Exp $

Do not call into gettext which may not be async-signal-safe in between fork
and exec.  Fixes crashes on OSX when LC_ALL is unset.

Thanks to http://article.gmane.org/gmane.os.macosx.fink.devel/21882 for the
diagnosis and fix.

--- src/system.c.orig	2014-02-25 22:26:02.000000000 +0000
+++ src/system.c
@@ -344,7 +344,7 @@ sys_child_open_for_compress (void)
 
   /* The new born child tar is here!  */
 
-  set_program_name (_("tar (child)"));
+  set_program_name (N_("tar (child)"));
   signal (SIGPIPE, SIG_DFL);
 
   xdup2 (parent_pipe[PREAD], STDIN_FILENO);
@@ -389,7 +389,7 @@ sys_child_open_for_compress (void)
     {
       /* The newborn grandchild tar is here!  Launch the compressor.  */
 
-      set_program_name (_("tar (grandchild)"));
+      set_program_name (N_("tar (grandchild)"));
 
       xdup2 (child_pipe[PWRITE], STDOUT_FILENO);
       xclose (child_pipe[PREAD]);
@@ -523,7 +523,7 @@ sys_child_open_for_uncompress (void)
 
   /* The newborn child tar is here!  */
 
-  set_program_name (_("tar (child)"));
+  set_program_name (N_("tar (child)"));
   signal (SIGPIPE, SIG_DFL);
 
   xdup2 (parent_pipe[PWRITE], STDOUT_FILENO);
@@ -558,7 +558,7 @@ sys_child_open_for_uncompress (void)
     {
       /* The newborn grandchild tar is here!  Launch the uncompressor.  */
 
-      set_program_name (_("tar (grandchild)"));
+      set_program_name (N_("tar (grandchild)"));
 
       xdup2 (child_pipe[PREAD], STDIN_FILENO);
       xclose (child_pipe[PWRITE]);
