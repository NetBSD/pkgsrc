$NetBSD: patch-liboctave_operators_mx-inlines.cc,v 1.4 2018/08/12 08:33:55 maya Exp $

std::pow is required to promote numeric arguments to the smallest
common float type. octave_int<> provides another test of template
specializations for pow() as well as explicit cast operators.
The combination of both leads to ambiguous resolutions.

https://savannah.gnu.org/bugs/?43298
https://llvm.org/bugs/show_bug.cgi?id=21083

--- liboctave/operators/mx-inlines.cc.orig	2018-08-09 18:20:32.000000000 +0000
+++ liboctave/operators/mx-inlines.cc
@@ -412,7 +412,6 @@ template <typename R, typename X, typena
 inline void
 mx_inline_pow (size_t n, R *r, const X *x, const Y *y)
 {
-  using std::pow;
 
   for (size_t i = 0; i < n; i++)
     r[i] = pow (x[i], y[i]);
