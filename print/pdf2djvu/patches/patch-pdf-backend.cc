$NetBSD: patch-pdf-backend.cc,v 1.2 2015/04/24 20:18:48 joerg Exp $

--- pdf-backend.cc.orig	2012-09-18 15:27:41.000000000 +0000
+++ pdf-backend.cc
@@ -54,7 +54,7 @@ static void poppler_error_handler(int po
   error_log << std::endl;
 }
 #else
-static void poppler_error_handler(void *data, ErrorCategory category, int pos, char *message)
+static void poppler_error_handler(void *data, ErrorCategory category, Goffset pos, char *message)
 {
   std::string format;
   const char *category_name = _("PDF error");
@@ -119,15 +119,6 @@ pdf::Environment::Environment(const char
 #endif
 }
 
-void pdf::Environment::set_antialias(bool value)
-{
-  if (!globalParams->setAntialias(const_cast<char*>(value ? "yes" : "no")))
-    throw UnableToSetParameter(_("Unable to set antialias parameter"));
-  if (!globalParams->setVectorAntialias(const_cast<char*>(value ? "yes" : "no")))
-    throw UnableToSetParameter(_("Unable to set vector antialias parameter"));
-}
-
-
 /* class pdf::Document
  * ===================
  */
