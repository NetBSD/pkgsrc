$NetBSD: patch-lily_input.cc,v 1.1 2013/06/16 20:46:52 joerg Exp $

--- lily/input.cc.orig	2013-06-16 18:50:37.000000000 +0000
+++ lily/input.cc
@@ -142,7 +142,7 @@ string
 Input::line_number_string () const
 {
   if (source_file_)
-    return to_string (source_file_->get_line (start_));
+    return ::to_string (source_file_->get_line (start_));
   return "?";
 }
 
