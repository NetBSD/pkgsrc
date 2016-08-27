$NetBSD: patch-endian.h,v 1.1 2016/08/27 11:53:39 nonaka Exp $

--- endian.h.orig	2010-08-25 16:54:11.000000000 +0000
+++ endian.h	2016-08-25 06:19:59.000000000 +0000
@@ -19,6 +19,7 @@
 #ifndef ENDIAN_H
 #define ENDIAN_H
 
+#if defined(__linux__)
 #include <endian.h>
 
 #if __BYTE_ORDER == __LITTLE_ENDIAN
@@ -48,6 +49,63 @@
 #define le32_to_cpu(x) __bswap_32(x)
 #define le64_to_cpu(x) __bswap_64(x)
 #endif
+#elif defined(__APPLE__)
+#include <libkern/OSByteOrder.h>
+#define cpu_to_be16(x) OSSwapHostToBigInt16(x)
+#define cpu_to_be32(x) OSSwapHostToBigInt32(x)
+#define cpu_to_be64(x) OSSwapHostToBigInt64(x)
+#define be16_to_cpu(x) OSSwapBigToHostInt16(x)
+#define be32_to_cpu(x) OSSwapBigToHostInt32(x)
+#define be64_to_cpu(x) OSSwapBigToHostInt64(x)
+#define cpu_to_le16(x) OSSwapHostToLittleInt16(x)
+#define cpu_to_le32(x) OSSwapHostToLittleInt32(x)
+#define cpu_to_le64(x) OSSwapHostToLittleInt64(x)
+#define le16_to_cpu(x) OSSwapLittleToHostInt16(x)
+#define le32_to_cpu(x) OSSwapLittleToHostInt32(x)
+#define le64_to_cpu(x) OSSwapLittleToHostInt64(x)
+#elif defined(__sun__)
+#include <sys/byteorder.h>
+#define cpu_to_be16(x) BE_16(x)
+#define cpu_to_be32(x) BE_32(x)
+#define cpu_to_be64(x) BE_64(x)
+#define be16_to_cpu(x) BE_IN16(x)
+#define be32_to_cpu(x) BE_IN32(x)
+#define be64_to_cpu(x) BE_IN64(x)
+#define cpu_to_le16(x) LE_16(x)
+#define cpu_to_le32(x) LE_32(x)
+#define cpu_to_le64(x) LE_64(x)
+#define le16_to_cpu(x) LE_IN16(x)
+#define le32_to_cpu(x) LE_IN32(x)
+#define le64_to_cpu(x) LE_IN64(x)
+#elif defined(__OpenBSD__)
+#include <sys/endian.h>
+#define cpu_to_be16(x) htobe16(x)
+#define cpu_to_be32(x) htobe32(x)
+#define cpu_to_be64(x) htobe64(x)
+#define be16_to_cpu(x) betoh16(x)
+#define be32_to_cpu(x) betoh32(x)
+#define be64_to_cpu(x) betoh64(x)
+#define cpu_to_le16(x) htole16(x)
+#define cpu_to_le32(x) htole32(x)
+#define cpu_to_le64(x) htole64(x)
+#define le16_to_cpu(x) letoh16(x)
+#define le32_to_cpu(x) letoh32(x)
+#define le64_to_cpu(x) letoh64(x)
+#else /* *BSD */
+#include <sys/endian.h>
+#define cpu_to_be16(x) htobe16(x)
+#define cpu_to_be32(x) htobe32(x)
+#define cpu_to_be64(x) htobe64(x)
+#define be16_to_cpu(x) be16toh(x)
+#define be32_to_cpu(x) be32toh(x)
+#define be64_to_cpu(x) be64toh(x)
+#define cpu_to_le16(x) htole16(x)
+#define cpu_to_le32(x) htole32(x)
+#define cpu_to_le64(x) htole64(x)
+#define le16_to_cpu(x) le16toh(x)
+#define le32_to_cpu(x) le32toh(x)
+#define le64_to_cpu(x) le64toh(x)
+#endif
 
 #endif /* ENDIAN_H */
 /* vim:set shiftwidth=8 softtabstop=8: */
