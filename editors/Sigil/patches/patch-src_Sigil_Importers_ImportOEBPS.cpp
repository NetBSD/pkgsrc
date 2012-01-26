$NetBSD: patch-src_Sigil_Importers_ImportOEBPS.cpp,v 1.1 2012/01/26 15:43:20 ryoon Exp $

http://code.google.com/p/sigil/source/detail?r=ac1642d3df17ee958ab573e1cdb284d60bad6f9a

--- src/Sigil/Importers/ImportOEBPS.cpp.orig	2012-01-21 00:31:22.000000000 +0000
+++ src/Sigil/Importers/ImportOEBPS.cpp
@@ -81,7 +81,7 @@ void ImportOEBPS::ExtractContainer()
                 #ifdef Q_WS_WIN
                 std::string filename = QString::fromStdWString( file_header->GetFileName() ).toStdString();
                 #else
-                std::string filename = QString::fromAscii( file_header->GetFileName().c_str() ).toStdString();
+                std::string filename = QString::fromAscii( file_header->GetFileName() ).toStdString();
                 #endif
 
                 zip.Close(); 
@@ -105,7 +105,7 @@ void ImportOEBPS::ExtractContainer()
 #ifdef Q_WS_WIN
         std::string error_description = QString::fromStdWString( exception.GetErrorDescription() ).toStdString();
 #else
-        std::string error_description = QString::fromAscii( exception.GetErrorDescription().c_str() ).toStdString();
+        std::string error_description = QString::fromAscii( exception.GetErrorDescription() ).toStdString();
 #endif
         boost_throw( CZipExceptionWrapper()
             << errinfo_zip_info_msg( error_description )
