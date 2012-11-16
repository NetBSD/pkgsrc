$NetBSD: patch-src_ui-part-cdda.hh,v 1.1 2012/11/16 20:05:35 joerg Exp $

--- src/ui-part-cdda.hh.orig	2012-11-16 15:04:58.000000000 +0000
+++ src/ui-part-cdda.hh
@@ -209,7 +209,7 @@ namespace Bmp
 
         struct LabelT
         {
-          Gtk::Label  * Album,;
+          Gtk::Label  * Album;
           Gtk::Label  * Artist;
           Gtk::Label  * Date;
         };
