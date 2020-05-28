$NetBSD: patch-.._.._python_mozbuild_mozbuild_virtualenv.py,v 1.1 2020/05/28 15:26:23 triaxx Exp $

Remove a test that drives the Python environment to be reduilt during the
configure step. This bug is related to PR pkg/54878.

--- ../../python/mozbuild/mozbuild/virtualenv.py.orig	2019-07-01 11:07:46.000000000 +0200
+++ ../../python/mozbuild/mozbuild/virtualenv.py
@@ -122,12 +122,6 @@
 
             return False
 
-        # check modification times
-        activate_mtime = os.path.getmtime(self.activate_path)
-        dep_mtime = max(os.path.getmtime(p) for p in deps)
-        if dep_mtime > activate_mtime:
-            return False
-
         # Verify that the Python we're checking here is either the virutalenv
         # python, or we have the Python version that was used to create the
         # virtualenv. If this fails, it is likely system Python has been
