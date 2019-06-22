$NetBSD: patch-src_scintillaeditor.h,v 1.2 2019/06/22 12:57:50 mef Exp $

the Qt4 moc has some difficulty parsing in the boost headers. Apply
the workaround from https://bugreports.qt.io/browse/QTBUG-22829

--- src/scintillaeditor.h.orig	2018-03-13 12:12:43.000000000 +0000
+++ src/scintillaeditor.h
@@ -12,8 +12,10 @@
 #include "parsersettings.h"
 
 #include "memory.h"
+#ifndef Q_MOC_RUN
 #include <boost/property_tree/ptree.hpp>
 #include <boost/property_tree/json_parser.hpp>
+#endif
 
 class EditorColorScheme
 {
