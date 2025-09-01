$NetBSD: patch-src_tracing_traced__value.cc,v 1.1 2025/09/01 20:57:39 wiz Exp $

Fix build on NetBSD.
https://github.com/nodejs/node/issues/59714

--- src/tracing/traced_value.cc.orig	2025-09-01 20:45:44.230556337 +0000
+++ src/tracing/traced_value.cc
@@ -87,7 +87,11 @@ std::string EscapeString(const char* val
 }
 
 std::string DoubleToCString(double v) {
+#if defined(__NetBSD__)
+  switch (fpclassify(v)) {
+#else
   switch (FPCLASSIFY_NAMESPACE::fpclassify(v)) {
+#endif
     case FP_NAN: return "\"NaN\"";
     case FP_INFINITE: return (v < 0.0 ? "\"-Infinity\"" : "\"Infinity\"");
     case FP_ZERO: return "0";
