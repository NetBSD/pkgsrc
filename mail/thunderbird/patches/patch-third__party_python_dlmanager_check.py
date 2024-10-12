$NetBSD: patch-third__party_python_dlmanager_check.py,v 1.1 2024/10/12 09:07:02 ryoon Exp $

Fix build with Python 3.13.

--- third_party/python/dlmanager/check.py.orig	2024-10-11 13:43:43.746252969 +0000
+++ third_party/python/dlmanager/check.py
@@ -5,7 +5,7 @@ Run flake8 checks and tests.
 
 import os
 import argparse
-import pipes
+import shlex
 import shutil
 import tempfile
 
@@ -23,7 +23,7 @@ def parse_args():
 
 
 def run(cmd, **kwargs):
-    msg = 'Running: |%s|' % ' '.join(pipes.quote(c) for c in cmd)
+    msg = 'Running: |%s|' % ' '.join(shlex.quote(c) for c in cmd)
     if kwargs.get('cwd'):
         msg += ' in %s' % kwargs['cwd']
     print(msg)
