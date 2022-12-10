$NetBSD: patch-setup.py,v 1.2 2022/12/10 13:19:38 gdt Exp $

Force running cythonize, to fix build with python 3.10.

--- setup.py.orig	2021-03-05 04:25:28.000000000 +0000
+++ setup.py
@@ -179,6 +179,7 @@ def get_extension_modules():
             Extension("pyproj._sync", ["pyproj/_sync.pyx"], **ext_options),
         ],
         quiet=True,
+        force=True,
         compile_time_env={
             "CTE_PROJ_VERSION_MAJOR": int(proj_version_major),
             "CTE_PROJ_VERSION_MINOR": int(proj_version_minor),
