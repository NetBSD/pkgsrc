$NetBSD: patch-3rdparty_bx_include_bx_platform.h,v 1.1 2015/07/14 20:14:49 wiz Exp $

Add NetBSD support.

--- 3rdparty/bx/include/bx/platform.h.orig	2015-06-24 09:53:24.000000000 +0000
+++ 3rdparty/bx/include/bx/platform.h
@@ -18,6 +18,7 @@
 #define BX_PLATFORM_IOS        0
 #define BX_PLATFORM_LINUX      0
 #define BX_PLATFORM_NACL       0
+#define BX_PLATFORM_NETBSD     0
 #define BX_PLATFORM_OSX        0
 #define BX_PLATFORM_PS4        0
 #define BX_PLATFORM_QNX        0
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
@@ -198,6 +202,7 @@
 						|| BX_PLATFORM_IOS \
 						|| BX_PLATFORM_LINUX \
 						|| BX_PLATFORM_NACL \
+						|| BX_PLATFORM_NETBSD \
 						|| BX_PLATFORM_OSX \
 						|| BX_PLATFORM_QNX \
 						|| BX_PLATFORM_RPI \
@@ -250,6 +255,8 @@
 #elif BX_PLATFORM_NACL
 #	define BX_PLATFORM_NAME "NaCl " \
 				BX_STRINGIZE(BX_PLATFORM_NACL)
+#elif BX_PLATFORM_NETBSD
+#	define BX_PLATFORM_NAME "NetBSD"
 #elif BX_PLATFORM_OSX
 #	define BX_PLATFORM_NAME "OSX"
 #elif BX_PLATFORM_PS4
