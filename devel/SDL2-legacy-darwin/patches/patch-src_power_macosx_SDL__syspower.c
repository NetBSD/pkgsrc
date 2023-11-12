$NetBSD: patch-src_power_macosx_SDL__syspower.c,v 1.1 2023/11/12 21:28:04 nia Exp $

Restore support for Mac OS X 10.4, from "TigerPorts":
https://raw.githubusercontent.com/evanmiller/TigerPorts/master/devel/libsdl2/files/patch-SDL2-2.0.3_OSX_104.diff

--- src/power/macosx/SDL_syspower.c.orig	2014-03-16 02:31:42.000000000 +0000
+++ src/power/macosx/SDL_syspower.c
@@ -23,6 +23,12 @@
 #ifndef SDL_POWER_DISABLED
 #if SDL_POWER_MACOSX
 
+#if defined(__ALTIVEC__) && !defined(MAC_OS_X_VERSION_10_5)
+/* to cricumvent a bug in Mac OS X 10.4 SDK */
+#define vector __vector
+#include <CoreServices/CoreServices.h>
+#undef vector
+#endif
 #include <Carbon/Carbon.h>
 #include <IOKit/ps/IOPowerSources.h>
 #include <IOKit/ps/IOPSKeys.h>
