$NetBSD: patch-setup.py,v 1.1 2022/01/27 08:24:51 wiz Exp $

Force running cythonize, to fix build with python 3.10.

--- setup.py.orig	2020-05-04 02:03:06.000000000 +0000
+++ setup.py
@@ -168,6 +168,7 @@ def get_extension_modules():
             Extension("pyproj._list", ["pyproj/_list.pyx"], **ext_options),
         ],
         quiet=True,
+        force=True,
         **get_cythonize_options()
     )
 
