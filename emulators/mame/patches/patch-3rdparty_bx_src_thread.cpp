$NetBSD: patch-3rdparty_bx_src_thread.cpp,v 1.6 2025/07/01 18:20:51 wiz Exp $

NetBSD does not provide pthread_np.h.
https://github.com/bkaradzic/bx/issues/295

--- 3rdparty/bx/src/thread.cpp.orig	2025-06-28 20:55:26.000000000 +0000
+++ 3rdparty/bx/src/thread.cpp
@@ -17,7 +17,9 @@
 #elif  BX_PLATFORM_POSIX
 #	include <pthread.h>
 #	if BX_PLATFORM_BSD
+#ifndef __NetBSD__
 #		include <pthread_np.h>
+#endif
 #	endif // BX_PLATFORM_BSD
 #elif  BX_PLATFORM_WINDOWS \
 	|| BX_PLATFORM_WINRT   \
