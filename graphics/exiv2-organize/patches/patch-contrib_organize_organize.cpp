$NetBSD: patch-contrib_organize_organize.cpp,v 1.1 2011/02/28 20:37:56 adam Exp $

--- contrib/organize/organize.cpp.orig	2011-02-28 19:45:54.000000000 +0000
+++ contrib/organize/organize.cpp
@@ -568,8 +568,8 @@ boost::regex uregex("(.*?)\\(([[:digit:]
 
 fs::path uniquify(const fs::path &dest)
 {
-    std::string ext = dest.extension();
-    std::string fname = dest.stem();
+    std::string ext = dest.extension().file_string();
+    std::string fname = dest.stem().file_string();
     fs::path parent = dest.parent_path();
 
     unsigned number = 1;
@@ -658,7 +658,7 @@ void process_directory(const fs::path &d
                         ++params.unsorted_count;
                     }
             
-                    dest_file /= p_iter->filename();
+                    dest_file /= p_iter->path();
                 
                     if(fs::exists(dest_file)) {
                         if(params.ignore_dups) {
@@ -682,7 +682,7 @@ void process_directory(const fs::path &d
                             else {
                                 info(std::string("duplicate file: ") + p_iter->path().file_string() +
                                     " of: " +  dest_file.file_string());
-                                dest_file = params.dups_dir / dest_subdir / p_iter->filename();
+                                dest_file = params.dups_dir / dest_subdir / p_iter->path();
                                 // Ugh, more dup possibilities
                                 if(fs::exists(dest_file)) {
                                     info(std::string("renaming: ") + p_iter->path().file_string() +
