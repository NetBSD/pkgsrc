$NetBSD: patch-Source_ePC-8801MA_common.h,v 1.1 2019/09/07 00:36:34 tsutsui Exp $

- add NetBSD denitions

--- Source/ePC-8801MA/common.h.orig	2017-12-20 04:10:42.000000000 +0000
+++ Source/ePC-8801MA/common.h
@@ -33,6 +33,24 @@ typedef int errno_t;
 #define strnicmp strncasecmp
 #define stricmp strcasecmp
 #endif	// __linux__
+// NetBSD
+#ifdef __NetBSD__
+#include <types.h>
+#include <endian.h>
+#include <sys/param.h>
+#if BYTE_ORDER == LITTLE_ENDIAN
+#define __LITTLE_ENDIAN__
+#endif // BYTE_ORDER == LITTLE_ENDIAN
+#define _MAX_PATH			MAXPATHLEN
+#define __min	min
+#define __stdcall
+typedef int errno_t;
+typedef uint8_t Uint8;
+typedef uint16_t Uint16;
+typedef uint32_t Uint32;
+#define strnicmp strncasecmp
+#define stricmp strcasecmp
+#endif	// __NetBSD__
 
 // max() and min() macro
 #ifndef max
