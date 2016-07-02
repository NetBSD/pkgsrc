$NetBSD: patch-Lib_distutils_unixccompiler.py,v 1.4 2016/07/02 15:05:43 adam Exp $

* from cygport 2.7.3-dylib.patch

--- Lib/distutils/unixccompiler.py.orig	2016-06-25 21:49:30.000000000 +0000
+++ Lib/distutils/unixccompiler.py
@@ -84,6 +84,7 @@ class UnixCCompiler(CCompiler):
     xcode_stub_lib_format = dylib_lib_format
     if sys.platform == "cygwin":
         exe_extension = ".exe"
+        dylib_lib_extension = ".dll.a"
 
     def preprocess(self, source,
                    output_file=None, macros=None, include_dirs=None,
@@ -236,10 +237,8 @@ class UnixCCompiler(CCompiler):
             return ["+s", "-L" + dir]
         elif sys.platform[:7] == "irix646" or sys.platform[:6] == "osf1V5":
             return ["-rpath", dir]
-        elif self._is_gcc(compiler):
-            return "-Wl,-R" + dir
         else:
-            return "-R" + dir
+            return "-Wl,-R" + dir
 
     def library_option(self, lib):
         return "-l" + lib
