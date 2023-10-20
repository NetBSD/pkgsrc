$NetBSD: patch-src_libgame_joystick.c,v 1.2 2023/10/20 09:53:38 adam Exp $

Allow joystick on NetBSD.

--- src/libgame/joystick.c.orig	2023-05-21 14:16:39.000000000 +0000
+++ src/libgame/joystick.c
@@ -9,12 +9,13 @@
 // joystick.c
 // ============================================================================
 
-#if defined(PLATFORM_FREEBSD)
+#include "misc.h"
+
+#if defined(PLATFORM_FREEBSD) || (defined(PLATFORM_NETBSD) && defined(HAVE_JOYSTICK))
 #include <machine/joystick.h>
 #endif
 
 #include "joystick.h"
-#include "misc.h"
 
 
 // ============================================================================
