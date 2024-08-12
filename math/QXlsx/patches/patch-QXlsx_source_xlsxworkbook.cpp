$NetBSD: patch-QXlsx_source_xlsxworkbook.cpp,v 1.1 2024/08/12 14:03:25 adam Exp $

Fix error: calling a private constructor of class 'QString'.

--- QXlsx/source/xlsxworkbook.cpp.orig	2024-08-11 08:21:48.310667167 +0000
+++ QXlsx/source/xlsxworkbook.cpp
@@ -607,7 +607,7 @@ bool Workbook::loadFromXmlFile(QIODevice
 
                 AbstractSheet *sheet = addSheet(name, sheetId, type);
                 sheet->setSheetState(state);
-                if (relationship.target.startsWith("/")) {
+                if (relationship.target.startsWith(QStringLiteral("/"))) {
                     QString fullPath = QDir::cleanPath(relationship.target.mid(1));
 
                     sheet->setFilePath(fullPath);
