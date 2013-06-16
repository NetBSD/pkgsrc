$NetBSD: patch-lily_arpeggio.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/arpeggio.cc.orig	2013-06-16 19:09:07.000000000 +0000
+++ lily/arpeggio.cc
@@ -140,7 +140,7 @@ Arpeggio::print (SCM smob)
   if (dir)
     {
       Font_metric *fm = Font_interface::get_default_font (me);
-      arrow = fm->find_by_name ("scripts.arpeggio.arrow." + to_string (dir));
+      arrow = fm->find_by_name ("scripts.arpeggio.arrow." + ::to_string (dir));
       heads[dir] -= dir * arrow.extent (Y_AXIS).length ();
     }
 
