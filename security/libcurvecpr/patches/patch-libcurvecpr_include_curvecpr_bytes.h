$NetBSD: patch-libcurvecpr_include_curvecpr_bytes.h,v 1.1 2019/12/22 22:28:54 joerg Exp $

--- libcurvecpr/include/curvecpr/bytes.h.orig	2019-12-22 17:51:15.224837301 +0000
+++ libcurvecpr/include/curvecpr/bytes.h
@@ -2,10 +2,11 @@
 #define __LIBCURVECPR_BYTES_H
 
 #include <string.h>
+#include <inttypes.h>
 
-#include <sodium/crypto_uint16.h>
-#include <sodium/crypto_uint32.h>
-#include <sodium/crypto_uint64.h>
+typedef uint16_t crypto_uint16;
+typedef uint32_t crypto_uint32;
+typedef uint64_t crypto_uint64;
 
 void curvecpr_bytes_copy (void *destination, const void *source, size_t num);
 void curvecpr_bytes_zero (void *destination, size_t num);
