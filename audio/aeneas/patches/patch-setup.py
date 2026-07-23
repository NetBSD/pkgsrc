$NetBSD: patch-setup.py,v 1.3 2026/07/23 17:29:30 wiz Exp $

Fix for numpy.distutils deprecation from deleted
upstream bug tracker comment.
https://github.com/readbeyond/aeneas/issues/312

Always build C extension.

--- setup.py.orig	2017-03-16 12:48:53.000000000 +0000
+++ setup.py
@@ -187,7 +187,6 @@ try:
 # try importing numpy: if it fails, warn user and exit
 try:
     from numpy import get_include
-    from numpy.distutils import misc_util
 except ImportError:
     print("[ERRO] You must install numpy before installing aeneas")
     print("[INFO] Try the following command:")
@@ -195,7 +194,7 @@ except ImportError:
     sys.exit(1)
 
 # to compile cdtw and cmfcc, we need to include the NumPy dirs
-INCLUDE_DIRS = [misc_util.get_numpy_include_dirs()]
+INCLUDE_DIRS = [get_include()]
 
 # scripts to be installed globally
 # on Linux and Mac OS X, use the file without extension
@@ -234,7 +233,7 @@ EXTENSION_CEW = Extension(
         "aeneas/cew/cew_func.c"
     ],
     libraries=[
-        "espeak"
+        "espeak-ng"
     ]
 )
 EXTENSION_CFW = Extension(
@@ -297,7 +296,7 @@ else:
     print("[INFO] ")
     EXTENSIONS.append(EXTENSION_CEW)
 else:
-    if IS_LINUX:
+    if 1:
         EXTENSIONS.append(EXTENSION_CEW)
     elif IS_OSX:
         print("[INFO] *********************************************************************************")
