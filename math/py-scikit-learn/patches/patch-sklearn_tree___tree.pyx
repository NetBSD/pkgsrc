$NetBSD: patch-sklearn_tree___tree.pyx,v 1.1 2023/11/13 10:42:42 wiz Exp $

Fix build on NetBSD.

--- sklearn/tree/_tree.pyx.orig	2023-10-23 10:11:35.000000000 +0000
+++ sklearn/tree/_tree.pyx
@@ -18,7 +18,7 @@ from libc.stdlib cimport free
 from libc.string cimport memcpy
 from libc.string cimport memset
 from libc.stdint cimport INTPTR_MAX
-from libc.math cimport isnan
+from libcpp.cmath cimport isnan as isnan
 from libcpp.vector cimport vector
 from libcpp.algorithm cimport pop_heap
 from libcpp.algorithm cimport push_heap
