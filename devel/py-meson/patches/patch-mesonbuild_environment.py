$NetBSD: patch-mesonbuild_environment.py,v 1.4 2019/07/06 22:42:25 adam Exp $

Support SunOS ar and SunOS-specific GCC behaviour.

--- mesonbuild/environment.py.orig	2019-06-16 18:54:18.000000000 +0000
+++ mesonbuild/environment.py
@@ -613,6 +613,8 @@ class Environment:
             return CompilerType.GCC_MINGW
         elif '__CYGWIN__' in defines:
             return CompilerType.GCC_CYGWIN
+        elif '__sun' in defines:
+            return CompilerType.GCC_SUNOS
         return CompilerType.GCC_STANDARD
 
     def _get_compilers(self, lang, for_machine):
@@ -1220,6 +1222,8 @@ class Environment:
                 return ArLinker(linker)
             if p.returncode == 1 and err.startswith('usage'): # OSX
                 return ArLinker(linker)
+            if p.returncode == 1 and err.startswith('ar: bad option'): # SUNOS
+                return ArLinker(linker)
             if p.returncode == 1 and err.startswith('Usage'): # AIX
                 return ArLinker(linker)
             if p.returncode == 1 and err.startswith('ar: bad option: --'): # Solaris
