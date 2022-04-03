$NetBSD: patch-pdf-backend.cc,v 1.6 2022/04/03 10:09:58 wiz Exp $

Poppler-22.03 compat from upstream.

--- pdf-backend.cc.orig	2021-11-22 17:38:31.000000000 +0000
+++ pdf-backend.cc
@@ -130,7 +130,11 @@ void pdf::Environment::set_antialias(boo
  */
 
 pdf::Document::Document(const std::string &file_name)
-: ::PDFDoc(new pdf::String(file_name.c_str()), nullptr, nullptr)
+#if POPPLER_VERSION >= 220300
+: ::PDFDoc(std::make_unique<pdf::String>(file_name.c_str()))
+#else
+: ::PDFDoc(new pdf::String(file_name.c_str()))
+#endif
 {
   if (!this->isOk())
     throw LoadError();
