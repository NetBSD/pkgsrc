$NetBSD: patch-gcore_gdaljp2metadatagenerator.cpp,v 1.1 2024/02/01 07:31:50 wiz Exp $

Fix build with libxml 2.
https://github.com/OSGeo/gdal/commit/cbed9fc91dffba30d0f9a6a06a412a04d9cd36fa

--- gcore/gdaljp2metadatagenerator.cpp.orig	2024-02-01 07:27:50.221341841 +0000
+++ gcore/gdaljp2metadatagenerator.cpp
@@ -355,7 +355,7 @@ static CPLString GDALGMLJP2EvalExpr(cons
 /************************************************************************/
 
 static void GDALGMLJP2XPathErrorHandler( void * /* userData */,
-                                         xmlErrorPtr error)
+                                         const xmlError *error)
 {
     if( error->domain == XML_FROM_XPATH &&
         error->str1 != nullptr &&
