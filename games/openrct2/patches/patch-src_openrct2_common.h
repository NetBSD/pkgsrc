$NetBSD: patch-src_openrct2_common.h,v 1.1 2022/12/15 19:26:35 he Exp $

Take a stab at supporting big-endian ports.

--- src/openrct2/common.h.orig	2019-10-28 20:18:47.000000000 +0000
+++ src/openrct2/common.h
@@ -73,6 +73,12 @@ const constexpr auto ror64 = ror<uint64_
 #        define HIBYTE(w) ((uint8_t)(((uint16_t)(w) >> 8) & 0xFF))
 #    endif // __BYTE_ORDER__
 
+#    if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
+#	 define RCT2_ENDIANESS __ORDER_BIG_ENDIAN__
+#	 define LOBYTE(w) ((uint8_t)(((uint16_t)(w) >> 8) & 0xFF))
+#	 define HIBYTE(w) ((uint8_t)(w))
+#    endif
+
 #    ifndef RCT2_ENDIANESS
 #        error Unknown endianess!
 #    endif // RCT2_ENDIANESS
