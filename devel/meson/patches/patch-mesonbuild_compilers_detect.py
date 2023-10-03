$NetBSD: patch-mesonbuild_compilers_detect.py,v 1.5 2023/10/03 01:21:36 gutteridge Exp $

Specify c++ language when making CXX parse standard input.
Fixes problem where graphics/MesaLib fails to build due to:

> clang++ -std=c++14 -dM -E -
> error: invalid argument '-std=c++14' not allowed with 'C'

Also account for multiple versions of cython in pkgsrc.

--- mesonbuild/compilers/detect.py.orig	2023-07-21 20:36:13.000000000 +0000
+++ mesonbuild/compilers/detect.py
@@ -80,7 +80,7 @@ defaults['cuda'] = ['nvcc']
 defaults['rust'] = ['rustc']
 defaults['swift'] = ['swiftc']
 defaults['vala'] = ['valac']
-defaults['cython'] = ['cython', 'cython3'] # Official name is cython, but Debian renamed it to cython3.
+defaults['cython'] = ['cython', 'cython-3.11', 'cython-3.10', 'cython-3.9', 'cython-3.8', 'cython-3.12'] # Handle pkgsrc multi-versions.
 defaults['static_linker'] = ['ar', 'gar']
 defaults['strip'] = ['strip']
 defaults['vs_static_linker'] = ['lib']
@@ -1318,7 +1318,10 @@ def _get_gnu_compiler_defines(compiler: 
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
@@ -1345,7 +1348,10 @@ def _get_clang_compiler_defines(compiler
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
