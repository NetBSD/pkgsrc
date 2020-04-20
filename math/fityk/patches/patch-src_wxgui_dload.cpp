$NetBSD: patch-src_wxgui_dload.cpp,v 1.1 2020/04/20 00:41:04 joerg Exp $

--- src/wxgui/dload.cpp.orig	2020-04-19 19:06:47.672823533 +0000
+++ src/wxgui/dload.cpp
@@ -53,11 +53,11 @@ public:
     void draw(wxDC &dc, bool);
     void load_dataset(string const& filename, string const& filetype,
                       string const& options);
-    shared_ptr<const xylib::DataSet> get_data() const { return data; }
+    dataset_shared_ptr get_data() const { return data; }
     void make_outdated() { data_updated = false; }
 
 private:
-    shared_ptr<const xylib::DataSet> data;
+    dataset_shared_ptr data;
     bool data_updated; // if false, draw() doesn't do anything (plot is clear)
 };
 
