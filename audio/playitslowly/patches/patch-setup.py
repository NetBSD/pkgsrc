$NetBSD: patch-setup.py,v 1.1 2022/01/25 19:00:56 wiz Exp $

Support python 3.10.

--- setup.py.orig	2016-05-21 20:57:51.000000000 +0000
+++ setup.py
@@ -20,9 +20,10 @@ class new_install(install):
                 self.execute(os.unlink, (p, ), "Removing old file %r" % p)
 
         # write install-info
-        basename = "%s-py%s.install-info" % (
+        basename = "%s-py%s.%s.install-info" % (
             to_filename(safe_name(self.distribution.get_name())),
-            sys.version[:3]
+            sys.version_info.major,
+            sys.version_info.minor
         )
         install_info = os.path.join(self.install_libbase, basename)
         outputs = self.get_outputs()
