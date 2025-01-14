$NetBSD: patch-giscanner_ccompiler.py,v 1.9 2025/01/14 13:17:12 adam Exp $

Exclude system paths from LD_LIBRARY_PATH.
Do not use -Wl,--no-as-needed on SunOS.

--- giscanner/ccompiler.py.orig	2024-09-13 13:08:54.000000000 +0000
+++ giscanner/ccompiler.py
@@ -242,7 +242,7 @@ class CCompiler(object):
 
             # Ensure libraries are always linked as we are going to use ldd to work
             # out their names later
-            if sys.platform != 'darwin':
+            if sys.platform != 'darwin' and sys.platform != 'sunos5':
                 args.append('-Wl,--no-as-needed')
 
         for library_path in libpaths:
@@ -260,7 +260,8 @@ class CCompiler(object):
                     else:
                         args.append('-Wl,-rpath,' + library_path)
 
-            runtime_paths.append(library_path)
+            if library_path not in '@_OPSYS_LIB_DIRS@'.split(' '):
+                runtime_paths.append(library_path)
 
         for library in libraries + extra_libraries:
             if os.path.isfile(library):
