$NetBSD: patch-src_display_canvas.h,v 1.1 2018/06/24 16:59:52 adam Exp $

Make this work with "ncurses" 5.8. Patch taken from:
http://www.mail-archive.com/arch-general@archlinux.org/msg18728.html

--- src/display/canvas.h.orig	2018-06-07 04:25:27.000000000 +0000
+++ src/display/canvas.h
@@ -37,6 +37,7 @@
 #ifndef RTORRENT_DISPLAY_CANVAS_H
 #define RTORRENT_DISPLAY_CANVAS_H
 
+#include <cstdarg>
 #include <string>
 #include <vector>
 
@@ -48,7 +49,7 @@ class Canvas {
 public:
   typedef std::vector<Attributes> attributes_list;
 
-  Canvas(int x = 0, int y = 0, int width = 0, int height = 0);
+  Canvas(int x = 0, int y = 0, int width = 1, int height = 1);
   ~Canvas() { if (!m_isDaemon) { delwin(m_window); } }
 
   void                refresh()                                               { if (!m_isDaemon) { wnoutrefresh(m_window); } }
