$NetBSD: patch-liboctave_operators_mx-inlines.cc,v 1.2 2016/11/19 00:47:08 maya Exp $

std::pow is required to promote numeric arguments to the smallest
common float type. octave_int<> provides another test of template
specializations for pow() as well as explicit cast operators.
The combination of both leads to ambiguous resolutions.

https://savannah.gnu.org/bugs/?43298
https://llvm.org/bugs/show_bug.cgi?id=21083

--- liboctave/operators/mx-inlines.cc.orig	2015-05-23 14:21:53.000000000 +0000
+++ liboctave/operators/mx-inlines.cc
@@ -307,7 +307,6 @@ inline void F (size_t n, R *r, X x, cons
 
 // Let the compiler decide which pow to use, whichever best matches the
 // arguments provided.
-using std::pow;
 DEFMXMAPPER2X (mx_inline_pow, pow)
 
 // Arbitrary function appliers. The function is a template parameter to enable
