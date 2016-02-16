$NetBSD: patch-liboctave_operators_mx-inlines.cc,v 1.1 2016/02/16 04:21:40 dbj Exp $

std::pow is required to promote numeric arguments to the smallest
common float type. octave_int<> provides another test of template
specializations for pow() as well as explicit cast operators.
The combination of both leads to ambiguous resolutions.

--- liboctave/operators/mx-inlines.cc.orig	2015-05-23 14:21:53.000000000 +0000
+++ liboctave/operators/mx-inlines.cc
@@ -307,7 +307,6 @@ inline void F (size_t n, R *r, X x, cons
 
 // Let the compiler decide which pow to use, whichever best matches the
 // arguments provided.
-using std::pow;
 DEFMXMAPPER2X (mx_inline_pow, pow)
 
 // Arbitrary function appliers. The function is a template parameter to enable
