$NetBSD: patch-mesonbuild_compilers_detect.py,v 1.3 2022/08/15 08:19:39 adam Exp $

Specify c++ language when making CXX parse standard input.
Fixes problem where graphics/MesaLib fails to build due to:

> clang++ -std=c++14 -dM -E -
> error: invalid argument '-std=c++14' not allowed with 'C'

--- mesonbuild/compilers/detect.py.orig	2022-08-13 08:48:46.000000000 +0000
+++ mesonbuild/compilers/detect.py
@@ -1231,7 +1231,10 @@ def _get_gnu_compiler_defines(compiler: 
     """
     # Arguments to output compiler pre-processor defines to stdout
     # gcc, g++, and gfortran all support these arguments
-    args = compiler + ['-E', '-dM', '-']
+    args = compiler + ['-E', '-dM']
+    if compiler[0].endswith('++'):
+        args += ['-x', 'c++']
+    args += ['-']
     mlog.debug(f'Running command: {join_args(args)}')
     p, output, error = Popen_safe(args, write='', stdin=subprocess.PIPE)
     if p.returncode != 0:
@@ -1258,7 +1261,10 @@ def _get_clang_compiler_defines(compiler
     """
     Get the list of Clang pre-processor defines
     """
-    args = compiler + ['-E', '-dM', '-']
+    args = compiler + ['-E', '-dM']
+    if compiler[0].endswith('++'):
+        args += ['-x', 'c++']
+    args += ['-']
     mlog.debug(f'Running command: {join_args(args)}')
     p, output, error = Popen_safe(args, write='', stdin=subprocess.PIPE)
     if p.returncode != 0:
