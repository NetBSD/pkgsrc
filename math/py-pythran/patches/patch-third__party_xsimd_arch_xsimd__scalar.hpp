$NetBSD: patch-third__party_xsimd_arch_xsimd__scalar.hpp,v 1.1 2023/01/25 09:06:54 adam Exp $

https://github.com/serge-sans-paille/pythran/issues/2070

--- third_party/xsimd/arch/xsimd_scalar.hpp.orig	2023-01-25 08:48:11.000000000 +0000
+++ third_party/xsimd/arch/xsimd_scalar.hpp
@@ -441,7 +441,7 @@ namespace xsimd
         return !(x0 == x1);
     }
 
-#if defined(_GNU_SOURCE) && !defined(__APPLE__) && !defined(__MINGW32__) && !defined(__ANDROID__)
+#if defined(_GNU_SOURCE) && !defined(__APPLE__) && !defined(__MINGW32__) && !defined(__ANDROID__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__) && !defined(__DragonFly__)
     inline float exp10(const float& x) noexcept
     {
         return ::exp10f(x);
