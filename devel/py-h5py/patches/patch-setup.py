$NetBSD: patch-setup.py,v 1.1 2021/06/18 12:15:22 nia Exp $

Do not require exact numpy version.

--- setup.py.orig	2021-03-05 10:02:07.000000000 +0000
+++ setup.py
@@ -49,7 +49,7 @@ SETUP_REQUIRES = [
     "Cython >=0.29.14; python_version=='3.8'",
     "Cython >=0.29.15; python_version>='3.9'",
 ] + [
-    f"numpy =={np_min}; python_version{py_condition}"
+    f"numpy >={np_min}; python_version{py_condition}"
     for np_min, py_condition in NUMPY_MIN_VERSIONS
 ]
 
