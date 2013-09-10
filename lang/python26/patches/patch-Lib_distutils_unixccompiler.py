$NetBSD: patch-Lib_distutils_unixccompiler.py,v 1.1 2013/09/10 14:22:30 joerg Exp $

--- Lib/distutils/unixccompiler.py.orig	2012-04-10 15:32:04.000000000 +0000
+++ Lib/distutils/unixccompiler.py
@@ -292,10 +292,8 @@ class UnixCCompiler(CCompiler):
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
