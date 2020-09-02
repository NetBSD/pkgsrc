$NetBSD: patch-setup.py,v 1.1 2020/09/02 21:42:48 wiz Exp $

Compatibility with setuptools>=50.0.0
https://github.com/pypa/setuptools/issues/2355#issuecomment-685159580

--- setup.py.orig	2020-02-12 12:29:41.000000000 +0000
+++ setup.py
@@ -446,10 +446,7 @@ class NameSpacePackager(object):
             sys.exit(1)
 
     def check(self):
-        try:
-            from pip.exceptions import InstallationError
-        except ImportError:
-            return
+        InstallationError = Exception
         # arg is either develop (pip install -e) or install
         if self.command not in ['install', 'develop']:
             return
