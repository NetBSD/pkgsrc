$NetBSD: patch-langkit_libmanage.py,v 1.2 2025/10/09 15:18:55 dkazankov Exp $

Transition uses of the Python pipes module to shlex
"pipes" was removed from Python 3.13.
https://github.com/AdaCore/langkit/commit/dbacb9b5545315e7045ef082dba99d2c96ed1356

--- langkit/libmanage.py.orig	2024-12-10 12:23:59.000000000 +0200
+++ langkit/libmanage.py
@@ -9,7 +9,7 @@
 import os
 from os import path
 import pdb
-import pipes
+import shlex
 import shutil
 import subprocess
 import sys
@@ -1582,9 +1582,7 @@
         :param argv: Arguments for the command to log.
         """
         if self.verbosity.debug:
-            printcol('Executing: {}'.format(
-                ' '.join(pipes.quote(arg) for arg in argv)
-            ), Colors.CYAN)
+            printcol('Executing: {}'.format(shlex.join(argv)), Colors.CYAN)
 
     def log_info(self, msg: str, color: str) -> None:
         """
