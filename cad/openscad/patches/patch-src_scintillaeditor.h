$NetBSD: patch-src_scintillaeditor.h,v 1.1 2016/09/01 19:53:36 plunky Exp $

the Qt4 moc has some difficulty parsing in the boost headers. Apply
the workaround from https://bugreports.qt.io/browse/QTBUG-22829

--- src/scintillaeditor.h.orig	2015-04-05 14:01:12.000000000 +0000
+++ src/scintillaeditor.h
@@ -11,9 +11,11 @@
 #include "scadlexer.h"
 #include "parsersettings.h"
 
+#ifndef Q_MOC_RUN
 #include <boost/shared_ptr.hpp>
 #include <boost/property_tree/ptree.hpp>
 #include <boost/property_tree/json_parser.hpp>
+#endif
 
 class EditorColorScheme
 {
