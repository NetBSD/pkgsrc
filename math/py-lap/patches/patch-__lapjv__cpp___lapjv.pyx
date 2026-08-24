$NetBSD: patch-__lapjv__cpp___lapjv.pyx,v 1.1 2026/08/24 11:05:38 wiz Exp $

Work around breakage with cpython 3.3.0.
https://github.com/cython/cython/issues/7915

--- _lapjv_cpp/_lapjv.pyx.orig	2026-08-24 11:00:49.361196480 +0000
+++ _lapjv_cpp/_lapjv.pyx
@@ -7,6 +7,12 @@ from libc.stdlib cimport malloc, free
 from libc.stdlib cimport malloc, free
 
 
+cdef extern from * nogil:
+    """
+    #include <cmath>
+    using std::isfinite;
+    """
+
 cdef extern from "lapjv.h" nogil:
     ctypedef signed int int_t
     ctypedef unsigned int uint_t
