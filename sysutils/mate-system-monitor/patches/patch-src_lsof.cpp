$NetBSD: patch-src_lsof.cpp,v 1.2 2016/06/08 13:03:18 joerg Exp $

Casting temporaries to references is not valid.

--- src/lsof.cpp.orig	2016-06-04 18:57:52.613319665 +0000
+++ src/lsof.cpp
@@ -137,7 +137,7 @@ namespace
 
         void update_count(unsigned count)
         {
-            string s = static_cast<std::ostringstream&>(std::ostringstream() << count).str();
+            string s = (std::ostringstream() << count).str();
             gtk_label_set_text(this->count, s.c_str());
         }
 
