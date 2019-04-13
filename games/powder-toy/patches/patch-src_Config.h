$NetBSD: patch-src_Config.h,v 1.1 2019/04/13 12:08:04 nia Exp $

Disable auto-updater.

--- src/Config.h.orig	2019-02-21 05:23:45.000000000 +0000
+++ src/Config.h
@@ -40,7 +40,7 @@
 #endif
 //VersionInfoEnd
 
-//#define IGNORE_UPDATES //uncomment this for mods, to not get any update notifications
+#define IGNORE_UPDATES //uncomment this for mods, to not get any update notifications
 
 #if !(defined(MACOSX) && defined(DEBUG))
 #define HIGH_QUALITY_RESAMPLE			//High quality image resampling, slower but much higher quality than my terribad linear interpolation
