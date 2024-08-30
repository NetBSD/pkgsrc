$NetBSD: patch-giscanner_ccompiler.py,v 1.7 2024/08/30 16:31:19 ryoon Exp $

Fix build with py-setuptools-74.0.0.

Exclude system paths from LD_LIBRARY_PATH.
Do not use -Wl,--no-as-needed on SunOS.

--- giscanner/ccompiler.py.orig	2024-04-01 13:21:25.000000000 +0000
+++ giscanner/ccompiler.py
@@ -26,7 +26,7 @@ import tempfile
 import sys
 import distutils
 
-from distutils.msvccompiler import MSVCCompiler
+from distutils._msvccompiler import MSVCCompiler
 from distutils.unixccompiler import UnixCCompiler
 from distutils.cygwinccompiler import Mingw32CCompiler
 from distutils.sysconfig import get_config_vars
@@ -232,7 +232,7 @@ class CCompiler(object):
 
                 # Ensure libraries are always linked as we are going to use ldd to work
                 # out their names later
-                if sys.platform != 'darwin':
+                if sys.platform != 'darwin' and sys.platform != 'sunos5':
                     args.append('-Wl,--no-as-needed')
 
         for library_path in libpaths:
@@ -250,7 +250,8 @@ class CCompiler(object):
                     else:
                         args.append('-Wl,-rpath,' + library_path)
 
-            runtime_paths.append(library_path)
+            if library_path not in '@_OPSYS_LIB_DIRS@'.split(' '):
+                runtime_paths.append(library_path)
 
         for library in libraries + extra_libraries:
             if os.path.isfile(library):
