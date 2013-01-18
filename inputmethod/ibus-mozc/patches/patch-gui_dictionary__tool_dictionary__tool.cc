$NetBSD: patch-gui_dictionary__tool_dictionary__tool.cc,v 1.1 2013/01/18 11:36:40 ryoon Exp $

--- gui/dictionary_tool/dictionary_tool.cc.orig	2012-08-31 05:37:14.000000000 +0000
+++ gui/dictionary_tool/dictionary_tool.cc
@@ -339,7 +339,7 @@ DictionaryTool::DictionaryTool(QWidget *
   }
 
   // main window
-#ifndef OS_LINUX
+#if !defined(OS_LINUX) && !defined(OS_NETBSD)
   // For some reason setCentralWidget crashes the dictionary_tool on Linux
   // TODO(taku): investigate the cause of the crashes
   setCentralWidget(splitter_);
