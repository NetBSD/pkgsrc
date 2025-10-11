$NetBSD: patch-libstdc++-v3_include_bits_valarray_after.h,v 1.1 2025/10/11 16:14:19 js Exp $

--- libstdc++-v3/include/bits/valarray_after.h.orig	2025-10-10 21:07:12.000000000 +0000
+++ libstdc++-v3/include/bits/valarray_after.h
@@ -439,20 +439,20 @@ _GLIBCXX_BEGIN_NAMESPACE_VERSION
       return _Expr<_Closure, _Tp>(_Closure(__v));                        \
     }
 
-    _DEFINE_EXPR_UNARY_FUNCTION(abs, _Abs)
-    _DEFINE_EXPR_UNARY_FUNCTION(cos, _Cos)
-    _DEFINE_EXPR_UNARY_FUNCTION(acos, _Acos)
-    _DEFINE_EXPR_UNARY_FUNCTION(cosh, _Cosh)
-    _DEFINE_EXPR_UNARY_FUNCTION(sin, _Sin)
-    _DEFINE_EXPR_UNARY_FUNCTION(asin, _Asin)
-    _DEFINE_EXPR_UNARY_FUNCTION(sinh, _Sinh)
-    _DEFINE_EXPR_UNARY_FUNCTION(tan, _Tan)
-    _DEFINE_EXPR_UNARY_FUNCTION(tanh, _Tanh)
-    _DEFINE_EXPR_UNARY_FUNCTION(atan, _Atan)
-    _DEFINE_EXPR_UNARY_FUNCTION(exp, _Exp)
-    _DEFINE_EXPR_UNARY_FUNCTION(log, _Log)
-    _DEFINE_EXPR_UNARY_FUNCTION(log10, _Log10)
-    _DEFINE_EXPR_UNARY_FUNCTION(sqrt, _Sqrt)
+    _DEFINE_EXPR_UNARY_FUNCTION(abs, struct _Abs)
+    _DEFINE_EXPR_UNARY_FUNCTION(cos, struct _Cos)
+    _DEFINE_EXPR_UNARY_FUNCTION(acos, struct _Acos)
+    _DEFINE_EXPR_UNARY_FUNCTION(cosh, struct _Cosh)
+    _DEFINE_EXPR_UNARY_FUNCTION(sin, struct _Sin)
+    _DEFINE_EXPR_UNARY_FUNCTION(asin, struct _Asin)
+    _DEFINE_EXPR_UNARY_FUNCTION(sinh, struct _Sinh)
+    _DEFINE_EXPR_UNARY_FUNCTION(tan, struct _Tan)
+    _DEFINE_EXPR_UNARY_FUNCTION(tanh, struct _Tanh)
+    _DEFINE_EXPR_UNARY_FUNCTION(atan, struct _Atan)
+    _DEFINE_EXPR_UNARY_FUNCTION(exp, struct _Exp)
+    _DEFINE_EXPR_UNARY_FUNCTION(log, struct _Log)
+    _DEFINE_EXPR_UNARY_FUNCTION(log10, struct _Log10)
+    _DEFINE_EXPR_UNARY_FUNCTION(sqrt, struct _Sqrt)
 
 #undef _DEFINE_EXPR_UNARY_FUNCTION
 
