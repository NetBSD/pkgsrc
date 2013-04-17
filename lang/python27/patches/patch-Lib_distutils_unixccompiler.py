$NetBSD: patch-Lib_distutils_unixccompiler.py,v 1.1 2013/04/17 13:21:05 obache Exp $

* from cygport 2.7.3-dylib.patch

--- Lib/distutils/unixccompiler.py.orig	2013-04-06 14:02:26.000000000 +0000
+++ Lib/distutils/unixccompiler.py
@@ -82,6 +82,7 @@ class UnixCCompiler(CCompiler):
     static_lib_format = shared_lib_format = dylib_lib_format = "lib%s%s"
     if sys.platform == "cygwin":
         exe_extension = ".exe"
+        dylib_lib_extension = ".dll.a"
 
     def preprocess(self, source,
                    output_file=None, macros=None, include_dirs=None,
