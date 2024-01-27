$NetBSD: patch-helpcompiler_source_HelpLinker.cxx,v 1.1 2024/01/27 22:35:07 wiz Exp $

Fix build with libxml2 2.12.

--- helpcompiler/source/HelpLinker.cxx.orig	2024-01-27 20:26:24.244726819 +0000
+++ helpcompiler/source/HelpLinker.cxx
@@ -815,7 +815,7 @@ static const HelpProcessingException* Gp
 
 extern "C" {
 
-static void StructuredXMLErrorFunction(SAL_UNUSED_PARAMETER void *, xmlErrorPtr error)
+static void StructuredXMLErrorFunction(SAL_UNUSED_PARAMETER void *, const _xmlError* error)
 {
     std::string aErrorMsg = error->message;
     std::string aXMLParsingFile;
