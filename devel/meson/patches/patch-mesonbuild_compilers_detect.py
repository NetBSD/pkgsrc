$NetBSD: patch-mesonbuild_compilers_detect.py,v 1.6 2024/07/19 07:26:38 adam Exp $

Specify c++ language when making CXX parse standard input.
Fixes problem where graphics/MesaLib fails to build due to:

> clang++ -std=c++14 -dM -E -
> error: invalid argument '-std=c++14' not allowed with 'C'

Also account for multiple versions of cython in pkgsrc.

--- mesonbuild/compilers/detect.py.orig	2024-06-24 16:26:41.000000000 +0000
+++ mesonbuild/compilers/detect.py
@@ -68,7 +68,7 @@ defaults['cuda'] = ['nvcc']
 defaults['rust'] = ['rustc']
 defaults['swift'] = ['swiftc']
 defaults['vala'] = ['valac']
-defaults['cython'] = ['cython', 'cython3'] # Official name is cython, but Debian renamed it to cython3.
+defaults['cython'] = ['cython', 'cython-3.11', 'cython-3.10', 'cython-3.9', 'cython-3.8', 'cython-3.12'] # Handle pkgsrc multi-versions.
 defaults['static_linker'] = ['ar', 'gar']
 defaults['strip'] = ['strip']
 defaults['vs_static_linker'] = ['lib']
@@ -1346,7 +1346,10 @@ def _get_gnu_compiler_defines(compiler:
 
     # Arguments to output compiler pre-processor defines to stdout
     # gcc, g++, and gfortran all support these arguments
-    baseline_test_args = ['-E', '-dM', '-']
+    baseline_test_args = ['-E', '-dM']
+    if compiler[0].endswith('++'):
+        baseline_test_args += ['-x', 'c++']
+    baseline_test_args += ['-']
     try:
         # We assume that when _get_gnu_compiler_defines is called, it's
         # close enough to a GCCish compiler so we reuse the _LANG_MAP
@@ -1398,7 +1401,10 @@ def _get_clang_compiler_defines(compiler
         return output
 
     # Arguments to output compiler pre-processor defines to stdout
-    baseline_test_args = ['-E', '-dM', '-']
+    baseline_test_args = ['-E', '-dM']
+    if compiler[0].endswith('++'):
+        baseline_test_args += ['-x', 'c++']
+    baseline_test_args += ['-']
     try:
         # We assume that when _get_clang_compiler_defines is called, it's
         # close enough to a Clangish compiler so we reuse the _LANG_MAP
