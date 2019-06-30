$NetBSD: patch-libobs_graphics_graphics.h,v 1.1 2019/06/30 21:01:24 nia Exp $

Support NetBSD.

--- libobs/graphics/graphics.h.orig	2019-06-14 05:28:10.000000000 +0000
+++ libobs/graphics/graphics.h
@@ -461,7 +461,7 @@ struct gs_window {
 	void                    *hwnd;
 #elif defined(__APPLE__)
 	__unsafe_unretained id  view;
-#elif defined(__linux__) || defined(__FreeBSD__)
+#else
 	/* I'm not sure how portable defining id to uint32_t is. */
 	uint32_t id;
 	void* display;
