$NetBSD: patch-src_openrct2_common.h,v 1.4 2023/07/22 10:55:16 triaxx Exp $

Take a stab at supporting big-endian ports.

--- src/openrct2/common.h.orig	2020-08-15 19:13:50.000000000 +0000
+++ src/openrct2/common.h
@@ -91,6 +91,12 @@ namespace
 #        define LOBYTE(w) (static_cast<uint8_t>(w))
 #        define HIBYTE(w) (static_cast<uint8_t>((static_cast<uint16_t>(w) >> 8) & 0xFF))
 #    endif // __BYTE_ORDER__
+ 
+#    if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
+#        define RCT2_ENDIANESS __ORDER_BIG_ENDIAN__
+#        define LOBYTE(w) (static_cast<uint8_t>((static_cast<uint16_t>(w) >> 8) & 0xFF))
+#        define HIBYTE(w) (static_cast<uint8_t>(w))
+#    endif
 
 #    ifndef RCT2_ENDIANESS
 #        error Unknown endianess!
