$NetBSD: patch-src_include_OpenImageIO_typedesc.h,v 1.2 2025/08/13 06:51:22 wiz Exp $

https://github.com/AcademySoftwareFoundation/OpenImageIO/pull/4857

--- src/include/OpenImageIO/typedesc.h.orig	2025-08-13 06:24:05.048800007 +0000
+++ src/include/OpenImageIO/typedesc.h
@@ -401,7 +401,7 @@ template<> struct BaseTypeFromC<uint32_t
 template<> struct BaseTypeFromC<int32_t> { static const TypeDesc::BASETYPE value = TypeDesc::INT; };
 template<> struct BaseTypeFromC<uint64_t> { static const TypeDesc::BASETYPE value = TypeDesc::UINT64; };
 template<> struct BaseTypeFromC<int64_t> { static const TypeDesc::BASETYPE value = TypeDesc::INT64; };
-#if defined(__GNUC__) && __WORDSIZE == 64 && !(defined(__APPLE__) && defined(__MACH__))
+#if defined(__GNUC__) && __WORDSIZE == 64 && !(defined(__APPLE__) && defined(__MACH__)) || defined(__NetBSD__)
 // Some platforms consider int64_t and long long to be different types, even
 // though they are actually the same size.
 static_assert(!std::is_same_v<unsigned long long, uint64_t>);
