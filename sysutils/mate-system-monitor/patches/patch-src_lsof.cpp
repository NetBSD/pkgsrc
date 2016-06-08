$NetBSD: patch-src_lsof.cpp,v 1.1 2016/06/08 13:00:44 youri Exp $

Fix build on clang.

--- src/lsof.cpp.orig	2016-04-05 16:12:54.000000000 +0000
+++ src/lsof.cpp
@@ -137,7 +137,7 @@ namespace
 
         void update_count(unsigned count)
         {
-            string s = static_cast<std::ostringstream&>(std::ostringstream() << count).str();
+            string s = static_cast<const std::ostringstream&>(std::ostringstream() << count).str();
             gtk_label_set_text(this->count, s.c_str());
         }
 
