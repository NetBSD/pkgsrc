$NetBSD: patch-scribus_plugins_import_pdf_importpdf.cpp,v 1.1 2022/09/29 00:17:01 markd Exp $

patches for poppler 22.03

--- scribus/plugins/import/pdf/importpdf.cpp.orig	2022-01-23 16:16:01.000000000 +0000
+++ scribus/plugins/import/pdf/importpdf.cpp
@@ -90,7 +90,11 @@ QImage PdfPlug::readThumbnail(const QStr
 #endif
 	globalParams->setErrQuiet(gTrue);
 
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 3, 0)
+	PDFDoc pdfDoc{ std::make_unique<GooString>(fname) };
+#else
 	PDFDoc pdfDoc{fname, nullptr, nullptr, nullptr};
+#endif
 	if (!pdfDoc.isOk() || pdfDoc.getErrorCode() == errEncrypted)
 		return QImage();
 
@@ -343,7 +347,11 @@ bool PdfPlug::convert(const QString& fn)
 	globalParams->setErrQuiet(gTrue);
 //	globalParams->setPrintCommands(gTrue);
 	QList<OptionalContentGroup*> ocgGroups;
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 3, 0)
+	auto pdfDoc = std::make_unique<PDFDoc>(std::make_unique<GooString>(fname));
+#else
 	auto pdfDoc = std::unique_ptr<PDFDoc>(new PDFDoc(fname, nullptr, nullptr, nullptr));
+#endif
 	if (pdfDoc)
 	{
 		if (pdfDoc->getErrorCode() == errEncrypted)
@@ -362,8 +370,13 @@ bool PdfPlug::convert(const QString& fn)
 #else
 				auto fname = new GooString(QFile::encodeName(fn).data());
 #endif
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 3, 0)
+				std::optional<GooString> userPW(std::in_place, text.toLocal8Bit().data());
+				pdfDoc.reset(new PDFDoc(std::make_unique<GooString>(fname), userPW, userPW, nullptr));
+#else
 				auto userPW = new GooString(text.toLocal8Bit().data());
 				pdfDoc.reset(new PDFDoc(fname, userPW, userPW, nullptr));
+#endif
 				qApp->changeOverrideCursor(QCursor(Qt::WaitCursor));
 			}
 			if ((!pdfDoc) || (pdfDoc->getErrorCode() != errNone))
