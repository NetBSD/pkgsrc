$NetBSD: patch-giscanner_ccompiler.py,v 1.4 2021/01/11 19:15:24 jperkin Exp $

Exclude system paths from LD_LIBRARY_PATH.

--- giscanner/ccompiler.py.orig	2020-10-03 10:23:41.768748500 +0000
+++ giscanner/ccompiler.py
@@ -215,7 +215,8 @@ class CCompiler(object):
                     else:
                         args.append('-Wl,-rpath,' + library_path)
 
-            runtime_paths.append(library_path)
+            if library_path not in '@_OPSYS_LIB_DIRS@'.split(' '):
+                runtime_paths.append(library_path)
 
         for library in libraries + extra_libraries:
             if self.check_is_msvc():
