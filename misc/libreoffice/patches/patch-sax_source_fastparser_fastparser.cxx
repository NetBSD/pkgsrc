$NetBSD: patch-sax_source_fastparser_fastparser.cxx,v 1.1 2024/01/27 22:35:07 wiz Exp $

Fix build with libxml2 2.12.

--- sax/source/fastparser/fastparser.cxx.orig	2024-01-27 20:14:24.030394982 +0000
+++ sax/source/fastparser/fastparser.cxx
@@ -579,7 +579,7 @@ Event& Entity::getEvent( CallbackType aT
 OUString lclGetErrorMessage( xmlParserCtxtPtr ctxt, std::u16string_view sSystemId, sal_Int32 nLine )
 {
     const char* pMessage;
-    xmlErrorPtr error = xmlCtxtGetLastError( ctxt );
+    const xmlError* error = xmlCtxtGetLastError( ctxt );
     if( error && error->message )
         pMessage = error->message;
     else
