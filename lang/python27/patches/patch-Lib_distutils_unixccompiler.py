$NetBSD: patch-Lib_distutils_unixccompiler.py,v 1.5 2022/05/13 18:42:05 tnn Exp $

* from cygport 2.7.3-dylib.patch

--- Lib/distutils/unixccompiler.py.orig	2020-04-19 21:13:39.000000000 +0000
+++ Lib/distutils/unixccompiler.py
@@ -84,6 +84,7 @@ class UnixCCompiler(CCompiler):
     xcode_stub_lib_format = dylib_lib_format
     if sys.platform == "cygwin":
         exe_extension = ".exe"
+        dylib_lib_extension = ".dll.a"
 
     def preprocess(self, source,
                    output_file=None, macros=None, include_dirs=None,
@@ -238,10 +239,8 @@ class UnixCCompiler(CCompiler):
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
@@ -271,13 +270,10 @@ class UnixCCompiler(CCompiler):
             #       usr/lib/libedit.tbd
             # vs
             #   /usr/lib/libedit.dylib
-            cflags = sysconfig.get_config_var('CFLAGS')
-            m = re.search(r'-isysroot\s+(\S+)', cflags)
-            if m is None:
-                sysroot = '/'
+            if os.path.exists('@OSX_SDK_PATH@/usr/lib'):
+                sysroot = '@OSX_SDK_PATH@'
             else:
-                sysroot = m.group(1)
-
+                sysroot = '/'
 
 
         for dir in dirs:
