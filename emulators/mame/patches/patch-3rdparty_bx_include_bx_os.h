$NetBSD: patch-3rdparty_bx_include_bx_os.h,v 1.1 2015/07/14 20:14:49 wiz Exp $

Add NetBSD support.

--- 3rdparty/bx/include/bx/os.h.orig	2015-06-24 09:53:24.000000000 +0000
+++ 3rdparty/bx/include/bx/os.h
@@ -17,11 +17,12 @@
 	|| BX_PLATFORM_IOS \
 	|| BX_PLATFORM_LINUX \
 	|| BX_PLATFORM_NACL \
+	|| BX_PLATFORM_NETBSD \
 	|| BX_PLATFORM_OSX \
 	|| BX_PLATFORM_RPI
 
 #	include <sched.h> // sched_yield
-#	if BX_PLATFORM_FREEBSD || BX_PLATFORM_IOS || BX_PLATFORM_NACL || BX_PLATFORM_OSX
+#	if BX_PLATFORM_FREEBSD || BX_PLATFORM_IOS || BX_PLATFORM_NACL || BX_PLATFORM_NETBSD || BX_PLATFORM_OSX
 #		include <pthread.h> // mach_port_t
 #	endif // BX_PLATFORM_IOS || BX_PLATFORM_OSX || BX_PLATFORM_NACL
 
@@ -93,7 +94,7 @@ namespace bx
 		return (pid_t)::syscall(SYS_gettid);
 #elif BX_PLATFORM_IOS || BX_PLATFORM_OSX
 		return (mach_port_t)::pthread_mach_thread_np(pthread_self() );
-#elif BX_PLATFORM_FREEBSD || BX_PLATFORM_NACL
+#elif BX_PLATFORM_FREEBSD || BX_PLATFORM_NACL || BX_PLATFORM_NETBSD
 		// Casting __nc_basic_thread_data*... need better way to do this.
 		return *(uint32_t*)::pthread_self();
 #else
