$NetBSD: patch-3rdparty_macdeployqt_shared.cpp,v 1.1 2023/08/22 20:26:30 adam Exp $

Fix build with Qt5 on Darwin.

--- 3rdparty/macdeployqt/shared.cpp.orig	2023-08-21 18:34:21.000000000 +0000
+++ 3rdparty/macdeployqt/shared.cpp
@@ -1490,7 +1490,7 @@ bool deployQmlImports(const QString &app
 #if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
     QString qmlImportsPath = QLibraryInfo::path(QLibraryInfo::QmlImportsPath);
 #else
-    QString qmlImportsPath = QLibraryInfo::location(QLibraryInfo::QmlImportsPath);
+    QString qmlImportsPath = QLibraryInfo::location(QLibraryInfo::Qml2ImportsPath);
 #endif
     argumentList.append( "-importPath");
     argumentList.append(qmlImportsPath);
