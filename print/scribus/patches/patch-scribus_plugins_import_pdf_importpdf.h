$NetBSD: patch-scribus_plugins_import_pdf_importpdf.h,v 1.1 2025/11/10 13:54:53 wiz Exp $

Sync with git head as of 2025-11-10 to fix build problems with qt, poppler, podofo.

--- scribus/plugins/import/pdf/importpdf.h.orig	2025-01-25 21:57:14.000000000 +0000
+++ scribus/plugins/import/pdf/importpdf.h
@@ -66,7 +66,7 @@ public:
 	\param showProgress if progress must be displayed
 	\retval bool true if import was ok
 	 */
-	bool import(const QString& fn, const TransactionSettings& trSettings, int flags, bool showProgress = true);
+	bool importFile(const QString& fn, const TransactionSettings& trSettings, int flags, bool showProgress = true);
 	QImage readThumbnail(const QString& fn);
 	QImage readPreview(int pgNum, int width, int height, int box);
 	enum PDF_Box_Type
@@ -81,8 +81,8 @@ public:
 private:
 	bool convert(const QString& fn);
 	QRectF getCBox(int box, int pgNum);
-	QString UnicodeParsedString(const GooString *s1);
-	QString UnicodeParsedString(const std::string& s1);
+	QString UnicodeParsedString(const GooString *s1) const;
+	QString UnicodeParsedString(const std::string& s1) const;
 	
 	QList<PageItem*> m_elements;
 
