$NetBSD: patch-setup.py,v 1.1 2018/05/22 06:41:30 adam Exp $

Point to a parent directory, to distinguish includes from
the ones currenly installed with Python.

--- setup.py.orig	2017-07-18 21:23:52.000000000 +0000
+++ setup.py
@@ -9,7 +9,7 @@ except ImportError:
 
 _ast27 = Extension(
     '_ast27',
-    include_dirs = ['ast27/Include'],
+    include_dirs = ['ast27'],
     sources = [
         'ast27/Parser/acceler.c',
         'ast27/Parser/bitset.c',
@@ -45,7 +45,7 @@ _ast27 = Extension(
 
 _ast3 = Extension(
     '_ast3',
-    include_dirs = ['ast3/Include'],
+    include_dirs = ['ast3'],
     sources = [
         'ast3/Parser/acceler.c',
         'ast3/Parser/bitset.c',
