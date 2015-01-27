$NetBSD: patch-setup.py,v 1.1 2015/01/27 05:04:06 dbj Exp $

--- setup.py.orig	2005-11-11 08:56:59.000000000 +0000
+++ setup.py
@@ -15,12 +15,8 @@ if not hasattr(sys, 'version_info') or s
     raise SystemExit, "Python 2.0 or later required to build Numeric."
 
 from glob import glob
-try:
-    from setuptools import setup
-    have_setuptools = 1
-except ImportError:
-    from distutils.core import setup
-    have_setuptools = 0
+from distutils.core import setup
+have_setuptools = 0
 from distutils.core import Extension
 from distutils.command.config import config
 from distutils.sysconfig import get_config_var, customize_compiler
@@ -128,10 +124,10 @@ elif sys.platform in ['mac', 'beos5']:
 if os.path.isfile(os.path.join("Src","config.h")):
     extra_compile_args.append('-DHAVE_CONFIG')
 
-# For Mac OS X >= 10.2, an optimized BLAS and most of LAPACK (all the
+# For Mac OS X >= 10.3, an optimized BLAS and most of LAPACK (all the
 # routines we need, at least) should already be installed
-VECLIB_PATH = '/System/Library/Frameworks/vecLib.framework'
-have_veclib = os.path.exists(VECLIB_PATH)
+ACCELERATE_PATH = '/System/Library/Frameworks/Accelerate.framework'
+have_accelerate = os.path.exists(ACCELERATE_PATH)
 
 def extension(name, sources, **kw):
     def prepend(name, value, kw=kw):
@@ -146,8 +142,8 @@ lapack_source = [path('Src/lapack_litemo
 lapack_link_args = customize.lapack_extra_link_args
 if customize.use_system_lapack:
     pass
-elif have_veclib:
-    lapack_link_args.extend(['-framework', 'vecLib'])
+elif have_accelerate:
+    lapack_link_args.extend(['-framework', 'Accelerate'])
 else:
     lapack_source.extend([path('Src/f2c_lite.c'),
                           path('Src/zlapack_lite.c'),
@@ -172,11 +168,10 @@ if customize.use_dotblas:
                                             customize.dotblas_cblas_header)],
                             extra_link_args=customize.dotblas_extra_link_args,
                            )
-elif have_veclib:
+elif have_accelerate:
     dotblas_ext = extension('_dotblas', dotblas_source,
-                            include_dirs=[os.path.join(VECLIB_PATH, 'Headers')],
-                            define_macros=[('CBLAS_HEADER', '<cblas.h>')],
-                            extra_link_args=['-framework', 'vecLib'],
+                            define_macros=[('CBLAS_HEADER', '<Accelerate/Accelerate.h>')],
+                            extra_link_args=['-framework', 'Accelerate'],
                            )
 else:
     dotblas_ext = None
