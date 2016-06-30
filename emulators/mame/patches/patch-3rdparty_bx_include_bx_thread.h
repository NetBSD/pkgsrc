$NetBSD: patch-3rdparty_bx_include_bx_thread.h,v 1.5 2016/06/30 18:14:23 wiz Exp $

https://github.com/bkaradzic/bx/pull/118

--- 3rdparty/bx/include/bx/thread.h.orig	2016-06-29 06:34:30.000000000 +0000
+++ 3rdparty/bx/include/bx/thread.h
@@ -9,7 +9,9 @@
 #if BX_PLATFORM_POSIX
 #	include <pthread.h>
 #	if BX_PLATFORM_BSD
+#          ifdef __FreeBSD__
 #		include <pthread_np.h>
+#	   endif
 #	endif
 #	if defined(__GLIBC__) && !( (__GLIBC__ > 2) || ( (__GLIBC__ == 2) && (__GLIBC_MINOR__ >= 12) ) )
 #		include <sys/prctl.h>
