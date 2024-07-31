$NetBSD: patch-scipy_special_special_specfun_specfun.h,v 1.1 2024/07/31 18:15:38 adam Exp $

Prefer C++ copysign().

--- scipy/special/special/specfun/specfun.h.orig	2024-07-31 10:16:24.693973249 +0000
+++ scipy/special/special/specfun/specfun.h
@@ -2096,7 +2096,7 @@ std::complex<T> e1z(std::complex<T> z) {
         if ((x <= 0.0) && (z.imag() == 0.0)) {
             //Careful on the branch cut -- use the sign of the imaginary part
             // to get the right sign on the factor if pi.
-            ce1 = -el - std::log(-z) + z*ce1 - copysign(pi, z.imag())*std::complex<T>(0.0, 1.0);
+            ce1 = -el - std::log(-z) + z*ce1 - std::copysign(pi, z.imag())*std::complex<T>(0.0, 1.0);
         } else {
             ce1 = -el - std::log(z) + z*ce1;
         }
