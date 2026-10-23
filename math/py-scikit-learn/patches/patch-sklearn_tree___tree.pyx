$NetBSD: patch-sklearn_tree___tree.pyx,v 1.2 2026/10/23 12:18:46 adam Exp $

Fix build on NetBSD.

--- sklearn/tree/_tree.pyx.orig	2026-09-10 05:14:20.000000000 +0000
+++ sklearn/tree/_tree.pyx
@@ -3,7 +3,8 @@
 
 from cpython cimport Py_INCREF, PyObject, PyTypeObject
 
-from libc.math cimport INFINITY, isnan
+from libc.math cimport INFINITY
+from libcpp.cmath cimport isnan as isnan
 from libc.stdlib cimport free
 from libc.string cimport memcpy
 from libc.string cimport memset
