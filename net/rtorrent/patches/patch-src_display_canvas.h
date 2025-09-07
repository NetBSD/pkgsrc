$NetBSD: patch-src_display_canvas.h,v 1.3 2025/09/07 07:49:16 adam Exp $

Make this work with "ncurses" 5.8. Patch taken from:
http://www.mail-archive.com/arch-general@archlinux.org/msg18728.html

--- src/display/canvas.h.orig	2025-03-28 18:55:13.000000000 +0000
+++ src/display/canvas.h
@@ -15,7 +16,7 @@ public:
   typedef std::vector<Attributes>      attributes_list;
   typedef std::unordered_map<int, int> attributes_map;
 
-  Canvas(int x = 0, int y = 0, int width = 0, int height = 0);
+  Canvas(int x = 0, int y = 0, int width = 1, int height = 1);
   ~Canvas();
 
   void         refresh();
