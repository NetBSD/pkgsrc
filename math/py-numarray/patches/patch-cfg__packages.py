$NetBSD: patch-cfg__packages.py,v 1.1 2015/01/27 05:05:30 dbj Exp $

The vecLib framework has been obsolete since at least osx 10.3
use the Accelerate framework instead

--- cfg_packages.py.orig	2005-07-21 13:57:10.000000000 +0000
+++ cfg_packages.py
@@ -28,13 +28,12 @@ if USE_LAPACK:
     lapack_link_args = [] 
     lapack_include_dirs = ["Packages/LinearAlgebra2/Src"] 
 
-    if os.path.exists('/System/Library/Frameworks/vecLib.framework'):
+    if os.path.exists('/System/Library/Frameworks/Accelerate.framework'):
         # use Apple's optimized BLAS implementation
         lapack_libs = []
-        lapack_link_args = ['-framework', 'vecLib']
-        lapack_compile_args = ['-framework', 'vecLib']
+        lapack_link_args = ['-framework', 'Accelerate']
+        lapack_compile_args = ['-framework', 'Accelerate']
         lapack_dirs = []
-        lapack_include_dirs +=  ['/System/Library/Frameworks/vecLib.framework/Headers']
     elif USE_ABSOFT:  # Absoft Fortran
         lapack_dirs = ['/usr/local/lib/atlas', '/opt/absoft/lib']
         lapack_libs = ['lapack', 'f77blas', 'cblas', 'atlas',
