$NetBSD: patch-3rdparty_bx_src_thread.cpp,v 1.4 2023/02/22 11:15:21 wiz Exp $

NetBSD does not provide pthread_np.h.

--- 3rdparty/bx/src/thread.cpp.orig	2023-02-21 17:59:53.000000000 +0000
+++ 3rdparty/bx/src/thread.cpp
@@ -25,7 +25,9 @@
 	|| BX_PLATFORM_NX
 #	include <pthread.h>
 #	if BX_PLATFORM_BSD
+#ifndef __NetBSD__
 #		include <pthread_np.h>
+#endif
 #	endif // BX_PLATFORM_BSD
 #	if BX_PLATFORM_LINUX && (BX_CRT_GLIBC < 21200)
 #		include <sys/prctl.h>
