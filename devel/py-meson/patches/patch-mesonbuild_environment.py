$NetBSD: patch-mesonbuild_environment.py,v 1.2 2018/05/15 09:04:37 jperkin Exp $

Support SunOS ar and SunOS-specific GCC behaviour.

--- mesonbuild/environment.py.orig	2018-02-20 21:48:57.000000000 +0000
+++ mesonbuild/environment.py
@@ -29,6 +29,7 @@ from .compilers import (
     GCC_CYGWIN,
     GCC_MINGW,
     GCC_OSX,
+    GCC_SUNOS,
     GCC_STANDARD,
     ICC_STANDARD,
     is_assembly,
@@ -409,6 +410,8 @@ class Environment:
         # Detect GCC type (Apple, MinGW, Cygwin, Unix)
         if '__APPLE__' in defines:
             return GCC_OSX
+        elif '__sun' in defines:
+            return GCC_SUNOS
         elif '__MINGW32__' in defines or '__MINGW64__' in defines:
             return GCC_MINGW
         elif '__CYGWIN__' in defines:
@@ -779,6 +782,8 @@ class Environment:
                 return ArLinker(linker)
             if p.returncode == 1 and err.startswith('usage'): # OSX
                 return ArLinker(linker)
+            if p.returncode == 1 and err.startswith('ar: bad option'): # SunOS
+                return ArLinker(linker)
         self._handle_exceptions(popen_exceptions, linkers, 'linker')
         raise EnvironmentException('Unknown static linker "%s"' % ' '.join(linkers))
 
