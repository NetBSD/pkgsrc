$NetBSD: patch-3rdparty_bx_include_bx_platform.h,v 1.4 2015/11/13 14:11:49 wiz Exp $

Add NetBSD support.
https://github.com/mamedev/mame/pull/464

--- 3rdparty/bx/include/bx/platform.h.orig	2015-09-30 06:29:01.000000000 +0000
+++ 3rdparty/bx/include/bx/platform.h
@@ -15,6 +15,7 @@
 #define BX_PLATFORM_ANDROID    0
 #define BX_PLATFORM_EMSCRIPTEN 0
 #define BX_PLATFORM_FREEBSD    0
+#define BX_PLATFORM_NETBSD     0
 #define BX_PLATFORM_IOS        0
 #define BX_PLATFORM_LINUX      0
 #define BX_PLATFORM_NACL       0
@@ -187,6 +188,9 @@
 #elif defined(__FreeBSD__)
 #	undef  BX_PLATFORM_FREEBSD
 #	define BX_PLATFORM_FREEBSD 1
+#elif defined(__NetBSD__)
+#	undef  BX_PLATFORM_NETBSD
+#	define BX_PLATFORM_NETBSD 1
 #else
 #	error "BX_PLATFORM_* is not defined!"
 #endif //
@@ -195,6 +199,7 @@
 						|| BX_PLATFORM_ANDROID \
 						|| BX_PLATFORM_EMSCRIPTEN \
 						|| BX_PLATFORM_FREEBSD \
+						|| BX_PLATFORM_NETBSD \
 						|| BX_PLATFORM_IOS \
 						|| BX_PLATFORM_LINUX \
 						|| BX_PLATFORM_NACL \
@@ -244,6 +249,8 @@
 				BX_STRINGIZE(__EMSCRIPTEN_tiny__)
 #elif BX_PLATFORM_FREEBSD
 #	define BX_PLATFORM_NAME "FreeBSD"
+#elif BX_PLATFORM_NETBSD
+#	define BX_PLATFORM_NAME "NetBSD"
 #elif BX_PLATFORM_IOS
 #	define BX_PLATFORM_NAME "iOS"
 #elif BX_PLATFORM_LINUX
