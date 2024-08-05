$NetBSD: patch-setup.py,v 1.1 2024/08/05 20:38:39 adam Exp $

Allow cmake to find pybind11 config files.

--- setup.py.orig	2024-08-05 19:53:30.832882276 +0000
+++ setup.py
@@ -16,6 +16,7 @@
 
 import os
 import platform
+import site
 import shutil
 import subprocess
 import sys
@@ -86,9 +87,11 @@ class BuildCMakeExtension(build_ext.buil
     extension_dir = os.path.abspath(
         os.path.dirname(self.get_ext_fullpath(ext.name)))
     build_cfg = 'Debug' if self.debug else 'Release'
+    site_dir = site.getsitepackages()[0]
     cmake_args = [
         f'-DPython3_ROOT_DIR={sys.prefix}',
         f'-DPython3_EXECUTABLE={sys.executable}',
+        f'-Dpybind11_DIR={site_dir}/pybind11/share/cmake/pybind11',
         f'-DCMAKE_LIBRARY_OUTPUT_DIRECTORY={extension_dir}',
         f'-DCMAKE_BUILD_TYPE={build_cfg}'
     ]
