$NetBSD: patch-src_libgame_joystick.h,v 1.1 2019/05/05 07:59:38 adam Exp $

Allow joystick on NetBSD.

--- src/libgame/joystick.h.orig	2017-09-12 20:17:10.000000000 +0000
+++ src/libgame/joystick.h
@@ -23,7 +23,7 @@
 
 #define MAX_JOYSTICK_NAME_LEN	40
 
-#if defined(PLATFORM_FREEBSD)
+#if defined(PLATFORM_FREEBSD) || (defined(PLATFORM_NETBSD) && defined(HAVE_JOYSTICK))
 #define DEV_JOYSTICK_0		"/dev/joy0"
 #define DEV_JOYSTICK_1		"/dev/joy1"
 #define DEV_JOYSTICK_2		"/dev/joy2"
