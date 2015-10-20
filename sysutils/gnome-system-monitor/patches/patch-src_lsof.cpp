$NetBSD: patch-src_lsof.cpp,v 1.1 2015/10/20 09:40:22 tnn Exp $

lsof.cpp:140:24: error: non-const lvalue reference to type
      'basic_ostringstream<[3 * ...]>' cannot bind to a temporary of type
      'basic_ostringstream<[3 * ...]>'
  ...s = static_cast<std::ostringstream&>(std::ostringstream() << count).str();

--- src/lsof.cpp.orig	2010-02-09 13:23:26.000000000 +0000
+++ src/lsof.cpp
@@ -137,7 +137,7 @@ namespace
 
     void update_count(unsigned count)
     {
-      string s = static_cast<std::ostringstream&>(std::ostringstream() << count).str();
+      string s = static_cast<const std::ostringstream&>(std::ostringstream() << count).str();
       gtk_label_set_text(this->count, s.c_str());
     }
 
