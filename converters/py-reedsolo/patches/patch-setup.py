$NetBSD: patch-setup.py,v 1.1 2022/01/25 10:40:23 wiz Exp $

Fix build with python 3.10.
https://github.com/tomerfiliba/reedsolomon/pull/38

--- setup.py.orig	2020-05-20 06:35:49.000000000 +0000
+++ setup.py
@@ -31,7 +31,7 @@ try:
     # If Cython is installed, transpile the optimized Cython module to C and compile as a .pyd to be distributed
     from Cython.Build import cythonize
     print("Cython is installed, building creedsolo module")
-    extensions = cythonize([ Extension('creedsolo', ['creedsolo.pyx']) ])
+    extensions = cythonize([ Extension('creedsolo', ['creedsolo.pyx']) ], force=True)
 except ImportError:
     # Else Cython is not installed (or user explicitly wanted to skip)
     if '--native-compile' in sys.argv:
