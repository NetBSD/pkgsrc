$NetBSD: patch-cvs2svn__lib_rcs__revision__manager.py,v 1.1 2026/10/30 21:49:08 cheusov Exp $

"co -V" is more portable than "co --version"

--- cvs2svn_lib/rcs_revision_manager.py.orig	2026-10-26 10:55:52.563612558 +0000
+++ cvs2svn_lib/rcs_revision_manager.py
@@ -29,7 +29,7 @@ class RCSRevisionReader(AbstractRCSRevis
   def __init__(self, co_executable):
     self.co_executable = co_executable
     try:
-      check_command_runs([self.co_executable, '--version'], self.co_executable)
+      check_command_runs([self.co_executable, '-V'], self.co_executable)
     except CommandFailedException, e:
       raise FatalError('%s\n'
                        'Please check that co is installed and in your PATH\n'
