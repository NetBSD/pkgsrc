$NetBSD: patch-src_Sigil_Exporters_ExportEPUB.cpp,v 1.1 2012/01/26 15:43:20 ryoon Exp $

http://code.google.com/p/sigil/source/detail?r=ac1642d3df17ee958ab573e1cdb284d60bad6f9a

--- src/Sigil/Exporters/ExportEPUB.cpp.orig	2012-01-21 00:31:22.000000000 +0000
+++ src/Sigil/Exporters/ExportEPUB.cpp
@@ -157,7 +157,7 @@ void ExportEPUB::SaveFolderAsEpubToLocat
 #ifdef Q_WS_WIN
         std::string error_description = QString::fromStdWString( exception.GetErrorDescription() ).toStdString();
 #else
-        std::string error_description = QString::fromAscii( exception.GetErrorDescription().c_str() ).toStdString();
+        std::string error_description = QString::fromAscii( exception.GetErrorDescription() ).toStdString();
 #endif
         boost_throw( CZipExceptionWrapper()
             << errinfo_zip_info_msg( error_description )
