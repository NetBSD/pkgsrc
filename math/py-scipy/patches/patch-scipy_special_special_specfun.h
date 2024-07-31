$NetBSD: patch-scipy_special_special_specfun.h,v 1.2 2024/07/31 18:15:38 adam Exp $

Fix error: 'isinf' was not declared in this scope; did you mean 'std::isinf'?

--- scipy/special/special/specfun.h.orig	2024-06-24 18:58:56.000000000 +0000
+++ scipy/special/special/specfun.h
@@ -26,6 +26,9 @@
         }                                                                                                              \
     } while (0)
 
+using std::isinf;
+using std::isnan;
+
 namespace special {
 
 inline std::complex<double> chyp2f1(double a, double b, double c, std::complex<double> z) {
