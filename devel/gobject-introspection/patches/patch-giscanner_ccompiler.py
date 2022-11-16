$NetBSD: patch-giscanner_ccompiler.py,v 1.5 2022/11/16 16:08:34 jperkin Exp $

Exclude system paths from LD_LIBRARY_PATH.
Do not use -Wl,--no-as-needed on SunOS.

--- giscanner/ccompiler.py.orig	2021-09-17 16:02:42.520052200 +0000
+++ giscanner/ccompiler.py
@@ -197,7 +197,7 @@ class CCompiler(object):
 
                 # Ensure libraries are always linked as we are going to use ldd to work
                 # out their names later
-                if sys.platform != 'darwin':
+                if sys.platform != 'darwin' and sys.platform != 'sunos5':
                     args.append('-Wl,--no-as-needed')
 
         for library_path in libpaths:
@@ -215,7 +215,8 @@ class CCompiler(object):
                     else:
                         args.append('-Wl,-rpath,' + library_path)
 
-            runtime_paths.append(library_path)
+            if library_path not in '@_OPSYS_LIB_DIRS@'.split(' '):
+                runtime_paths.append(library_path)
 
         for library in libraries + extra_libraries:
             if self.check_is_msvc():
