$NetBSD: patch-Lib_distutils_unixccompiler.py,v 1.3 2015/04/24 03:01:36 rodent Exp $

* from cygport 2.7.3-dylib.patch

--- Lib/distutils/unixccompiler.py.orig	2014-12-10 15:59:34.000000000 +0000
+++ Lib/distutils/unixccompiler.py
@@ -82,6 +82,7 @@ class UnixCCompiler(CCompiler):
     static_lib_format = shared_lib_format = dylib_lib_format = "lib%s%s"
     if sys.platform == "cygwin":
         exe_extension = ".exe"
+        dylib_lib_extension = ".dll.a"
 
     def preprocess(self, source,
                    output_file=None, macros=None, include_dirs=None,
@@ -234,10 +235,8 @@ class UnixCCompiler(CCompiler):
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
