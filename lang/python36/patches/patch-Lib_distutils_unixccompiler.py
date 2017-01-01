$NetBSD: patch-Lib_distutils_unixccompiler.py,v 1.1 2017/01/01 14:34:27 adam Exp $

Do not force RUNPATH vs RPATH, trust the compiler to know what the
platform wants.

--- Lib/distutils/unixccompiler.py.orig	2016-12-23 02:21:19.000000000 +0000
+++ Lib/distutils/unixccompiler.py
@@ -236,22 +236,7 @@ class UnixCCompiler(CCompiler):
         elif sys.platform[:7] == "irix646" or sys.platform[:6] == "osf1V5":
             return ["-rpath", dir]
         else:
-            if self._is_gcc(compiler):
-                # gcc on non-GNU systems does not need -Wl, but can
-                # use it anyway.  Since distutils has always passed in
-                # -Wl whenever gcc was used in the past it is probably
-                # safest to keep doing so.
-                if sysconfig.get_config_var("GNULD") == "yes":
-                    # GNU ld needs an extra option to get a RUNPATH
-                    # instead of just an RPATH.
-                    return "-Wl,--enable-new-dtags,-R" + dir
-                else:
-                    return "-Wl,-R" + dir
-            else:
-                # No idea how --enable-new-dtags would be passed on to
-                # ld if this system was using GNU ld.  Don't know if a
-                # system like this even exists.
-                return "-R" + dir
+            return "-Wl,-R" + dir
 
     def library_option(self, lib):
         return "-l" + lib
