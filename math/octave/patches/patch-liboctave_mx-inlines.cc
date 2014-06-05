$NetBSD: patch-liboctave_mx-inlines.cc,v 1.1 2014/06/05 18:33:07 joerg Exp $

std::pow is required to promote numeric arguments to the smallest
common float type. octave_int<> provides another test of template
specialisations for pow() as well as explicit cast operators.
The combination of both leads to ambiguous resolutions.

--- liboctave/mx-inlines.cc.orig	2014-06-04 22:00:01.000000000 +0000
+++ liboctave/mx-inlines.cc
@@ -306,7 +306,6 @@ inline void F (size_t n, R *r, X x, cons
 
 // Let the compiler decide which pow to use, whichever best matches the
 // arguments provided.
-using std::pow;
 DEFMXMAPPER2X (mx_inline_pow, pow)
 
 // Arbitrary function appliers. The function is a template parameter to enable
