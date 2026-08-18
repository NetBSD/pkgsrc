$NetBSD: patch-Misc_common.c,v 1.1 2026/08/18 10:07:28 adam Exp $

On Darwin, don't redefine swab().

--- Misc/common.c.orig	2026-08-18 09:54:14.054642967 +0000
+++ Misc/common.c
@@ -28,7 +28,7 @@
 
 #include "common.h"
 
-#if defined(TARGET_OS_VMS) || defined(TARGET_OS_BEOS) || defined(TARGET_OS_MAC)
+#if defined(TARGET_OS_VMS) || defined(TARGET_OS_BEOS)
 void swab( const char *from, char *to, int nbytes)
 /* A quick definition of SWAB for VAX-VMS  */
 {
