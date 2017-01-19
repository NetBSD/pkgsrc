$NetBSD: patch-Lib_distutils_unixccompiler.py,v 1.3 2017/01/19 13:55:53 wen Exp $

Do not force RUNPATH vs RPATH, trust the compiler to know what the
platform wants.

--- Lib/distutils/unixccompiler.py.orig	2017-01-17 07:57:48.000000000 +0000
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
@@ -298,7 +283,7 @@ class UnixCCompiler(CCompiler):
 
             if sys.platform == 'darwin' and (
                 dir.startswith('/System/') or (
-                dir.startswith('/usr/') and not dir.startswith('/usr/local/'))):
+                dir.startswith('/usr/') and not dir.startswith('/usr/pkg/'))):
 
                 shared = os.path.join(sysroot, dir[1:], shared_f)
                 dylib = os.path.join(sysroot, dir[1:], dylib_f)
