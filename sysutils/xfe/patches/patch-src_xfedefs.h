$NetBSD: patch-src_xfedefs.h,v 1.1 2026/04/25 10:00:26 vins Exp $

Allow build on any platform with an unknown packaging system.

--- src/xfedefs.h.orig	2026-04-25 09:23:10.811011050 +0000
+++ src/xfedefs.h
@@ -402,9 +402,7 @@ enum
 // Macro to add parentheses before and after a given string
 #define PARS(s)    ((FXString)" (" + (s) + (FXString)")")
 
-#if defined(__FreeBSD__)
 #define OTHER_PKG    2
-#endif
 
 // Linux specials
 
@@ -423,6 +421,5 @@ enum
 // Package format
 #define DEB_PKG      0
 #define RPM_PKG      1
-#define OTHER_PKG    2
 
 #endif
