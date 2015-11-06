$NetBSD: patch-common_Endianness.h,v 1.3 2015/11/06 11:33:39 wiz Exp $

bswap16 redefined on NetBSD.
http://bugs.openmpt.org/view.php?id=720

--- common/Endianness.h.orig	2015-06-13 11:59:24.000000000 +0000
+++ common/Endianness.h
@@ -28,7 +28,7 @@ OPENMPT_NAMESPACE_BEGIN
 
 #if MPT_COMPILER_GCC
 #if MPT_GCC_AT_LEAST(4,8,0)
-#define bswap16 __builtin_bswap16
+#define MPT_bswap16 __builtin_bswap16
 #endif
 #if MPT_GCC_AT_LEAST(4,3,0)
 #define MPT_bswap32 __builtin_bswap32
