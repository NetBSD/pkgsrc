$NetBSD: patch-astropy_wcs_setup__package.py,v 1.1 2024/06/25 15:13:07 gutteridge Exp $

Fix builds with py-setuptools >= 70.
Borrowed from upstream commits
https://github.com/astropy/astropy/commit/f9483152a6f7a20512392ed6c8d272a297c070d6
https://github.com/astropy/astropy/commit/5dc050cda25006b4b45af54aead62a8bf760498e

--- astropy/wcs/setup_package.py.orig	2023-10-04 16:45:13.000000000 +0000
+++ astropy/wcs/setup_package.py
@@ -7,10 +7,10 @@ import shutil
 import sys
 from collections import defaultdict
 from os.path import join
+from pathlib import Path
 
 import numpy
 from setuptools import Extension
-from setuptools.dep_util import newer_group
 
 from extension_helpers import get_compiler, import_file, pkg_config, write_if_different
 
@@ -342,9 +342,9 @@ def get_extensions():
         or int(os.environ.get("ASTROPY_USE_SYSTEM_ALL", 0))
     ):
         for header in wcslib_headers:
-            source = join("cextern", "wcslib", "C", header)
-            dest = join("astropy", "wcs", "include", "wcslib", header)
-            if newer_group([source], dest, "newer"):
+            source = Path("cextern", "wcslib", "C", header)
+            dest = Path("astropy", "wcs", "include", "wcslib", header)
+            if not dest.is_file() or source.stat().st_mtime > dest.stat().st_mtime:
                 shutil.copy(source, dest)
 
     return [Extension("astropy.wcs._wcs", **cfg)]
