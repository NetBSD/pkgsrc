$NetBSD: patch-scribus_pdflib__core.cpp,v 1.1 2025/11/10 13:54:53 wiz Exp $

Fix build with podofo 1.0.
https://github.com/scribusproject/scribus/commit/760ff25fcc250099c0dca3949f62739be126c231

--- scribus/pdflib_core.cpp.orig	2025-01-25 21:57:39.000000000 +0000
+++ scribus/pdflib_core.cpp
@@ -6188,7 +6188,7 @@ QByteArray PDFLibCore::PDF_TransparenzFi
 			float r, g, b;
 			qStopColor.getRgbF(&r, &g, &b);
 			if ((GType == GradMask_LinearLumAlpha) || (GType == GradMask_RadialLumAlpha))
-				a = /* 1.0 - */ (0.3 * r + 0.59 * g + 0.11 * b);
+				a = 0.3 * r + 0.59 * g + 0.11 * b;
 			if ((cst == 0) && (actualStop != 0.0))
 			{
 				stopVec.append(0.0);
@@ -9808,7 +9808,11 @@ bool PDFLibCore::PDF_EmbeddedPDF(PageIte
 		PoDoFo::PdfPage& page = doc->GetPages().GetPageAt(qMin(qMax(1, c->pixm.imgInfo.actualPageNumber), c->pixm.imgInfo.numberOfPages) - 1);
 		PoDoFo::PdfObject& pageObj = page.GetObject();
 		PoDoFo::PdfObject* contents = page.GetContents() ? &(page.GetContents()->GetObject()) : nullptr;
+#if (PODOFO_VERSION >= PODOFO_MAKE_VERSION(1, 0, 0))
+		const PoDoFo::PdfObject* resources = &(page.GetResources().GetObject());
+#else
 		PoDoFo::PdfObject* resources = page.GetResources() ? &(page.GetResources()->GetObject()) : nullptr;
+#endif
 		PoDoFo::PdfDictionary* pageObjDict = pageObj.IsDictionary() ? &(pageObj.GetDictionary()) : nullptr;
 		for (PoDoFo::PdfDictionary* par = pageObjDict, *parentDict = nullptr; par && !resources; par = parentDict)
 		{
@@ -9829,8 +9833,15 @@ bool PDFLibCore::PDF_EmbeddedPDF(PageIte
 			importedObjects[page.GetObject().GetIndirectReference()] = xObj;
 			writer.startObj(xObj);
 			PutDoc("<<\n/Type /XObject\n/Subtype /Form\n/FormType 1");
+#if (PODOFO_VERSION >= PODOFO_MAKE_VERSION(1, 0, 0))
+                       PoDoFo::Rect pageRect = page.GetArtBoxRaw().GetNormalized(); // Because scimagedataloader_pdf use ArtBox
+                       double rotation = 0;
+                       if (!page.TryGetRotationRaw(rotation))
+                               rotation = 0;
+#else
 			PoDoFo::Rect pageRect = page.GetArtBox(); // Because scimagedataloader_pdf use ArtBox
 			int rotation = page.GetRotationRaw();
+#endif
 			double imgWidth  = (rotation == 90 || rotation == 270) ? pageRect.Height : pageRect.Width;
 			double imgHeight = (rotation == 90 || rotation == 270) ? pageRect.Width : pageRect.Height;
 			QTransform pageM;
@@ -9950,8 +9961,15 @@ bool PDFLibCore::PDF_EmbeddedPDF(PageIte
 			importedObjects[page.GetObject().GetIndirectReference()] = xObj;
 			writer.startObj(xObj);
 			PutDoc("<<\n/Type /XObject\n/Subtype /Form\n/FormType 1");
+#if (PODOFO_VERSION >= PODOFO_MAKE_VERSION(1, 0, 0))
+                       PoDoFo::Rect pageRect = page.GetArtBoxRaw().GetNormalized(); // Because scimagedataloader_pdf use ArtBox
+                       double rotation = 0;
+                       if (!page.TryGetRotationRaw(rotation))
+                               rotation = 0;
+#else
 			PoDoFo::Rect pageRect = page.GetArtBox(); // Because scimagedataloader_pdf use ArtBox
 			int rotation = page.GetRotationRaw();
+#endif
 			double imgWidth  = (rotation == 90 || rotation == 270) ? pageRect.Height : pageRect.Width;
 			double imgHeight = (rotation == 90 || rotation == 270) ? pageRect.Width : pageRect.Height;
 			QTransform pageM;
