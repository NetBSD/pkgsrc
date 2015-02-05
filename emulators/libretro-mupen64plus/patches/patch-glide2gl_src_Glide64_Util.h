$NetBSD: patch-glide2gl_src_Glide64_Util.h,v 1.1 2015/02/05 17:42:06 wiz Exp $

bswap32 is defined in the included headers on NetBSD.

--- glide2gl/src/Glide64/Util.h.orig	2015-02-04 18:18:28.000000000 +0000
+++ glide2gl/src/Glide64/Util.h
@@ -56,7 +56,7 @@ float ScaleZ(float z);
 #if defined(_MSC_VER) && (defined(_M_IX86) || defined(_M_X64))
 #include <stdlib.h>
 #define bswap32(x) _byteswap_ulong(x)
-#else
+#elif !defined(__NetBSD__)
 static inline uint32_t bswap32(uint32_t val)
 {
    return (((val & 0xff000000) >> 24) |
