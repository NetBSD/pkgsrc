$NetBSD: patch-python_mozbuild_mozbuild_virtualenv.py,v 1.1 2020/03/23 08:46:14 triaxx Exp $

Remove a test that drives the Python environment to be reduilt during the
configure step. This bug seems esoteric since it only occurs on some machines
when using pbulk in a sandbox chroot.

--- python/mozbuild/mozbuild/virtualenv.py.orig	2018-04-28 01:04:06.000000000 +0000
+++ python/mozbuild/mozbuild/virtualenv.py
@@ -122,12 +122,6 @@ class VirtualenvManager(object):
 
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
