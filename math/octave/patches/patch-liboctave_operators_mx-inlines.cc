$NetBSD: patch-liboctave_operators_mx-inlines.cc,v 1.3 2016/11/19 21:53:12 maya Exp $

std::pow is required to promote numeric arguments to the smallest
common float type. octave_int<> provides another test of template
specializations for pow() as well as explicit cast operators.
The combination of both leads to ambiguous resolutions.

https://savannah.gnu.org/bugs/?43298
https://llvm.org/bugs/show_bug.cgi?id=21083

--- liboctave/operators/mx-inlines.cc.orig	2016-11-13 15:16:10.000000000 +0000
+++ liboctave/operators/mx-inlines.cc
@@ -398,7 +398,6 @@ DEFMINMAXSPEC (float, mx_inline_xmax, >=
 
 // Let the compiler decide which pow to use, whichever best matches the
 // arguments provided.
-using std::pow;
 DEFMXMAPPER2X (mx_inline_pow, pow)
 
 // Arbitrary function appliers.
