$NetBSD: patch-3rdparty_bx_include_bx_os.h,v 1.4 2015/11/13 14:11:49 wiz Exp $

Add NetBSD support.
https://github.com/mamedev/mame/pull/464

--- 3rdparty/bx/include/bx/os.h.orig	2015-09-30 06:29:01.000000000 +0000
+++ 3rdparty/bx/include/bx/os.h
@@ -15,6 +15,7 @@
 #elif  BX_PLATFORM_ANDROID \
 	|| BX_PLATFORM_EMSCRIPTEN \
 	|| BX_PLATFORM_FREEBSD \
+	|| BX_PLATFORM_NETBSD \
 	|| BX_PLATFORM_IOS \
 	|| BX_PLATFORM_LINUX \
 	|| BX_PLATFORM_NACL \
@@ -24,6 +25,7 @@
 
 #	include <sched.h> // sched_yield
 #	if BX_PLATFORM_FREEBSD \
+	|| BX_PLATFORM_NETBSD \
 	|| BX_PLATFORM_IOS \
 	|| BX_PLATFORM_NACL \
 	|| BX_PLATFORM_OSX \
@@ -103,7 +105,7 @@ namespace bx
 		return (pid_t)::syscall(SYS_gettid);
 #elif BX_PLATFORM_IOS || BX_PLATFORM_OSX
 		return (mach_port_t)::pthread_mach_thread_np(pthread_self() );
-#elif BX_PLATFORM_FREEBSD || BX_PLATFORM_NACL
+#elif BX_PLATFORM_FREEBSD || BX_PLATFORM_NACL || BX_PLATFORM_NETBSD
 		// Casting __nc_basic_thread_data*... need better way to do this.
 		return *(uint32_t*)::pthread_self();
 #else
