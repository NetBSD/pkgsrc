$NetBSD: patch-tests_test-quantize-fns.cpp,v 1.1 2026/11/04 17:07:04 wiz Exp $

error: 'isnan' was not declared in this scope; did you mean 'std::isnan'?
error: 'signbit' was not declared in this scope; did you mean 'std::signbit'?
https://github.com/ggml-org/ggml/issues/1681

--- tests/test-quantize-fns.cpp.orig	2026-11-04 17:03:17.251240863 +0000
+++ tests/test-quantize-fns.cpp
@@ -177,10 +177,10 @@ static uint8_t fp32_to_f8_e4m3_ref(float value) {
 };
 
 static uint8_t fp32_to_f8_e4m3_ref(float value) {
-    if (isnan(value)) {
+    if (std::isnan(value)) {
         return 0x7F;
     }
-    const uint8_t sign = signbit(value) ? 0x80 : 0;
+    const uint8_t sign = std::signbit(value) ? 0x80 : 0;
     const double magnitude = fabs((double) value);
     if (magnitude >= F8_E4M3_VALUES[126]) {
         return sign | 126;
@@ -222,8 +222,8 @@ static int test_f8_e4m3(bool verbose) {
     for (int i = 0; i < 256; ++i) {
         const bool is_nan = (i & 0x7F) == 0x7F;
         const float expected = is_nan ? NAN : copysignf(F8_E4M3_VALUES[i & 0x7F], i & 0x80 ? -1.0f : 1.0f);
-        const bool decode_failed = is_nan ? !isnan(decoded[i])
-            : decoded[i] != expected || (expected == 0.0f && signbit(decoded[i]) != signbit(expected));
+        const bool decode_failed = is_nan ? !std::isnan(decoded[i])
+            : decoded[i] != expected || (expected == 0.0f && std::signbit(decoded[i]) != std::signbit(expected));
         const bool encode_failed = !is_nan && roundtrip[i] != encoded[i];
         if (decode_failed || encode_failed) {
             num_failed++;
@@ -293,7 +293,7 @@ static int test_f8_e4m3(bool verbose) {
         x[0] = x.back() = code;
         float actual;
         traits_cpu->vec_dot(x.size(), &actual, 0, x.data(), 0, y.data(), 0, 1);
-        num_failed += !isnan(actual);
+        num_failed += !std::isnan(actual);
     }
 
     if (verbose || num_failed) {
