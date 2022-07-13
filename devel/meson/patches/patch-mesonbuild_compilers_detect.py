$NetBSD: patch-mesonbuild_compilers_detect.py,v 1.2 2022/07/13 03:57:22 triaxx Exp $

Specify c++ language when making CXX parse standard input.
Fixes problem where graphics/MesaLib fails to build due to:

> clang++ -std=c++14 -dM -E -
> error: invalid argument '-std=c++14' not allowed with 'C'

--- mesonbuild/compilers/detect.py.orig	2021-09-10 05:30:31.000000000 +0000
+++ mesonbuild/compilers/detect.py
@@ -1224,7 +1224,10 @@ def _get_gnu_compiler_defines(compiler: 
     """
     # Arguments to output compiler pre-processor defines to stdout
     # gcc, g++, and gfortran all support these arguments
-    args = compiler + ['-E', '-dM', '-']
+    args = compiler + ['-E', '-dM']
+    if compiler[0].endswith('++'):
+        args += ['-x', 'c++']
+    args += ['-']
     p, output, error = Popen_safe(args, write='', stdin=subprocess.PIPE)
     if p.returncode != 0:
         raise EnvironmentException('Unable to detect GNU compiler type:\n' + output + error)
@@ -1248,7 +1251,10 @@ def _get_clang_compiler_defines(compiler
     """
     Get the list of Clang pre-processor defines
     """
-    args = compiler + ['-E', '-dM', '-']
+    args = compiler + ['-E', '-dM']
+    if compiler[0].endswith('++'):
+        args += ['-x', 'c++']
+    args += ['-']
     p, output, error = Popen_safe(args, write='', stdin=subprocess.PIPE)
     if p.returncode != 0:
         raise EnvironmentException('Unable to get clang pre-processor defines:\n' + output + error)
