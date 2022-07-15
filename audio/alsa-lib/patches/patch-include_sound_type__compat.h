$NetBSD: patch-include_sound_type__compat.h,v 1.3 2022/07/15 21:17:25 wiz Exp $

NetBSD and Solaris support.

--- include/sound/type_compat.h.orig	2020-06-29 10:51:08.000000000 +0000
+++ include/sound/type_compat.h
@@ -15,7 +15,30 @@ typedef int16_t __s16;
 typedef int32_t __s32;
 typedef int64_t __s64;
 
+#ifndef __sun
 #include <endian.h>
+#endif
+#if defined(__NetBSD__)
+#include <machine/bswap.h>
+#if BYTE_ORDER == LITTLE_ENDIAN
+#define __cpu_to_le32(x) (x)
+#define __cpu_to_be32(x) bswap32(x)
+#define __cpu_to_le16(x) (x)
+#define __cpu_to_be16(x) bswap16(x)
+#else
+#define __cpu_to_le32(x) bswap32(x)
+#define __cpu_to_be32(x) (x)
+#define __cpu_to_le16(x) bswap16(x)
+#define __cpu_to_be16(x) (x)
+#endif
+#else
+#ifdef __sun
+#include <sys/byteorder.h>
+#define __cpu_to_le32(x) LE_32(x)
+#define __cpu_to_be32(x) BE_32(x)
+#define __cpu_to_le16(x) LE_16(x)
+#define __cpu_to_be16(x) BE_16(x)
+#else
 #include <byteswap.h>
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 #define __cpu_to_le32(x) (x)
@@ -28,6 +51,8 @@ typedef int64_t __s64;
 #define __cpu_to_le16(x) bswap_16(x)
 #define __cpu_to_be16(x) (x)
 #endif
+#endif
+#endif
 
 #define __le32_to_cpu __cpu_to_le32
 #define __be32_to_cpu __cpu_to_be32
