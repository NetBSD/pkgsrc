$NetBSD: patch-include_sound_type__compat.h,v 1.1 2021/05/12 14:12:13 ryoon Exp $

--- include/sound/type_compat.h.orig	2020-06-29 10:51:08.000000000 +0000
+++ include/sound/type_compat.h
@@ -1,5 +1,5 @@
-#ifndef __TYPE_COMPAT_H
-#define __TYPE_COMPAT_H
+#ifndef __SOUND_TYPE_COMPAT_H
+#define __SOUND_TYPE_COMPAT_H
 
 #ifndef DOC_HIDDEN
 #include <stdint.h>
@@ -16,6 +16,20 @@ typedef int32_t __s32;
 typedef int64_t __s64;
 
 #include <endian.h>
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
 #include <byteswap.h>
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 #define __cpu_to_le32(x) (x)
@@ -28,6 +42,7 @@ typedef int64_t __s64;
 #define __cpu_to_le16(x) bswap_16(x)
 #define __cpu_to_be16(x) (x)
 #endif
+#endif
 
 #define __le32_to_cpu __cpu_to_le32
 #define __be32_to_cpu __cpu_to_be32
@@ -54,4 +69,4 @@ typedef int64_t __s64;
 
 #endif /* DOC_HIDDEN */
 
-#endif /* __TYPE_COMPAT_H */
+#endif /* __SOUND_TYPE_COMPAT_H */
