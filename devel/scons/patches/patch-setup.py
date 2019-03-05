$NetBSD: patch-setup.py,v 1.1 2019/03/05 19:30:01 adam Exp $

Use PKGMANDIR.

--- setup.py.orig	2019-01-23 17:10:54.000000000 +0000
+++ setup.py
@@ -30,7 +30,6 @@ import distutils.command.install_data
 import distutils.command.install
 import distutils.core
 import distutils
-import setuptools
 """
 NOTE: Installed SCons is not importable like usual Python packages. It is
       executed explicitly with command line scripts. This allows multiple
@@ -380,7 +379,7 @@ class install_data(_install_data):
             if is_win32:
                 dir = 'Doc'
             else:
-                dir = os.path.join('man', 'man1')
+                dir = os.path.join(os.getenv("PKGMANDIR"), 'man1')
             self.data_files = [(dir, man_pages)]
             man_dir = os.path.join(self.install_dir, dir)
             msg = "Installed SCons man pages into %s" % man_dir
