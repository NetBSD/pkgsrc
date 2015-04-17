$NetBSD: patch-numpy_distutils_ccompiler.py,v 1.2 2015/04/17 00:41:38 wen Exp $

Hack: use compiler with CFLAGS for linking executables.

--- numpy/distutils/ccompiler.py.orig	2015-02-01 16:38:21.000000000 +0000
+++ numpy/distutils/ccompiler.py
@@ -201,6 +201,7 @@ def CCompiler_compile(self, sources, out
                     src = cyg2win32(src)
                 self._compile(obj, src, ext, cc_args, extra_postargs, pp_opts)
     else:
+        self.linker_exe = ccomp
         for obj, (src, ext) in build.items():
             self._compile(obj, src, ext, cc_args, extra_postargs, pp_opts)
 
