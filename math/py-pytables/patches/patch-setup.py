$NetBSD: patch-setup.py,v 1.1 2014/09/20 17:56:36 wiz Exp $

Fix build with cython-0.20++.

--- setup.py.orig	2014-03-25 20:49:03.000000000 +0000
+++ setup.py
@@ -122,21 +122,21 @@ if not has_setuptools:
 
 # Check if Cython is installed or not (requisite)
 try:
+    from Cython import __version__ as CythonVersion
     from Cython.Distutils import build_ext
-    from Cython.Compiler.Main import Version
     cmdclass['build_ext'] = build_ext
 except ImportError:
     exit_with_error(
         "You need %(pkgname)s %(pkgver)s or greater to compile PyTables!"
         % {'pkgname': 'Cython', 'pkgver': min_cython_version})
 
-if Version.version < min_cython_version:
+if CythonVersion < min_cython_version:
     exit_with_error(
         "At least Cython %s is needed so as to generate extensions!"
         % (min_cython_version))
 else:
     print("* Found %(pkgname)s %(pkgver)s package installed."
-          % {'pkgname': 'Cython', 'pkgver': Version.version})
+          % {'pkgname': 'Cython', 'pkgver': CythonVersion})
 
 VERSION = open('VERSION').read().strip()
 
