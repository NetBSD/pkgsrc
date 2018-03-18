$NetBSD: patch-3rdparty_bx_src_mutex.cpp,v 1.1 2018/03/18 00:40:20 ryoon Exp $

--- 3rdparty/bx/src/mutex.cpp.orig	2018-02-27 15:59:06.000000000 +0000
+++ 3rdparty/bx/src/mutex.cpp
@@ -13,6 +13,7 @@
 	|| BX_PLATFORM_IOS     \
 	|| BX_PLATFORM_OSX     \
 	|| BX_PLATFORM_PS4     \
+	|| BX_PLATFORM_BSD     \
 	|| BX_PLATFORM_RPI
 #	include <pthread.h>
 #elif  BX_PLATFORM_WINDOWS \
