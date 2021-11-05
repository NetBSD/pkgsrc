$NetBSD: patch-pylsp_plugins_flake8__lint.py,v 1.1 2021/11/05 15:58:23 wiz Exp $

Fix unportable interpreter name.
https://github.com/python-lsp/python-lsp-server/pull/111

--- pylsp/plugins/flake8_lint.py.orig	2021-06-25 21:26:52.000000000 +0000
+++ pylsp/plugins/flake8_lint.py
@@ -5,6 +5,7 @@
 import logging
 import os.path
 import re
+import sys
 from pathlib import PurePath
 from subprocess import PIPE, Popen
 
@@ -81,8 +82,8 @@ def run_flake8(flake8_executable, args, 
         cmd.extend(args)
         p = Popen(cmd, stdin=PIPE, stdout=PIPE, stderr=PIPE)  # pylint: disable=consider-using-with
     except IOError:
-        log.debug("Can't execute %s. Trying with 'python -m flake8'", flake8_executable)
-        cmd = ['python', '-m', 'flake8']
+        log.debug("Can't execute %s. Trying with '" + sys.executable + " -m flake8'", flake8_executable)
+        cmd = [sys.executable, '-m', 'flake8']
         cmd.extend(args)
         p = Popen(cmd, stdin=PIPE, stdout=PIPE, stderr=PIPE)  # pylint: disable=consider-using-with
     (stdout, stderr) = p.communicate(document.source.encode())
