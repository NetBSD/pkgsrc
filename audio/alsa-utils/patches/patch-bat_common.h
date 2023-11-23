$NetBSD: patch-bat_common.h,v 1.1 2023/11/23 16:15:04 ryoon Exp $

--- bat/common.h.orig	2023-09-01 15:36:26.000000000 +0000
+++ bat/common.h
@@ -13,6 +13,11 @@
  *
  */
 
+#ifndef ATTRIBUTE_UNUSED
+/** do not print warning (gcc) when function parameter is not used */
+#define ATTRIBUTE_UNUSED __attribute__ ((__unused__))
+#endif
+
 #define TEMP_RECORD_FILE_NAME		"/tmp/bat.wav.XXXXXX"
 #define DEFAULT_DEV_NAME		"default"
 
