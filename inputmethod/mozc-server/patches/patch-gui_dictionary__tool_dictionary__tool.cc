$NetBSD: patch-gui_dictionary__tool_dictionary__tool.cc,v 1.4 2014/01/19 01:18:50 ryoon Exp $

--- gui/dictionary_tool/dictionary_tool.cc.orig	2014-01-06 07:10:48.000000000 +0000
+++ gui/dictionary_tool/dictionary_tool.cc
@@ -194,11 +194,11 @@ class MultiByteTextLineIterator
   }
 
   bool IsAvailable() const {
-    return *(ifs_.get());
+    return (ifs_.get())->good() || (ifs_.get())->eof();
   }
 
   bool Next(string *line)  {
-    if (!*(ifs_.get())) {
+    if (!IsAvailable()) {
       return false;
     }
 
@@ -341,7 +341,7 @@ DictionaryTool::DictionaryTool(QWidget *
 #endif  // !ENABLE_CLOUD_SYNC
 
   // main window
-#ifndef OS_LINUX
+#if !defined(OS_LINUX) && !defined(OS_NETBSD)
   // For some reason setCentralWidget crashes the dictionary_tool on Linux
   // TODO(taku): investigate the cause of the crashes
   setCentralWidget(splitter_);
