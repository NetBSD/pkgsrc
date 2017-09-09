$NetBSD: patch-src_libgame_joystick.h,v 1.1 2017/09/09 07:10:34 adam Exp $

Allow joystick on NetBSD.

--- src/libgame/joystick.h.orig	2015-10-20 21:58:08.000000000 +0000
+++ src/libgame/joystick.h
@@ -19,7 +19,7 @@
 #define	JOYSTICK_ACTIVE		(1 << 1)
 #define JOYSTICK_ACTIVATED	(JOYSTICK_AVAILABLE | JOYSTICK_ACTIVE)
 
-#if defined(PLATFORM_FREEBSD)
+#if defined(PLATFORM_FREEBSD) || (defined(PLATFORM_NETBSD) && defined(HAVE_JOYSTICK))
 #define DEV_JOYSTICK_0		"/dev/joy0"
 #define DEV_JOYSTICK_1		"/dev/joy1"
 #define DEV_JOYSTICK_2		"/dev/joy2"
