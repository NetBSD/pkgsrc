$NetBSD: patch-media_ffvpx_libavutil_arm_bswap.h,v 1.1 2023/02/05 08:32:24 he Exp $

--- media/ffvpx/libavutil/arm/bswap.h.orig	2020-08-28 21:33:11.000000000 +0000
+++ media/ffvpx/libavutil/arm/bswap.h
@@ -23,6 +23,8 @@
 #include "config.h"
 #include "libavutil/attributes.h"
 
+#ifndef __aarch64__
+
 #ifdef __ARMCC_VERSION
 
 #if HAVE_ARMV6
@@ -64,4 +66,6 @@ static av_always_inline av_const uint32_
 
 #endif /* __ARMCC_VERSION */
 
+#endif /* __aarch64__ */
+
 #endif /* AVUTIL_ARM_BSWAP_H */
