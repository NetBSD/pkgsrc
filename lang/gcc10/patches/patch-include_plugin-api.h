$NetBSD: patch-include_plugin-api.h,v 1.1 2024/04/01 14:33:57 js Exp $

QNX uses __LITTLEENDIAN__ / __BIGENDIAN__, so detect based on that as well.

--- include/plugin-api.h.orig	2023-07-07 07:08:21.000000000 +0000
+++ include/plugin-api.h
@@ -89,6 +89,13 @@
 #ifdef __BIG_ENDIAN__
 #define PLUGIN_BIG_ENDIAN 1
 #endif
+/* Detect based on __BIGENDIAN__ and __LITTLEENDIAN__ */
+#ifdef __LITTLEENDIAN__
+#define PLUGIN_LITTLE_ENDIAN 1
+#endif
+#ifdef __BIGENDIAN__
+#define PLUGIN_BIG_ENDIAN 1
+#endif
 #endif
 
 #ifdef __cplusplus
