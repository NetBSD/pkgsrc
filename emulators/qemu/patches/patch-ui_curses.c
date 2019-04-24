$NetBSD: patch-ui_curses.c,v 1.1 2019/04/24 13:59:32 ryoon Exp $

* For NetBSD curses

--- ui/curses.c.orig	2019-04-23 18:14:46.000000000 +0000
+++ ui/curses.c
@@ -46,6 +46,11 @@
 #define FONT_HEIGHT 16
 #define FONT_WIDTH 8
 
+#if defined(__NetBSD__)
+#define chars vals
+#define attr attributes
+#endif
+
 enum maybe_keycode {
     CURSES_KEYCODE,
     CURSES_CHAR,
