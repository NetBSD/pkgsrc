$NetBSD: patch-libcurvecpr_include_curvecpr_block.h,v 1.1 2019/12/22 22:28:54 joerg Exp $

--- libcurvecpr/include/curvecpr/block.h.orig	2019-12-22 17:54:24.664262284 +0000
+++ libcurvecpr/include/curvecpr/block.h
@@ -2,9 +2,7 @@
 #define __CURVECPR_BLOCK_H
 
 #include <string.h>
-
-#include <sodium/crypto_uint32.h>
-#include <sodium/crypto_uint64.h>
+#include <curvecpr/bytes.h>
 
 enum curvecpr_block_eofflag {
     CURVECPR_BLOCK_STREAM,
