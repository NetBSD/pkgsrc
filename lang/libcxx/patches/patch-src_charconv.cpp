$NetBSD: patch-src_charconv.cpp,v 1.1 2022/08/13 09:38:09 tnn Exp $

#if out some code that doesn't compile with GCC < 11 for now

--- src/charconv.cpp.orig	2022-06-22 16:46:24.000000000 +0000
+++ src/charconv.cpp
@@ -152,6 +152,7 @@ __u64toa(uint64_t value, char* buffer) n
 
 // This implementation is dedicated to the memory of Mary and Thavatchai.
 
+#if _LIBCPP_STD_VER > 17
 to_chars_result to_chars(char* __first, char* __last, float __value) {
   return _Floating_to_chars<_Floating_to_chars_overload::_Plain>(__first, __last, __value, chars_format{}, 0);
 }
@@ -192,5 +193,6 @@ to_chars_result to_chars(char* __first, 
   return _Floating_to_chars<_Floating_to_chars_overload::_Format_precision>(
       __first, __last, static_cast<double>(__value), __fmt, __precision);
 }
+#endif
 
 _LIBCPP_END_NAMESPACE_STD
