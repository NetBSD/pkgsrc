$NetBSD: patch-style_primitive.cxx,v 1.1 2012/08/06 16:51:50 jperkin Exp $

Avoid "call of overloaded 'pow(double, long int&)' is ambiguous" error.

--- style/primitive.cxx.orig	Mon Aug  6 14:50:09 2012
+++ style/primitive.cxx	Mon Aug  6 14:50:27 2012
@@ -5047,7 +5047,7 @@
     if (!argv[1]->exactIntegerValue(n2))
       return argError(interp, loc,
   		      InterpreterMessages::notAnExactInteger, 1, argv[1]);
-    return new (interp) QuantityObj(pow(d1,n2), dim1*n2);
+    return new (interp) QuantityObj(pow(d1,(double)n2), dim1*n2);
   }
   else {
     if ((q2 == ELObj::noQuantity) || (dim2 != 0))
