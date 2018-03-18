$NetBSD: patch-3rdparty_bx_src_thread.cpp,v 1.1 2018/03/18 00:40:20 ryoon Exp $

--- 3rdparty/bx/src/thread.cpp.orig	2018-02-27 15:59:06.000000000 +0000
+++ 3rdparty/bx/src/thread.cpp
@@ -11,6 +11,7 @@
 	|| BX_PLATFORM_IOS     \
 	|| BX_PLATFORM_OSX     \
 	|| BX_PLATFORM_PS4     \
+	|| BX_PLATFORM_BSD     \
 	|| BX_PLATFORM_RPI
 #	include <pthread.h>
 #	if defined(__FreeBSD__)
