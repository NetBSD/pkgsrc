$NetBSD: patch-libs_charconv_src_float128__impl.hpp,v 1.1 2024/10/10 14:44:17 jperkin Exp $

Workaround system header issue on SunOS.

--- libs/charconv/src/float128_impl.hpp.orig	2024-10-10 14:05:35.495301016 +0000
+++ libs/charconv/src/float128_impl.hpp
@@ -92,7 +92,11 @@ inline __float128 to_float128(Unsigned_I
 template <>
 inline __float128 to_float128<uint128>(uint128 w) noexcept
 {
+#ifdef __sun
+    return ldexpq(static_cast<__float128>(w.high), 64) + static_cast<__float128>(w.low);
+#else
     return ldexp(static_cast<__float128>(w.high), 64) + static_cast<__float128>(w.low);
+#endif
 }
 
 template <typename Unsigned_Integer, typename ArrayPtr>
