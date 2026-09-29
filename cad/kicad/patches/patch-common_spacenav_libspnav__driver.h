$NetBSD: patch-common_spacenav_libspnav__driver.h,v 1.1 2026/09/29 16:11:56 bouyer Exp $

Add NetBSD support.

--- common/spacenav/libspnav_driver.h.orig	2026-05-05 12:57:05.286145561 +0000
+++ common/spacenav/libspnav_driver.h
@@ -24,7 +24,7 @@
 #ifndef KICAD_LIBSPNAV_DRIVER_H
 #define KICAD_LIBSPNAV_DRIVER_H
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #include <spnav.h>
 #endif
 
