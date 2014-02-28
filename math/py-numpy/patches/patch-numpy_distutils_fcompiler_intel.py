$NetBSD: patch-numpy_distutils_fcompiler_intel.py,v 1.1 2014/02/28 09:43:11 adam Exp $

On OS X, don't link against Python.framework, since we use Python from pkgsrc.

--- numpy/distutils/fcompiler/intel.py.orig	2014-02-28 07:25:23.000000000 +0000
+++ numpy/distutils/fcompiler/intel.py
@@ -68,7 +68,7 @@ class IntelFCompiler(BaseIntelFCompiler)
                 opt.remove('-shared')
             except ValueError:
                 idx = 0
-            opt[idx:idx] = ['-dynamiclib', '-Wl,-undefined,dynamic_lookup', '-Wl,-framework,Python']
+            opt[idx:idx] = ['-dynamiclib', '-Wl,-undefined,dynamic_lookup',]
         return opt
 
 class IntelItaniumFCompiler(IntelFCompiler):
