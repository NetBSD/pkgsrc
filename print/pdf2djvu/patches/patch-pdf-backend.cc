$NetBSD: patch-pdf-backend.cc,v 1.1 2013/08/31 14:54:23 joerg Exp $

--- pdf-backend.cc.orig	2013-08-31 13:41:40.000000000 +0000
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
