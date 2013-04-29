$NetBSD: patch-gui_dictionary__tool_dictionary__tool.cc,v 1.1 2013/04/29 09:52:17 ryoon Exp $

--- gui/dictionary_tool/dictionary_tool.cc.orig	2013-03-29 04:34:06.000000000 +0000
+++ gui/dictionary_tool/dictionary_tool.cc
@@ -358,7 +358,7 @@ DictionaryTool::DictionaryTool(QWidget *
   }
 
   // main window
-#ifndef OS_LINUX
+#if !defined(OS_LINUX) || !defined(OS_NETBSD)
   // For some reason setCentralWidget crashes the dictionary_tool on Linux
   // TODO(taku): investigate the cause of the crashes
   setCentralWidget(splitter_);
