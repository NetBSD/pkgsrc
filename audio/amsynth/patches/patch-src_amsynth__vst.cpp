$NetBSD: patch-src_amsynth__vst.cpp,v 1.1 2020/04/11 10:56:54 nia Exp $

This code violates PaX MPROTECT and isn't portable.

--- src/amsynth_vst.cpp.orig	2019-04-13 06:34:24.000000000 +0000
+++ src/amsynth_vst.cpp
@@ -48,7 +48,7 @@
 #ifdef WITH_GUI
 #include "GUI/editor_pane.h"
 #include <gdk/gdkx.h>
-#if __x86_64__
+#if __x86_64__ && !defined(__NetBSD__)
 #include <sys/mman.h>
 #include <sys/user.h>
 #endif
@@ -132,7 +132,7 @@ static void XEventProc(XEvent *xevent)
 
 static void setEventProc(Display *display, Window window)
 {
-#if __x86_64__
+#if __x86_64__ && !defined(__NetBSD__)
 	//
 	// JUCE calls XGetWindowProperty with long_length = 1 which means it only fetches the lower 32 bits of the address.
 	// Therefore we need to ensure we return an address in the lower 32-bits of address space.
