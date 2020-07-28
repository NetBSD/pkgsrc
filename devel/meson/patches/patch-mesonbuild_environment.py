$NetBSD: patch-mesonbuild_environment.py,v 1.4 2020/07/28 23:28:23 tnn Exp $

Specify c++ language when making CXX parse standard input.
Fixes problem where graphics/MesaLib fails to build due to:

> clang++ -std=c++14 -dM -E -
> error: invalid argument '-std=c++14' not allowed with 'C'

--- mesonbuild/environment.py.orig	2020-07-05 20:13:14.000000000 +0000
+++ mesonbuild/environment.py
@@ -708,7 +708,10 @@ class Environment:
         """
         # Arguments to output compiler pre-processor defines to stdout
         # gcc, g++, and gfortran all support these arguments
-        args = compiler + ['-E', '-dM', '-']
+        args = compiler + ['-E', '-dM' ]
+        if compiler[0].endswith('++'):
+          args += [ '-x', 'c++' ]
+        args += [ '-' ]
         p, output, error = Popen_safe(args, write='', stdin=subprocess.PIPE)
         if p.returncode != 0:
             raise EnvironmentException('Unable to detect GNU compiler type:\n' + output + error)
@@ -750,7 +753,10 @@ class Environment:
         """
         Get the list of Clang pre-processor defines
         """
-        args = compiler + ['-E', '-dM', '-']
+        args = compiler + ['-E', '-dM' ]
+        if compiler[0].endswith('++'):
+          args += [ '-x', 'c++' ]
+        args += [ '-' ]
         p, output, error = Popen_safe(args, write='', stdin=subprocess.PIPE)
         if p.returncode != 0:
             raise EnvironmentException('Unable to get clang pre-processor defines:\n' + output + error)
