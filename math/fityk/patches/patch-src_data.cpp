$NetBSD: patch-src_data.cpp,v 1.1 2020/04/20 00:41:04 joerg Exp $

--- src/data.cpp.orig	2020-04-19 19:03:20.044364446 +0000
+++ src/data.cpp
@@ -307,7 +307,7 @@ static string tr_opt(string options)
 int Data::count_blocks(string const& fn,
                        string const& format, string const& options)
 {
-    shared_ptr<const xylib::DataSet> xyds(
+    dataset_shared_ptr xyds(
                         xylib::cached_load_file(fn, format, tr_opt(options)));
     return xyds->get_block_count();
 }
@@ -316,7 +316,7 @@ int Data::count_columns(string const& fn
                         string const& format, string const& options,
                         int first_block)
 {
-    shared_ptr<const xylib::DataSet> xyds(
+    dataset_shared_ptr xyds(
                         xylib::cached_load_file(fn, format, tr_opt(options)));
     return xyds->get_block(first_block)->get_column_count();
 }
@@ -332,7 +332,7 @@ void Data::load_file (string const& fn,
 
     string block_name;
     try {
-        shared_ptr<const xylib::DataSet> xyds(
+        dataset_shared_ptr xyds(
                         xylib::cached_load_file(fn, format, tr_opt(options)));
         clear(); //removing previous file
         vector<int> bb = blocks.empty() ? vector1(0) : blocks;
