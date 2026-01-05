$NetBSD: patch-src_flatzebra_Joystick.h,v 1.1 2026/01/05 21:32:30 ktnb Exp $

Point to SDL2

--- src/flatzebra/Joystick.h.orig	2026-01-04 02:32:31.648378369 +0000
+++ src/flatzebra/Joystick.h
@@ -22,7 +22,7 @@
 #ifndef _H_Joystick
 #define _H_Joystick
 
-#include <SDL.h>
+#include <SDL2/SDL.h>
 
 #include <vector>
 
