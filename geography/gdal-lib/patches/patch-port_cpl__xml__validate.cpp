$NetBSD: patch-port_cpl__xml__validate.cpp,v 1.1 2024/02/01 07:31:50 wiz Exp $

Fix build with libxml 2.
https://github.com/OSGeo/gdal/commit/cbed9fc91dffba30d0f9a6a06a412a04d9cd36fa

--- port/cpl_xml_validate.cpp.orig	2024-02-01 07:23:14.995841703 +0000
+++ port/cpl_xml_validate.cpp
@@ -928,7 +928,7 @@ static void CPLLibXMLWarningErrorCallbac
 
     if( strstr(pszStr, "since this namespace was already imported") == nullptr )
     {
-        xmlErrorPtr pErrorPtr = xmlGetLastError();
+        const xmlError *pErrorPtr = xmlGetLastError();
         const char* pszFilename = static_cast<char *>(ctx);
         char* pszStrDup = CPLStrdup(pszStr);
         int nLen = static_cast<int>(strlen(pszStrDup));
