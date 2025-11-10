$NetBSD: patch-scribus_plugins_import_pdf_importpdf.cpp,v 1.1 2025/11/10 13:54:53 wiz Exp $

Sync with git head as of 2025-11-10 to fix build problems with qt, poppler, podofo.

--- scribus/plugins/import/pdf/importpdf.cpp.orig	2025-01-25 21:57:14.000000000 +0000
+++ scribus/plugins/import/pdf/importpdf.cpp
@@ -111,7 +111,7 @@ QImage PdfPlug::readThumbnail(const QStr
 	return image;
 }
 
-bool PdfPlug::import(const QString& fNameIn, const TransactionSettings& trSettings, int flags, bool showProgress)
+bool PdfPlug::importFile(const QString& fNameIn, const TransactionSettings& trSettings, int flags, bool showProgress)
 {
 #ifdef Q_OS_MACOS
 	showProgress = false;
@@ -142,7 +142,7 @@ bool PdfPlug::import(const QString& fNam
 		m_progressDialog->setProgress("GI", 0);
 		m_progressDialog->show();
 		connect(m_progressDialog, SIGNAL(canceled()), this, SLOT(cancelRequested()));
-		qApp->processEvents();
+		QApplication::processEvents();
 	}
 	else
 		m_progressDialog = nullptr;
@@ -150,7 +150,7 @@ bool PdfPlug::import(const QString& fNam
 	if (m_progressDialog)
 	{
 		m_progressDialog->setOverallProgress(1);
-		qApp->processEvents();
+		QApplication::processEvents();
 	}
 	double docWidth = PrefsManager::instance().appPrefs.docSetupPrefs.pageWidth;
 	double docHeight = PrefsManager::instance().appPrefs.docSetupPrefs.pageHeight;
@@ -170,7 +170,7 @@ bool PdfPlug::import(const QString& fNam
 		}
 	}
 
-	if ((ret) || (!m_interactive))
+	if (ret || !m_interactive)
 	{
 		if (docWidth > docHeight)
 			m_Doc->setPageOrientation(1);
@@ -186,7 +186,7 @@ bool PdfPlug::import(const QString& fNam
 	if ((!(flags & LoadSavePlugin::lfLoadAsPattern)) && (m_Doc->view() != nullptr))
 		m_Doc->view()->updatesOn(false);
 	m_Doc->scMW()->setScriptRunning(true);
-	qApp->setOverrideCursor(QCursor(Qt::WaitCursor));
+	QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
 	QString CurDirP = QDir::currentPath();
 	QDir::setCurrent(fi.path());
 	if (convert(fNameIn))
@@ -207,8 +207,8 @@ bool PdfPlug::import(const QString& fNam
 		m_Doc->DoDrawing = true;
 		m_Doc->scMW()->setScriptRunning(false);
 		m_Doc->setLoading(false);
-		qApp->changeOverrideCursor(QCursor(Qt::ArrowCursor));
-		if ((m_elements.count() > 0) && (!ret) && (m_interactive))
+		QApplication::changeOverrideCursor(QCursor(Qt::ArrowCursor));
+		if (!m_elements.isEmpty() && !ret && m_interactive)
 		{
 			if (flags & LoadSavePlugin::lfScripted)
 			{
@@ -269,7 +269,7 @@ bool PdfPlug::import(const QString& fNam
 		m_Doc->scMW()->setScriptRunning(false);
 		if (!(flags & LoadSavePlugin::lfLoadAsPattern))
 			m_Doc->view()->updatesOn(true);
-		qApp->changeOverrideCursor(QCursor(Qt::ArrowCursor));
+		QApplication::changeOverrideCursor(QCursor(Qt::ArrowCursor));
 		success = false;
 	}
 	if (m_interactive)
@@ -277,10 +277,10 @@ bool PdfPlug::import(const QString& fNam
 	//CB If we have a gui we must refresh it if we have used the progressbar
 	if (!(flags & LoadSavePlugin::lfLoadAsPattern))
 	{
-		if ((showProgress) && (!m_interactive))
+		if (showProgress && !m_interactive)
 			m_Doc->view()->DrawNew();
 	}
-	qApp->restoreOverrideCursor();
+	QApplication::restoreOverrideCursor();
 	return success;
 }
 
@@ -301,7 +301,7 @@ bool PdfPlug::convert(const QString& fn)
 		m_progressDialog->setOverallProgress(2);
 		m_progressDialog->setLabel("GI", tr("Generating Items"));
 		m_progressDialog->setBusyIndicator("GI");
-		qApp->processEvents();
+		QApplication::processEvents();
 	}
 
 	globalParams.reset(new GlobalParams());
@@ -318,7 +318,7 @@ bool PdfPlug::convert(const QString& fn)
 			pdfDoc = nullptr;
 			if (m_progressDialog)
 				m_progressDialog->hide();
-			qApp->changeOverrideCursor(QCursor(Qt::ArrowCursor));
+			QApplication::changeOverrideCursor(QCursor(Qt::ArrowCursor));
 			ScribusMainWindow* mw = m_Doc->scMW();
 			bool ok;
 			QString text = QInputDialog::getText(mw, tr("Open PDF-File"), tr("Password"), QLineEdit::Normal, "", &ok);
@@ -327,7 +327,7 @@ bool PdfPlug::convert(const QString& fn)
 				auto fname = std::make_unique<GooString>(encodedFileName.data());
 				std::optional<GooString> userPW(std::in_place, text.toLocal8Bit().data());
 				pdfDoc.reset(new PDFDoc(std::move(fname), userPW, userPW, nullptr));
-				qApp->changeOverrideCursor(QCursor(Qt::WaitCursor));
+				QApplication::changeOverrideCursor(QCursor(Qt::WaitCursor));
 			}
 			if ((!pdfDoc) || (pdfDoc->getErrorCode() != errNone))
 			{
@@ -368,7 +368,7 @@ bool PdfPlug::convert(const QString& fn)
 			{
 				if (m_progressDialog)
 					m_progressDialog->hide();
-				qApp->changeOverrideCursor(QCursor(Qt::ArrowCursor));
+				QApplication::changeOverrideCursor(QCursor(Qt::ArrowCursor));
 				PdfImportOptions optImp(ScCore->primaryMainWindow());
 				QFileInfo fi(fn);
 				optImp.setUpOptions(fi.fileName(), firstPage, lastPage, m_interactive, boxesAreDifferent, this);
@@ -391,7 +391,7 @@ bool PdfPlug::convert(const QString& fn)
 					useMediaBox = false;
 				if (cropped)
 					useMediaBox = true;
-				qApp->changeOverrideCursor(QCursor(Qt::WaitCursor));
+				QApplication::changeOverrideCursor(QCursor(Qt::WaitCursor));
 				if (m_progressDialog)
 					m_progressDialog->show();
 			}
@@ -400,7 +400,7 @@ bool PdfPlug::convert(const QString& fn)
 			if (m_progressDialog)
 			{
 				m_progressDialog->setTotalSteps("GI", pageNs.size());
-				qApp->processEvents();
+				QApplication::processEvents();
 			}
 			if (pageNs.size() <= 0) {
 				m_pdfDoc = nullptr;
@@ -416,11 +416,11 @@ bool PdfPlug::convert(const QString& fn)
 
 			if (dev->isOk())
 			{
-				OCGs* ocg = pdfDoc->getOptContentConfig();
+				const OCGs* ocg = pdfDoc->getOptContentConfig();
 				if (ocg && ocg->hasOCGs())
 				{
 					QStringList ocgNames;
-					Array *order = ocg->getOrderArray();
+					const Array *order = ocg->getOrderArray();
 					if (order)
 					{
 						for (int i = 0; i < order->getLength (); ++i)
@@ -510,22 +510,22 @@ bool PdfPlug::convert(const QString& fn)
 					{
 						Object obj;
 						Dict *infoDict = info.getDict();
-						obj = infoDict->lookup((char*) "Title");
+						obj = infoDict->lookup("Title");
 						if (obj.isString())
 						{
 							m_Doc->documentInfo().setTitle(UnicodeParsedString(obj.getString()));
 						}
-						obj = infoDict->lookup((char*) "Author");
+						obj = infoDict->lookup("Author");
 						if (obj.isString())
 						{
 							m_Doc->documentInfo().setAuthor(UnicodeParsedString(obj.getString()));
 						}
-						obj = infoDict->lookup((char*) "Subject");
+						obj = infoDict->lookup("Subject");
 						if (obj.isString())
 						{
 							m_Doc->documentInfo().setSubject(UnicodeParsedString(obj.getString()));
 						}
-						obj = infoDict->lookup((char*) "Keywords");
+						obj = infoDict->lookup("Keywords");
 						if (obj.isString())
 						{
 							//		s1 = obj.getString();
@@ -568,7 +568,7 @@ bool PdfPlug::convert(const QString& fn)
 						if (m_progressDialog)
 						{
 							m_progressDialog->setProgress("GI", i);
-							qApp->processEvents();
+							QApplication::processEvents();
 						}
 						int pp = pageNs[i];
 						m_Doc->setActiveLayer(baseLayer);
@@ -782,7 +782,7 @@ bool PdfPlug::convert(const QString& fn)
 //	qDebug() << "converting finished";
 //	qDebug() << "Imported" << m_elements.count() << "Elements";
 
-	if (m_elements.count() == 0)
+	if (m_elements.isEmpty())
 	{
 		for (int i = 0; i < m_importedColors.count(); i++)
 		{
@@ -872,8 +872,46 @@ QRectF PdfPlug::getCBox(int box, int pgN
 	return cRect;
 }
 
-QString PdfPlug::UnicodeParsedString(const GooString *s1)
+QString PdfPlug::UnicodeParsedString(const GooString *s1) const
 {
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 10, 0)
+	if (!s1 || s1->empty())
+		return QString();
+	bool isUnicode;
+	int i;
+	Unicode u;
+	QString result;
+	if ((s1->getChar(0) & 0xff) == 0xfe && (s1->size() > 1 && (s1->getChar(1) & 0xff) == 0xff))
+	{
+		isUnicode = true;
+		i = 2;
+		result.reserve((s1->size() - 2) / 2);
+	}
+	else
+	{
+		isUnicode = false;
+		i = 0;
+		result.reserve(s1->size());
+	}
+	while (i < s1->size())
+	{
+		if (isUnicode)
+		{
+			u = ((s1->getChar(i) & 0xff) << 8) | (s1->getChar(i + 1) & 0xff);
+			i += 2;
+		}
+		else
+		{
+			u = s1->getChar(i) & 0xff;
+			++i;
+		}
+		// #15616: imagemagick may write unicode strings incorrectly in PDF
+		if (u == 0)
+			continue;
+		result += QChar(u);
+	}
+	return result;
+#else
 	if (!s1 || s1->getLength() == 0)
 		return QString();
 	bool isUnicode;
@@ -910,9 +948,10 @@ QString PdfPlug::UnicodeParsedString(con
 		result += QChar( u );
 	}
 	return result;
+#endif
 }
 
-QString PdfPlug::UnicodeParsedString(const std::string& s1)
+QString PdfPlug::UnicodeParsedString(const std::string& s1) const
 {
 	if (s1.length() == 0)
 		return QString();
