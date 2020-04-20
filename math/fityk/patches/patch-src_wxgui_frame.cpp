$NetBSD: patch-src_wxgui_frame.cpp,v 1.1 2020/04/20 00:41:04 joerg Exp $

--- src/wxgui/frame.cpp.orig	2020-04-19 19:08:09.074623963 +0000
+++ src/wxgui/frame.cpp
@@ -919,7 +919,7 @@ void FFrame::OnDataQLoad (wxCommandEvent
     string cmd;
     if (count == 1) {
         string f = wx2s(paths[0]);
-        shared_ptr<const xylib::DataSet> d = xylib::cached_load_file(f, "", "");
+        dataset_shared_ptr d = xylib::cached_load_file(f, "", "");
         if (d->get_block_count() > 1) {
             wxArrayString choices;
             for (int i = 0; i < d->get_block_count(); ++i) {
