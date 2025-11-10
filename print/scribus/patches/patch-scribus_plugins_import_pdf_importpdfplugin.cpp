$NetBSD: patch-scribus_plugins_import_pdf_importpdfplugin.cpp,v 1.1 2025/11/10 13:54:53 wiz Exp $

--- scribus/plugins/import/pdf/importpdfplugin.cpp.orig	2025-01-25 21:57:14.000000000 +0000
+++ scribus/plugins/import/pdf/importpdfplugin.cpp
@@ -147,10 +147,10 @@ bool ImportPdfPlugin::fileSupported(QIOD
 bool ImportPdfPlugin::loadFile(const QString & fileName, const FileFormat &, int flags, int /*index*/)
 {
 	// There's only one format to handle, so we just call import(...)
-	return import(fileName, flags);
+	return importFile(fileName, flags);
 }
 
-bool ImportPdfPlugin::import(QString fileName, int flags)
+bool ImportPdfPlugin::importFile(QString fileName, int flags)
 {
 	if (!checkFlags(flags))
 		return false;
@@ -198,9 +198,9 @@ bool ImportPdfPlugin::import(QString fil
 	{
 		if (!ScCore->haveGS())
 		{
-			qApp->changeOverrideCursor(QCursor(Qt::ArrowCursor));
+			QApplication::changeOverrideCursor(QCursor(Qt::ArrowCursor));
 			ScMessageBox::warning(ScCore->primaryMainWindow(), CommonStrings::trWarning, tr("The Import plugin cannot handle PostScript files"));
-			qApp->changeOverrideCursor(QCursor(Qt::WaitCursor));
+			QApplication::changeOverrideCursor(QCursor(Qt::WaitCursor));
 			return false;
 		}
 
@@ -223,18 +223,20 @@ bool ImportPdfPlugin::import(QString fil
 		args.clear();
 		isCleanedFile = true;
 	}
+
 	bool ret = false;
-	PdfPlug *dia = new PdfPlug(m_Doc, flags);
-	Q_CHECK_PTR(dia);
+	auto pdfPlug = std::make_unique<PdfPlug>(m_Doc, flags);
+	Q_CHECK_PTR(pdfPlug.get());
 	if (isCleanedFile)
-		ret = dia->import(cleanFile, trSettings, flags, !(flags & lfScripted));
+		ret = pdfPlug->importFile(cleanFile, trSettings, flags, !(flags & lfScripted));
 	else
-		ret = dia->import(fileName, trSettings, flags, !(flags & lfScripted));
+		ret = pdfPlug->importFile(fileName, trSettings, flags, !(flags & lfScripted));
 	if (activeTransaction)
 		activeTransaction.commit();
 	if (emptyDoc || !(flags & lfInteractive) || !(flags & lfScripted))
 		UndoManager::instance()->setUndoEnabled(true);
-	delete dia;
+	pdfPlug.reset();
+
 	if (isCleanedFile)
 		QFile::remove(cleanFile);
 	return ret;
@@ -244,12 +246,13 @@ QImage ImportPdfPlugin::readThumbnail(co
 {
 	if (fileName.isEmpty())
 		return QImage();
+
 	UndoManager::instance()->setUndoEnabled(false);
 	m_Doc = nullptr;
-	PdfPlug *dia = new PdfPlug(m_Doc, lfCreateThumbnail);
-	Q_CHECK_PTR(dia);
-	QImage ret = dia->readThumbnail(fileName);
+	auto pdfPlug = std::make_unique<PdfPlug>(m_Doc, lfCreateThumbnail);
+	Q_CHECK_PTR(pdfPlug.get());
+	QImage ret = pdfPlug->readThumbnail(fileName);
 	UndoManager::instance()->setUndoEnabled(true);
-	delete dia;
+
 	return ret;
 }
