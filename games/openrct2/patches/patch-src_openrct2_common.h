$NetBSD: patch-src_openrct2_common.h,v 1.3 2023/07/22 02:15:16 triaxx Exp $

Take a stab at supporting big-endian ports.

--- src/openrct2/common.h.orig	2020-04-17 14:13:30.000000000 +0000
+++ src/openrct2/common.h
@@ -92,6 +92,12 @@ namespace
 #        define HIBYTE(w) ((uint8_t)(((uint16_t)(w) >> 8) & 0xFF))
 #    endif // __BYTE_ORDER__
 
+#    if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
+#        define RCT2_ENDIANESS __ORDER_BIG_ENDIAN__
+#        define LOBYTE(w) ((uint8_t)(((uint16_t)(w) >> 8) & 0xFF))
+#        define HIBYTE(w) ((uint8_t)(w))
+#    endif
+ 
 #    ifndef RCT2_ENDIANESS
 #        error Unknown endianess!
 #    endif // RCT2_ENDIANESS
