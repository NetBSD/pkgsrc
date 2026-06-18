$NetBSD: patch-xdelta3.h,v 1.1 2026/06/18 19:36:19 nia Exp $

Fix spelling of _POSIX_C_SOURCE so gettimeofday(2) gets declared
properly.

--- xdelta3.h.orig	2026-06-18 19:25:18.614120556 +0000
+++ xdelta3.h
@@ -24,7 +24,7 @@
 #ifndef _XDELTA3_H_
 #define _XDELTA3_H_
 
-#define _POSIX_SOURCE 200112L
+#define _POSIX_C_SOURCE 200112L
 #define _ISOC99_SOURCE
 #define _C99_SOURCE
 
