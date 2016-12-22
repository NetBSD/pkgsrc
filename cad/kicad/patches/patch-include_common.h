$NetBSD: patch-include_common.h,v 1.3 2016/12/22 21:01:22 joerg Exp $

Given that the constants are used in integer contexts, make sure that
the value is a valid int.

--- include/common.h.orig	2016-12-22 11:39:43.778530785 +0000
+++ include/common.h
@@ -54,10 +54,10 @@ class REPORTER;
 #define GR_KB_LEFTSHIFT  0x20000000                 /* left shift key depressed
                                                      */
 #define GR_KB_CTRL       0x40000000                 // CTRL depressed
-#define GR_KB_ALT        0x80000000                 // ALT depressed
+#define GR_KB_ALT        0x08000000                 // ALT depressed
 #define GR_KB_SHIFT      (GR_KB_LEFTSHIFT | GR_KB_RIGHTSHIFT)
 #define GR_KB_SHIFTCTRL  (GR_KB_SHIFT | GR_KB_CTRL)
-#define MOUSE_MIDDLE     0x08000000                 /* Middle button mouse
+#define MOUSE_MIDDLE     0x04000000                 /* Middle button mouse
                                                      * flag for block commands
                                                      */
 
