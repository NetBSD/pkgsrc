$NetBSD: patch-mesonbuild_compilers_c.py,v 1.1 2018/09/05 14:39:13 jperkin Exp $

Support SunOS.

--- mesonbuild/compilers/c.py.orig	2018-08-25 08:05:50.000000000 +0000
+++ mesonbuild/compilers/c.py
@@ -162,7 +162,7 @@ class CCompiler(Compiler):
             if self.gcc_type == compilers.GCC_OSX:
                 # Apple ld
                 return ['-Wl,-undefined,dynamic_lookup']
-            else:
+            elif self.gcc_type != compilers.GCC_SUNOS:
                 # GNU ld and LLVM lld
                 return ['-Wl,--allow-shlib-undefined']
         elif self.id == 'msvc':
