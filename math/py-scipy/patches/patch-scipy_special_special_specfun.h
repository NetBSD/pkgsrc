$NetBSD: patch-scipy_special_special_specfun.h,v 1.1 2024/04/19 19:24:25 adam Exp $

Fix error: 'isinf' was not declared in this scope; did you mean 'std::isinf'?

--- scipy/special/special/specfun.h.orig	2024-04-19 14:03:19.375569416 +0000
+++ scipy/special/special/specfun.h
@@ -26,6 +26,9 @@
         }                                                                                                              \
     } while (0)
 
+using std::isinf;
+using std::isnan;
+
 namespace special {
 
 inline int cem(double m, double q, double x, double *csf, double *csd);
