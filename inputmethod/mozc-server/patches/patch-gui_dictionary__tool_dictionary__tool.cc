$NetBSD: patch-gui_dictionary__tool_dictionary__tool.cc,v 1.3 2013/09/15 12:30:23 joerg Exp $

--- gui/dictionary_tool/dictionary_tool.cc.orig	2013-08-28 05:26:30.000000000 +0000
+++ gui/dictionary_tool/dictionary_tool.cc
@@ -219,11 +219,11 @@ class MultiByteTextLineIterator
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
 
@@ -358,7 +358,7 @@ DictionaryTool::DictionaryTool(QWidget *
   }
 
   // main window
-#ifndef OS_LINUX
+#if !defined(OS_LINUX) && !defined(OS_NETBSD)
   // For some reason setCentralWidget crashes the dictionary_tool on Linux
   // TODO(taku): investigate the cause of the crashes
   setCentralWidget(splitter_);
