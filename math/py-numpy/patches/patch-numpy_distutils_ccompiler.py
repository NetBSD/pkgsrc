$NetBSD: patch-numpy_distutils_ccompiler.py,v 1.1 2013/05/20 05:59:58 adam Exp $

Hack: use compiler with CFLAGS for linking executables.

--- numpy/distutils/ccompiler.py.orig	2013-05-19 19:28:28.000000000 +0000
+++ numpy/distutils/ccompiler.py
@@ -199,6 +199,7 @@ def CCompiler_compile(self, sources, out
                     src = cyg2win32(src)
                 self._compile(obj, src, ext, cc_args, extra_postargs, pp_opts)
     else:
+        self.linker_exe = ccomp
         for obj, (src, ext) in build.items():
             self._compile(obj, src, ext, cc_args, extra_postargs, pp_opts)
 
