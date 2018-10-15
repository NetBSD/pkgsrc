$NetBSD: patch-Source_Core_Common_Swap.h,v 1.1 2018/10/15 17:20:21 nia Exp $

Support NetBSD.

--- Source/Core/Common/Swap.h.orig	2018-08-27 13:59:39.000000000 +0000
+++ Source/Core/Common/Swap.h
@@ -13,7 +13,7 @@
 #include <byteswap.h>
 #elif defined(__FreeBSD__)
 #include <sys/endian.h>
-#elif defined(__OpenBSD__)
+#elif defined(__NetBSD__) || defined(__OpenBSD__)
 #include <endian.h>
 #endif
 
