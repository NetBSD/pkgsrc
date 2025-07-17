$NetBSD: patch-scribus_plugins_import_pdf_slaoutput.cpp,v 1.5 2025/07/17 07:49:04 wiz Exp $

Fix build with poppler-25.07.0 (via ArchLinux)

--- scribus/plugins/import/pdf/slaoutput.cpp.orig	2025-04-20 13:52:19.000000000 +0000
+++ scribus/plugins/import/pdf/slaoutput.cpp
@@ -606,7 +606,12 @@ bool SlaOutputDev::handleWidgetAnnot(Ann
 		FormWidget *fm = m_formWidgets->getWidget(i);
 		if (!fm)
 			continue;
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 06, 0)
+		std::shared_ptr<AnnotWidget> anoSharedPtr = fm->getWidgetAnnotation();
+		AnnotWidget* ano = anoSharedPtr.get();
+#else
 		AnnotWidget *ano = fm->getWidgetAnnotation();
+#endif
 		if (!ano)
 			continue;
 		if (ano != (AnnotWidget*) annota)
@@ -3250,7 +3255,12 @@ void SlaOutputDev::updateFont(GfxState *
 			break;
 		case fontTrueType:
 		case fontTrueTypeOT:
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 7, 0)
+			if (!fileName.empty())
+				ff = FoFiTrueType::load(fileName.c_str(), fontLoc->fontNum);
+			else
+				ff = FoFiTrueType::make(fontsrc->buf, fontLoc->fontNum);
+#elif POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
 			if (!fileName.empty())
 				ff = FoFiTrueType::load(fileName.c_str(), fontLoc->fontNum);
 			else
@@ -3395,7 +3405,13 @@ void SlaOutputDev::updateFont(GfxState *
 #endif
 			else
 			{
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
+
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 7, 0)
+				if (!fileName.empty())
+					ff = FoFiTrueType::load(fileName.c_str(), fontLoc->fontNum);
+				else
+					ff = FoFiTrueType::make(fontsrc->buf, fontLoc->fontNum);
+#elif POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
 				if (!fileName.empty())
 					ff = FoFiTrueType::load(fileName.c_str(), fontLoc->fontNum);
 				else
