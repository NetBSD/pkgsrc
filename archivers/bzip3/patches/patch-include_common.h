$NetBSD: patch-include_common.h,v 1.2 2024/01/03 08:16:36 nros Exp $

* _*_ENDIAN is defined to nothing on solaris-like systems leading to preprocessor errors
  when == try to compare to nothing. Use if _*_ENDIAN are defined as set in sys/isa_defs.h
  on solaris-like systems to check for endianess instead of _BYTE_ORDER.

* Avoid redefinition of bswap16 on NetBSD

--- include/common.h.orig	2023-08-06 08:22:20.000000000 +0000
+++ include/common.h
@@ -93,6 +93,7 @@ static void write_neutral_s32(u8 * data,
     #error Your compiler, configuration or platform is not supported.
 #endif
 
+#ifndef __sun__
 #if !defined(__LITTLE_ENDIAN__) && !defined(__BIG_ENDIAN__)
     #if defined(_LITTLE_ENDIAN) || (defined(BYTE_ORDER) && defined(LITTLE_ENDIAN) && BYTE_ORDER == LITTLE_ENDIAN) || \
         (defined(_BYTE_ORDER) && defined(_LITTLE_ENDIAN) && _BYTE_ORDER == _LITTLE_ENDIAN) ||                        \
@@ -108,17 +109,25 @@ static void write_neutral_s32(u8 * data,
         #define __LITTLE_ENDIAN__
     #endif
 #endif
+#else
+    #ifdef _LITTLE_ENDIAN
+        #define __LITTLE_ENDIAN__
+    #endif
+    #ifdef _BIG_ENDIAN
+¨       #define __BIG_ENDIAN__
+    #endif 
+#endif
 
 #if defined(__LITTLE_ENDIAN__) && !defined(__BIG_ENDIAN__)
     #if defined(HAS_BUILTIN_BSWAP16)
-        #define bswap16(x) (__builtin_bswap16(x))
+        #define bzip3_beton16(x) (__builtin_bswap16(x))
     #elif defined(_MSC_VER) && !defined(__INTEL_COMPILER)
-        #define bswap16(x) (_byteswap_ushort(x))
+        #define bzip3_beton16(x) (_byteswap_ushort(x))
     #else
-        #define bswap16(x) ((u16)(x >> 8) | (u16)(x << 8))
+        #define bzip3_beton16(x) ((u16)(x >> 8) | (u16)(x << 8))
     #endif
 #elif !defined(__LITTLE_ENDIAN__) && defined(__BIG_ENDIAN__)
-    #define bswap16(x) (x)
+    #define bzip3_beton16(x) (x)
 #else
     #error Your compiler, configuration or platform is not supported.
 #endif
