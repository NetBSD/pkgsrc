$NetBSD: patch-src_openrct2_common.h,v 1.7 2023/09/02 07:30:35 triaxx Exp $

Add big endian support.

--- src/openrct2/common.h.orig	2021-03-13 11:17:05.000000000 +0000
+++ src/openrct2/common.h
@@ -49,6 +49,12 @@ namespace
 #        define HIBYTE(w) (static_cast<uint8_t>((static_cast<uint16_t>(w) >> 8) & 0xFF))
 #    endif // __BYTE_ORDER__
 
+#    if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
+#        define RCT2_ENDIANESS __ORDER_BIG_ENDIAN__
+#        define LOBYTE(w) (static_cast<uint8_t>((static_cast<uint16_t>(w) >> 8) & 0xFF))
+#        define HIBYTE(w) (static_cast<uint8_t>(w))
+#    endif
+
 #    ifndef RCT2_ENDIANNESS
 #        error Unknown endianness!
 #    endif // RCT2_ENDIANNESS
