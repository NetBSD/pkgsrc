$NetBSD: patch-src_pingus__menu.cpp,v 1.1 2012/11/23 12:35:01 joerg Exp $

--- src/pingus_menu.cpp.orig	2012-11-22 20:47:42.000000000 +0000
+++ src/pingus_menu.cpp
@@ -234,7 +234,7 @@ PingusMenu::draw_foreground(DrawingConte
 
   gc.print_left(Fonts::pingus_small, 25, 
                 Display::get_height()-130,
-                "Pingus "VERSION", Copyright (C) 1998-2007 Ingo Ruhnke <grumbel@gmx.de>\n"
+                "Pingus " VERSION ", Copyright (C) 1998-2007 Ingo Ruhnke <grumbel@gmx.de>\n"
                 "See the file AUTHORS for a complete list of contributors.\n");
   gc.print_left(Fonts::pingus_small, 25, 
                 Display::get_height()-80,
