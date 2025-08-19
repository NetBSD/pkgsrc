$NetBSD: patch-src_qtjsapi_RJSTools.cpp,v 1.1 2025/08/19 12:52:17 plunky Exp $

turn off debug output

--- src/qtjsapi/RJSTools.cpp.orig	2025-05-28 12:02:41.395712228 +0000
+++ src/qtjsapi/RJSTools.cpp
@@ -321,10 +321,12 @@ void RJSTools::print(const QJSValue& arg
 }
 
 void RJSTools::debug(const QJSValue& args) {
+#ifndef QT_NO_DEBUG_OUTPUT
     QDebug deb = qDebug().noquote();
     for (int i=0; i<args.property("length").toInt(); i++) {
         deb << args.property(i).toString();
     }
+#endif
 }
 
 void RJSTools::warning(const QJSValue& args) {
