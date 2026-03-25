$NetBSD: patch-src_charconv.cpp,v 1.2 2026/03/25 22:56:26 wiz Exp $

#if out some code that doesn't compile with GCC < 11 for now

--- src/charconv.cpp.orig	2025-04-29 23:05:17.000000000 +0000
+++ src/charconv.cpp
@@ -34,6 +34,7 @@ _LIBCPP_EXPORTED_FROM_ABI char* __u64toa
 
 // This implementation is dedicated to the memory of Mary and Thavatchai.
 
+#if _LIBCPP_STD_VER > 17
 to_chars_result to_chars(char* __first, char* __last, float __value) {
   return _Floating_to_chars<_Floating_to_chars_overload::_Plain>(__first, __last, __value, chars_format{}, 0);
 }
@@ -74,6 +75,7 @@ to_chars_result to_chars(char* __first,
   return _Floating_to_chars<_Floating_to_chars_overload::_Format_precision>(
       __first, __last, static_cast<double>(__value), __fmt, __precision);
 }
+#endif
 
 template <class _Fp>
 __from_chars_result<_Fp> __from_chars_floating_point(
