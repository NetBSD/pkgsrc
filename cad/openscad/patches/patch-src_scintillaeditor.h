$NetBSD: patch-src_scintillaeditor.h,v 1.3 2021/04/08 10:26:08 bouyer Exp $

the Qt4 moc has some difficulty parsing in the boost headers. Apply
the workaround from https://bugreports.qt.io/browse/QTBUG-22829

--- src/scintillaeditor.h.orig	2021-01-31 18:41:09.000000000 +0100
+++ src/scintillaeditor.h	2021-04-04 21:01:50.732077378 +0200
@@ -1,8 +1,10 @@
 #pragma once
 
 #include <functional>
+#ifndef Q_MOC_RUN
 #include <boost/property_tree/ptree.hpp>
 #include <boost/property_tree/json_parser.hpp>
+#endif
 
 #include <QMap>
 #include <QObject>
