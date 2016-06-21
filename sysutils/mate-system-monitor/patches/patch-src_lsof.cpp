$NetBSD: patch-src_lsof.cpp,v 1.4 2016/06/21 16:24:00 youri Exp $

Casting temporaries to references is not valid.
Merged upstream.

--- src/lsof.cpp.orig	2016-04-05 16:12:54.000000000 +0000
+++ src/lsof.cpp
@@ -137,7 +137,9 @@ namespace
 
         void update_count(unsigned count)
         {
-            string s = static_cast<std::ostringstream&>(std::ostringstream() << count).str();
+		std::ostringstream ss;
+			ss << count;
+		string s = ss.str();
             gtk_label_set_text(this->count, s.c_str());
         }
 
