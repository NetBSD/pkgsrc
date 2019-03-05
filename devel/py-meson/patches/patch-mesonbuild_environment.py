$NetBSD: patch-mesonbuild_environment.py,v 1.3 2019/03/05 16:30:18 prlw1 Exp $

Support SunOS ar and SunOS-specific GCC behaviour.

--- mesonbuild/environment.py.orig	2019-01-23 16:46:09.000000000 +0000
+++ mesonbuild/environment.py
@@ -528,6 +528,8 @@ class Environment:
             return CompilerType.GCC_MINGW
         elif '__CYGWIN__' in defines:
             return CompilerType.GCC_CYGWIN
+        elif '__sun' in defines:
+            return CompilerType.GCC_SUNOS
         return CompilerType.GCC_STANDARD
 
     def _get_compilers(self, lang, want_cross):
@@ -1019,6 +1021,8 @@ class Environment:
                 return ArLinker(linker)
             if p.returncode == 1 and err.startswith('usage'): # OSX
                 return ArLinker(linker)
+            if p.returncode == 1 and err.startswith('ar: bad option'): # SUNOS
+                return ArLinker(linker)
             if p.returncode == 1 and err.startswith('Usage'): # AIX
                 return ArLinker(linker)
         self._handle_exceptions(popen_exceptions, linkers, 'linker')
