$NetBSD: patch-numpy_distutils_fcompiler_gnu.py,v 1.1 2011/11/22 20:56:13 minskim Exp $

Do not run a shell command when it is "None".

--- numpy/distutils/fcompiler/gnu.py.orig	2010-04-22 09:35:24.000000000 +0000
+++ numpy/distutils/fcompiler/gnu.py
@@ -249,7 +249,7 @@ class Gnu95FCompiler(GnuFCompiler):
 
     def _universal_flags(self, cmd):
         """Return a list of -arch flags for every supported architecture."""
-        if not sys.platform == 'darwin':
+        if not sys.platform == 'darwin' or cmd == None:
             return []
         arch_flags = []
         for arch in ["ppc", "i686", "x86_64"]:
