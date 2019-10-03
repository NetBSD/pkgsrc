$NetBSD: patch-libobs_graphics_graphics.h,v 1.2 2019/10/03 20:33:15 nia Exp $

Support NetBSD.

--- libobs/graphics/graphics.h.orig	2019-09-20 15:14:16.000000000 +0000
+++ libobs/graphics/graphics.h
@@ -468,7 +468,7 @@ struct gs_window {
 	void *hwnd;
 #elif defined(__APPLE__)
 	__unsafe_unretained id view;
-#elif defined(__linux__) || defined(__FreeBSD__)
+#else
 	/* I'm not sure how portable defining id to uint32_t is. */
 	uint32_t id;
 	void *display;
