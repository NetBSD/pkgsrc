$NetBSD: patch-gui_dictionary__tool_dictionary__tool.cc,v 1.1 2021/02/17 15:29:51 ryoon Exp $

* NetBSD support

--- gui/dictionary_tool/dictionary_tool.cc.orig	2014-05-21 10:51:22.000000000 +0000
+++ gui/dictionary_tool/dictionary_tool.cc
@@ -347,7 +347,7 @@ DictionaryTool::DictionaryTool(QWidget *
 #endif  // !ENABLE_CLOUD_SYNC
 
   // main window
-#ifndef OS_LINUX
+#if !defined(OS_LINUX) && !defined(OS_NETBSD)
   // For some reason setCentralWidget crashes the dictionary_tool on Linux
   // TODO(taku): investigate the cause of the crashes
   setCentralWidget(splitter_);
