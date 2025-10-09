$NetBSD: patch-langkit_libmanage.py,v 1.1 2025/10/09 11:25:49 wiz Exp $

Transition uses of the Python pipes module to shlex
"pipes" was removed from Python 3.13.
https://github.com/AdaCore/langkit/commit/dbacb9b5545315e7045ef082dba99d2c96ed1356

--- langkit/libmanage.py.orig	2024-09-17 09:18:15.000000000 +0000
+++ langkit/libmanage.py
@@ -9,7 +9,7 @@ import json
 import os
 from os import path
 import pdb
-import pipes
+import shlex
 import shutil
 import subprocess
 import sys
@@ -1581,9 +1581,7 @@ class ManageScript(abc.ABC):
         :param argv: Arguments for the command to log.
         """
         if self.verbosity.debug:
-            printcol('Executing: {}'.format(
-                ' '.join(pipes.quote(arg) for arg in argv)
-            ), Colors.CYAN)
+            printcol('Executing: {}'.format(shlex.join(argv)), Colors.CYAN)
 
     def log_info(self, msg: str, color: str) -> None:
         """
