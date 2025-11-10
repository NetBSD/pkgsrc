$NetBSD: patch-scribus_pdf__analyzer.cpp,v 1.1 2025/11/10 13:54:53 wiz Exp $

Fix build with podofo 1.0.
https://github.com/scribusproject/scribus/commit/760ff25fcc250099c0dca3949f62739be126c231

--- scribus/pdf_analyzer.cpp.orig	2025-01-25 21:57:41.000000000 +0000
+++ scribus/pdf_analyzer.cpp
@@ -272,7 +272,11 @@ bool PDFAnalyzer::inspectCanvas(PdfCanva
 	try
 	{
 		// start parsing the content stream
+#if (PODOFO_VERSION >= PODOFO_MAKE_VERSION(1, 0, 0))
+		PdfContentReaderArgs tokenizerArgs;
+#else
 		PdfContentReaderArgs tokenizerArgs = { PdfContentReaderFlags::DontFollowXObjectForms };
+#endif
 		PdfContentStreamReader tokenizer(*canvas, tokenizerArgs);
 		PdfContent pdfContent;
 		PdfVariant var;
@@ -285,13 +289,29 @@ bool PDFAnalyzer::inspectCanvas(PdfCanva
 		while (tokenizer.TryReadNext(pdfContent))
 		{
 			++tokenNumber;
+#if (PODOFO_VERSION >= PODOFO_MAKE_VERSION(1, 0, 0))
+			if (pdfContent.GetType() == PdfContentType::Operator)
+#else
 			if (pdfContent.Type == PdfContentType::Operator)
+#endif
 			{
 				args.clear();
+#if (PODOFO_VERSION >= PODOFO_MAKE_VERSION(1, 0, 0))
+				const auto& pdfContentStack = pdfContent.GetStack();
+				size_t stackSize = pdfContentStack.size();
+				for (size_t i = 0; i < stackSize; ++i)
+					args.append(pdfContentStack[stackSize - 1 - i]);
+#else
+
 				size_t stackSize = pdfContent.Stack.size();
 				for (size_t i = 0; i < stackSize; ++i)
 					args.append(pdfContent.Stack[stackSize - 1 - i]);
+#endif
+#if (PODOFO_VERSION >= PODOFO_MAKE_VERSION(1, 0, 0))
+				switch (pdfContent.GetOperator())
+#else
 				switch (pdfContent.Operator)
+#endif
 				{
 				case PdfOperator::q:
 					gsStack.push(currGS);
@@ -673,12 +693,23 @@ bool PDFAnalyzer::inspectCanvas(PdfCanva
 				}
 				args.clear();
 			}
+#if (PODOFO_VERSION >= PODOFO_MAKE_VERSION(1, 0, 0))
+			if (pdfContent.GetType() == PdfContentType::DoXObject)
+#else
 			if (pdfContent.Type == PdfContentType::DoXObject)
+#endif
 			{
 				args.clear();
+#if (PODOFO_VERSION >= PODOFO_MAKE_VERSION(1, 0, 0))
+				const auto& pdfContentStack = pdfContent.GetStack();
+				size_t stackSize = pdfContentStack.size();
+				for (size_t i = 0; i < stackSize; ++i)
+					args.append(pdfContentStack[stackSize - 1 - i]);
+#else
 				size_t stackSize = pdfContent.Stack.size();
 				for (size_t i = 0; i < stackSize; ++i)
 					args.append(pdfContent.Stack[stackSize - 1 - i]);
+#endif
 				if (!processedNamedXObj.contains(args[0].GetName()))
 				{
 					if (args.size() == 1 && args[0].IsName() && xObjectsDict)
