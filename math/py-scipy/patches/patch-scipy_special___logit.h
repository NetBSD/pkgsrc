$NetBSD: patch-scipy_special___logit.h,v 1.2 2022/05/13 09:49:31 tnn Exp $

py-scipy: work around undefined PLT symbol "log1pl" on NetBSD

--- scipy/special/_logit.h.orig	2022-01-29 22:59:08.000000000 +0000
+++ scipy/special/_logit.h
@@ -31,6 +31,17 @@ inline T _expit(T x) {
 // obtain accurate results (compared to the naive implementation
 // log(expit(x))).
 //
+#if defined(__NetBSD__)
+template <typename T>
+inline T _log_expit(T x) {
+    if (x < 0.0) {
+        return x - std::log(std::exp(x) + 1.0);
+    }
+    else {
+        return -std::log(std::exp(-x) + 1.0);
+    }
+};
+#else
 template <typename T>
 inline T _log_expit(T x) {
     if (x < 0.0) {
@@ -40,6 +51,7 @@ inline T _log_expit(T x) {
         return -std::log1p(std::exp(-x));
     }
 };
+#endif
 
 
 npy_float logitf(npy_float x)  {return _logit(x);};
