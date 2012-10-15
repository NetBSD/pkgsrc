$NetBSD: patch-tagutils_misc.c,v 1.1 2012/10/15 22:48:02 drochner Exp $

--- tagutils/misc.c.orig	2012-10-15 19:24:13.000000000 +0000
+++ tagutils/misc.c
@@ -21,24 +21,35 @@
 
 #include <stdio.h>
 #include <string.h>
+#ifdef __NetBSD__
+#include <sys/endian.h>
+#else
 #include <endian.h>
+#endif
 
 #include "misc.h"
 
-inline __u16
+__u16
 le16_to_cpu(__u16 le16)
 {
+#ifdef __NetBSD__
+	return le16toh(le16);
+#else
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 	return le16;
 #else
 	__u16 be16 = ((le16 << 8) & 0xff00) | ((le16 >> 8) & 0x00ff);
 	return be16;
 #endif
+#endif
 }
 
-inline __u32
+__u32
 le32_to_cpu(__u32 le32)
 {
+#ifdef __NetBSD__
+	return le32toh(le32);
+#else
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 	return le32;
 #else
@@ -49,11 +60,15 @@ le32_to_cpu(__u32 le32)
 		((le32 >> 24) & 0x000000ff);
 	return be32;
 #endif
+#endif
 }
 
-inline __u64
+__u64
 le64_to_cpu(__u64 le64)
 {
+#ifdef __NetBSD__
+	return le64toh(le64);
+#else
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 	return le64;
 #else
@@ -70,6 +85,7 @@ le64_to_cpu(__u64 le64)
 	be64p[7] = le64p[0];
 	return be64;
 #endif
+#endif
 }
 
 inline __u8
@@ -101,9 +117,12 @@ fget_le32(FILE *fp)
 	return d;
 }
 
-inline __u32
+__u32
 cpu_to_be32(__u32 cpu32)
 {
+#ifdef __NetBSD__
+	return htole32(cpu32);
+#else
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 	__u32 be32 =
 		((cpu32 << 24) & 0xff000000) |
@@ -114,4 +133,5 @@ cpu_to_be32(__u32 cpu32)
 #else
 	return cpu32;
 #endif
+#endif
 }
