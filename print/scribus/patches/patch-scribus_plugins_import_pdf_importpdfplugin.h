$NetBSD: patch-scribus_plugins_import_pdf_importpdfplugin.h,v 1.1 2025/11/10 13:54:53 wiz Exp $

--- scribus/plugins/import/pdf/importpdfplugin.h.orig	2025-01-25 21:57:14.000000000 +0000
+++ scribus/plugins/import/pdf/importpdfplugin.h
@@ -44,7 +44,7 @@ class PLUGIN_API ImportPdfPlugin : publi
 		\param fileName input filename, or QString() to prompt.
 		\retval bool always true
 		 */
-		virtual bool import(QString fileName = QString(), int flags = lfUseCurrentPage|lfInteractive);
+		virtual bool importFile(QString fileName = QString(), int flags = lfUseCurrentPage|lfInteractive);
 
 	private:
 		void registerFormats();
