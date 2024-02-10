$NetBSD: patch-gui_dictionary__tool_dictionary__tool.cc,v 1.1 2024/02/10 02:20:18 ryoon Exp $

--- gui/dictionary_tool/dictionary_tool.cc.orig	2023-12-13 09:38:40.198993431 +0000
+++ gui/dictionary_tool/dictionary_tool.cc
@@ -369,7 +369,7 @@ DictionaryTool::DictionaryTool(QWidget *
 #endif  // !ENABLE_CLOUD_SYNC
 
   // main window
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__NetBSD__)
   // For some reason setCentralWidget crashes the dictionary_tool on Linux
   // TODO(taku): investigate the cause of the crashes
   setCentralWidget(splitter_);
