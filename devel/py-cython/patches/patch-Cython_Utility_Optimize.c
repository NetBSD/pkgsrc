$NetBSD: patch-Cython_Utility_Optimize.c,v 1.1 2026/08/25 10:50:00 wiz Exp $

Use std::isfinite() is C++ and isfinite() in C.
https://github.com/cython/cython/pull/7930

--- Cython/Utility/Optimize.c.orig	2026-08-22 04:59:36.772782600 +0000
+++ Cython/Utility/Optimize.c
@@ -1721,7 +1721,7 @@ static {{c_ret_type}} __Pyx_PyObject_CompareFloatInt{{
         Py_ssize_t iop2 = __Pyx_PyLong_CompactValue(op2);
         if (float_op1 {{c_op}} ((double)iop2)) {{return_true}}; else {{return_false}};
     }
-    if (unlikely(!isfinite(float_op1))) {
+    if (unlikely(!__Pyx_isfinite(float_op1))) {
         // CPython just compares inf/nan to 0.0
         if (float_op1 {{c_op}} 0.0) {{return_true}}; else {{return_false}};
     } else {
@@ -1738,7 +1738,7 @@ static {{c_ret_type}} __Pyx_PyObject_CompareFloatInt{{
         }
     }
     #else
-    if (unlikely(!isfinite(float_op1))) {
+    if (unlikely(!__Pyx_isfinite(float_op1))) {
         // CPython just compares inf/nan to 0.0
         if (float_op1 {{c_op}} 0.0) {{return_true}}; else {{return_false}};
     } else {
@@ -1787,7 +1787,7 @@ static {{c_ret_type}} __Pyx_PyObject_CompareIntFloat{{
         Py_ssize_t iop1 = __Pyx_PyLong_CompactValue(op1);
         if (((double)iop1) {{c_op}} float_op2) {{return_true}}; else {{return_false}};
     }
-    if (unlikely(!isfinite(float_op2))) {
+    if (unlikely(!__Pyx_isfinite(float_op2))) {
         // CPython just compares inf/nan to 0.0
         if (0.0 {{c_op}} float_op2) {{return_true}}; else {{return_false}};
     } else {
@@ -1804,7 +1804,7 @@ static {{c_ret_type}} __Pyx_PyObject_CompareIntFloat{{
         }
     }
     #else
-    if (unlikely(!isfinite(float_op2))) {
+    if (unlikely(!__Pyx_isfinite(float_op2))) {
         // CPython just compares inf/nan to 0.0
         if (0.0 {{c_op}} float_op2) {{return_true}}; else {{return_false}};
     } else {
