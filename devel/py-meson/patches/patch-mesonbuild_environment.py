$NetBSD: patch-mesonbuild_environment.py,v 1.1 2018/05/14 09:43:15 jperkin Exp $

Support SunOS ar.

--- mesonbuild/environment.py.orig	2018-02-20 21:48:57.000000000 +0000
+++ mesonbuild/environment.py
@@ -779,6 +779,8 @@ class Environment:
                 return ArLinker(linker)
             if p.returncode == 1 and err.startswith('usage'): # OSX
                 return ArLinker(linker)
+            if p.returncode == 1 and err.startswith('ar: bad option'): # SunOS
+                return ArLinker(linker)
         self._handle_exceptions(popen_exceptions, linkers, 'linker')
         raise EnvironmentException('Unknown static linker "%s"' % ' '.join(linkers))
 
