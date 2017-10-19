$NetBSD: patch-nss_lib_freebl_verified_kremlib.h,v 1.1 2017/10/19 15:28:45 jperkin Exp $

Support SunOS byteswap macros.

--- nss/lib/freebl/verified/kremlib.h.orig	2017-09-20 06:47:27.000000000 +0000
+++ nss/lib/freebl/verified/kremlib.h
@@ -100,6 +100,23 @@ typedef void *Prims_pos, *Prims_nat, *Pr
 #define htobe32(x) OSSwapHostToBigInt32(x)
 #define be32toh(x) OSSwapBigToHostInt32(x)
 
+#elif defined(__sun__)
+#include <sys/byteorder.h>
+#define htole64(x) LE_64(x)
+#define le64toh(x) LE_IN64(x)
+#define htobe64(x) BE_64(x)
+#define be64toh(x) BE_IN64(x)
+
+#define htole16(x) LE_16(x)
+#define le16toh(x) LE_IN16(x)
+#define htobe16(x) BE_16(x)
+#define be16toh(x) BE_IN16(x)
+
+#define htole32(x) LE_32(x)
+#define le32toh(x) LE_IN32(x)
+#define htobe32(x) BE_32(x)
+#define be32toh(x) BE_IN32(x)
+
 // ... for Windows
 #elif (defined(_WIN16) || defined(_WIN32) || defined(_WIN64)) && \
     !defined(__WINDOWS__)
