$NetBSD: patch-lily_paper-column-engraver.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/paper-column-engraver.cc.orig	2013-06-16 19:08:16.000000000 +0000
+++ lily/paper-column-engraver.cc
@@ -49,7 +49,7 @@ void
 Paper_column_engraver::finalize ()
 {
   if (! (breaks_ % 8))
-    progress_indication ("[" + to_string (breaks_) + "]");
+    progress_indication ("[" + ::to_string (breaks_) + "]");
 
   if (!made_columns_)
     {
@@ -267,7 +267,7 @@ Paper_column_engraver::stop_translation_
       breaks_++;
 
       if (! (breaks_ % 8))
-        progress_indication ("[" + to_string (breaks_) + "]");
+        progress_indication ("[" + ::to_string (breaks_) + "]");
     }
 
   context ()->get_score_context ()->unset_property (ly_symbol2scm ("forbidBreak"));
