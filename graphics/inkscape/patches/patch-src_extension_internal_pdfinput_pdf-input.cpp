$NetBSD: patch-src_extension_internal_pdfinput_pdf-input.cpp,v 1.2 2019/01/06 08:41:01 markd Exp $

support for poppler 0.72 from upstream by way of linuxfromscratch

--- src/extension/internal/pdfinput/pdf-input.cpp.orig	2018-03-11 20:38:09.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-input.cpp
@@ -793,7 +793,7 @@ PdfInput::open(::Inkscape::Extension::In
             dlg->getImportSettings(prefs);
 
         // Apply crop settings
-        PDFRectangle *clipToBox = NULL;
+        _POPPLER_CONST PDFRectangle *clipToBox = NULL;
         double crop_setting;
         sp_repr_get_double(prefs, "cropTo", &crop_setting);
 
