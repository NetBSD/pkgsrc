$NetBSD: patch-Lib_distutils_unixccompiler.py,v 1.1 2014/05/09 02:27:14 wen Exp $

--- Lib/distutils/unixccompiler.py.orig	2013-05-15 16:32:54.000000000 +0000
+++ Lib/distutils/unixccompiler.py
@@ -232,7 +232,7 @@ class UnixCCompiler(CCompiler):
         elif sys.platform[:7] == "irix646" or sys.platform[:6] == "osf1V5":
             return ["-rpath", dir]
         else:
-            if self._is_gcc(compiler):
+            if True:
                 # gcc on non-GNU systems does not need -Wl, but can
                 # use it anyway.  Since distutils has always passed in
                 # -Wl whenever gcc was used in the past it is probably
