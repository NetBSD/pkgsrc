$NetBSD: patch-scipy_special___logit.h,v 1.1 2022/05/03 15:14:54 tnn Exp $

py-scipy: work around undefined PLT symbol "log1pl" on NetBSD

--- scipy/special/_logit.h.orig	2022-01-29 22:59:08.475390400 +0000
+++ scipy/special/_logit.h
@@ -31,15 +31,41 @@ inline T _expit(T x) {
 // obtain accurate results (compared to the naive implementation
 // log(expit(x))).
 //
-template <typename T>
-inline T _log_expit(T x) {
+inline npy_float _log_expit(npy_float x) {
     if (x < 0.0) {
         return x - std::log1p(std::exp(x));
     }
     else {
         return -std::log1p(std::exp(-x));
     }
-};
+}
+inline npy_double _log_expit(npy_double x) {
+    if (x < 0.0) {
+        return x - std::log1p(std::exp(x));
+    }
+    else {
+        return -std::log1p(std::exp(-x));
+    }
+}
+#if defined(__NetBSD__)
+inline npy_longdouble _log_expit(npy_longdouble x) {
+    if (x < 0.0) {
+        return x - std::log(1.0l + std::exp(x));
+    }
+    else {
+        return -std::log(1.0l + std::exp(-x));
+    }
+}
+#else
+inline npy_longdouble _log_expit(npy_longdouble x) {
+    if (x < 0.0) {
+        return x - std::log1p(std::exp(x));
+    }
+    else {
+        return -std::log1p(std::exp(-x));
+    }
+}
+#endif
 
 
 npy_float logitf(npy_float x)  {return _logit(x);};
