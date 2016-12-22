$NetBSD: patch-contrib_organize_helpers.cpp,v 1.1 2016/12/22 21:04:31 joerg Exp $

Pointers have no sign.

--- contrib/organize/helpers.cpp.orig	2016-12-22 14:15:48.253723125 +0000
+++ contrib/organize/helpers.cpp
@@ -204,7 +204,7 @@ std::string iptc_day(const Exiv2::Image 
 bool file_get_tm(const fs::path &path, std::tm &tm)
 {
     std::time_t timer = fs::last_write_time(path);
-    if(time > 0) {
+    if(time) {
         tm = *localtime(&timer);
         return true;
     } 
