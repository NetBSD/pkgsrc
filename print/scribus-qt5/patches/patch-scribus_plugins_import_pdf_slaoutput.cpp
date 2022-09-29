$NetBSD: patch-scribus_plugins_import_pdf_slaoutput.cpp,v 1.2 2022/09/29 00:17:01 markd Exp $

patches for poppler 22.03, 22.04 and 22.09

--- scribus/plugins/import/pdf/slaoutput.cpp.orig	2022-01-23 16:16:01.000000000 +0000
+++ scribus/plugins/import/pdf/slaoutput.cpp
@@ -7,6 +7,11 @@ for which a new license (GPL+exception) 
 
 #include "slaoutput.h"
 
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 2, 0)
+#include <memory>
+#include <optional>
+#endif
+
 #include <poppler/GlobalParams.h>
 #include <poppler/poppler-config.h>
 #include <poppler/FileSpec.h>
@@ -169,8 +174,13 @@ void AnoOutputDev::drawString(GfxState *
 	int shade = 100;
 	currColorText = getColor(state->getFillColorSpace(), state->getFillColor(), &shade);
 	fontSize = state->getFontSize();
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 4, 0)
+	if (state->getFont() && state->getFont()->getName())
+		fontName = new GooString(state->getFont()->getName().value());
+#else
 	if (state->getFont())
 		fontName = state->getFont()->getName()->copy();
+#endif
 	itemText = s->copy();
 }
 
@@ -358,7 +368,12 @@ LinkAction* SlaOutputDev::SC_getAddition
 GBool SlaOutputDev::annotations_callback(Annot *annota, void *user_data)
 {
 	SlaOutputDev *dev = (SlaOutputDev*)user_data;
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 4, 0)
+	const PDFRectangle& annotRect = annota->getRect();;
+	const PDFRectangle* box = &annotRect;
+#else
 	PDFRectangle *box = annota->getRect();
+#endif
 	double xCoor = dev->m_doc->currentPage()->xOffset() + box->x1 - dev->cropOffsetX;
 	double yCoor = dev->m_doc->currentPage()->yOffset() + dev->m_doc->currentPage()->height() - box->y2 + dev->cropOffsetY;
 	double width = box->x2 - box->x1;
@@ -701,7 +716,12 @@ bool SlaOutputDev::handleWidgetAnnot(Ann
 			if (apa || !achar)
 			{
 				AnoOutputDev *annotOutDev = new AnoOutputDev(m_doc, m_importedColors);
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 4, 0)
+				const PDFRectangle& annotaRect = annota->getRect();
+				Gfx* gfx = new Gfx(pdfDoc, annotOutDev, pdfDoc->getPage(m_actPage)->getResourceDict(), &annotaRect, nullptr);
+#else
 				Gfx *gfx = new Gfx(pdfDoc, annotOutDev, pdfDoc->getPage(m_actPage)->getResourceDict(), annota->getRect(), nullptr);
+#endif
 				ano->draw(gfx, false);
 				if (!bgFound)
 					m_currColorFill = annotOutDev->currColorFill;
@@ -3026,19 +3046,30 @@ void SlaOutputDev::markPoint(POPPLER_CON
 
 void SlaOutputDev::updateFont(GfxState *state)
 {
-	GfxFont *gfxFont;
-	GfxFontLoc *fontLoc;
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 4, 0)
+	std::optional<GfxFontLoc> fontLoc;
+	std::string fileName;
+	std::unique_ptr<FoFiTrueType> ff;
+	std::optional<std::vector<unsigned char>> tmpBuf;
+#elif POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 2, 0)
+	std::optional<GfxFontLoc> fontLoc;
+	const GooString * fileName = nullptr;
+	std::unique_ptr<FoFiTrueType> ff;
+	char* tmpBuf = nullptr;
+#else
+	GfxFontLoc * fontLoc = nullptr;
+	GooString * fileName = nullptr;
+	FoFiTrueType * ff = nullptr;
+	char* tmpBuf = nullptr;
+#endif
 	GfxFontType fontType;
 	SlaOutFontFileID *id;
 	SplashFontFile *fontFile;
 	SplashFontSrc *fontsrc = nullptr;
-	FoFiTrueType *ff;
 	Object refObj, strObj;
-	GooString *fileName;
-	char *tmpBuf;
 	int tmpBufLen = 0;
-	int *codeToGID;
-	const double *textMat;
+	int *codeToGID = nullptr;
+	const double *textMat = nullptr;
 	double m11, m12, m21, m22, fontSize;
 	SplashCoord mat[4];
 	int n = 0;
@@ -3046,11 +3077,12 @@ void SlaOutputDev::updateFont(GfxState *
 	SplashCoord matrix[6];
 
 	m_font = nullptr;
-	fileName = nullptr;
-	tmpBuf = nullptr;
-	fontLoc = nullptr;
 
-	gfxFont = state->getFont();
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 4, 0)
+	GfxFont* gfxFont = state->getFont().get();
+#else
+	GfxFont* gfxFont = state->getFont();
+#endif
 	if (!gfxFont)
 		goto err1;
 
@@ -3064,10 +3096,10 @@ void SlaOutputDev::updateFont(GfxState *
 		delete id;
 	else
 	{
-		if (!(fontLoc = gfxFont->locateFont(xref, nullptr)))
+		fontLoc = gfxFont->locateFont((xref) ? xref : pdfDoc->getXRef(), nullptr);
+		if (!fontLoc)
 		{
-			error(errSyntaxError, -1, "Couldn't find a font for '{0:s}'",
-			gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+			error(errSyntaxError, -1, "Couldn't find a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
 			goto err2;
 		}
 
@@ -3075,94 +3107,106 @@ void SlaOutputDev::updateFont(GfxState *
 		if (fontLoc->locType == gfxFontLocEmbedded)
 		{
 			// if there is an embedded font, read it to memory
-			tmpBuf = gfxFont->readEmbFontFile(xref, &tmpBufLen);
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 4, 0)
+			tmpBuf = gfxFont->readEmbFontFile((xref) ? xref : pdfDoc->getXRef());
 			if (! tmpBuf)
 				goto err2;
+#else
+			tmpBuf = gfxFont->readEmbFontFile(xref, &tmpBufLen);
+			if (!tmpBuf)
+				goto err2;
+#endif
 
 			// external font
 		}
 		else
 		{ // gfxFontLocExternal
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 4, 0)
+			fileName = fontLoc->path;
+#elif POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 2, 0)
+			fileName = fontLoc->pathAsGooString();
+#else
 			fileName = fontLoc->path;
+#endif
 			fontType = fontLoc->fontType;
 		}
 
 		fontsrc = new SplashFontSrc;
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 4, 0)
+		if (!fileName.empty())
+			fontsrc->setFile(fileName);
+		else
+			fontsrc->setBuf(std::move(tmpBuf.value()));
+#else
 		if (fileName)
 			fontsrc->setFile(fileName, gFalse);
 		else
 			fontsrc->setBuf(tmpBuf, tmpBufLen, gTrue);
+#endif
 
 		// load the font file
 		switch (fontType) {
 		case fontType1:
-			if (!(fontFile = m_fontEngine->loadType1Font(
-				id,
-				fontsrc,
-				(const char **)((Gfx8BitFont *) gfxFont)->getEncoding())))
+			if (!(fontFile = m_fontEngine->loadType1Font(id, fontsrc, (const char **)((Gfx8BitFont *) gfxFont)->getEncoding())))
 			{
-				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'",
-				gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
 				goto err2;
 			}
 			break;
 		case fontType1C:
-			if (!(fontFile = m_fontEngine->loadType1CFont(
-							id,
-							fontsrc,
-							(const char **)((Gfx8BitFont *) gfxFont)->getEncoding())))
+			if (!(fontFile = m_fontEngine->loadType1CFont(id, fontsrc, (const char **)((Gfx8BitFont *) gfxFont)->getEncoding())))
 			{
-				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'",
-				gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
 				goto err2;
 			}
 			break;
 		case fontType1COT:
-			if (!(fontFile = m_fontEngine->loadOpenTypeT1CFont(
-							id,
-							fontsrc,
-							(const char **)((Gfx8BitFont *) gfxFont)->getEncoding())))
+			if (!(fontFile = m_fontEngine->loadOpenTypeT1CFont(id, fontsrc, (const char **)((Gfx8BitFont *) gfxFont)->getEncoding())))
 			{
-				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'",
-				gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
 				goto err2;
 			}
 			break;
 		case fontTrueType:
 		case fontTrueTypeOT:
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 4, 0)
+			if (!fileName.empty())
+				ff = FoFiTrueType::load(fileName.c_str());
+			else
+				ff = FoFiTrueType::make(fontsrc->buf.data(), fontsrc->buf.size());
+#else
 			if (fileName)
 				ff = FoFiTrueType::load(fileName->getCString());
 			else
 				ff = FoFiTrueType::make(tmpBuf, tmpBufLen);
+#endif
 			if (ff)
 			{
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 2, 0)
+				codeToGID = ((Gfx8BitFont*) gfxFont)->getCodeToGIDMap(ff.get());
+				ff.reset();
+#else
 				codeToGID = ((Gfx8BitFont *)gfxFont)->getCodeToGIDMap(ff);
-				n = 256;
 				delete ff;
+#endif
+				n = 256;
 			}
 			else
 			{
 				codeToGID = nullptr;
 				n = 0;
 			}
-			if (!(fontFile = m_fontEngine->loadTrueTypeFont(
-							id,
-							fontsrc,
-							codeToGID, n)))
+			if (!(fontFile = m_fontEngine->loadTrueTypeFont(id, fontsrc, codeToGID, n)))
 			{
-				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'",
-				gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
 				goto err2;
 			}
 			break;
 		case fontCIDType0:
 		case fontCIDType0C:
-			if (!(fontFile = m_fontEngine->loadCIDFont(
-							id,
-							fontsrc)))
+			if (!(fontFile = m_fontEngine->loadCIDFont(id, fontsrc)))
 			{
-				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'",
-				gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
 				goto err2;
 			}
 			break;
@@ -3178,10 +3222,7 @@ void SlaOutputDev::updateFont(GfxState *
 				codeToGID = nullptr;
 				n = 0;
 			}
-			if (!(fontFile = m_fontEngine->loadOpenTypeCFFFont(
-							id,
-							fontsrc,
-							codeToGID, n)))
+			if (!(fontFile = m_fontEngine->loadOpenTypeCFFFont(id, fontsrc, codeToGID, n)))
 			{
 				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'",
 				gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
@@ -3203,22 +3244,30 @@ void SlaOutputDev::updateFont(GfxState *
 			}
 			else
 			{
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 4, 0)
+				if (!fileName.empty())
+					ff = FoFiTrueType::load(fileName.c_str());
+				else
+					ff = FoFiTrueType::make(fontsrc->buf.data(), fontsrc->buf.size());
+#else
 				if (fileName)
 					ff = FoFiTrueType::load(fileName->getCString());
 				else
 					ff = FoFiTrueType::make(tmpBuf, tmpBufLen);
+#endif
 				if (! ff)
 					goto err2;
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 2, 0)
+				codeToGID = ((GfxCIDFont*) gfxFont)->getCodeToGIDMap(ff.get(), &n);
+				ff.reset();
+#else
 				codeToGID = ((GfxCIDFont *)gfxFont)->getCodeToGIDMap(ff, &n);
 				delete ff;
+#endif
 			}
-			if (!(fontFile = m_fontEngine->loadTrueTypeFont(
-							id,
-							fontsrc,
-							codeToGID, n, faceIndex)))
+			if (!(fontFile = m_fontEngine->loadTrueTypeFont(id, fontsrc, codeToGID, n, faceIndex)))
 			{
-				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'",
-				gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
 				goto err2;
 			}
 			break;
@@ -3247,14 +3296,19 @@ void SlaOutputDev::updateFont(GfxState *
 	mat[3] = -m22;
 	m_font = m_fontEngine->getFont(fontFile, mat, matrix);
 
+#if POPPLER_ENCODED_VERSION < POPPLER_VERSION_ENCODE(22, 2, 0)
 	delete fontLoc;
+#endif
 	if (fontsrc && !fontsrc->isFile)
 		fontsrc->unref();
 	return;
 
 err2:
 	delete id;
+#if POPPLER_ENCODED_VERSION < POPPLER_VERSION_ENCODE(22, 2, 0)
 	delete fontLoc;
+#endif
+
 err1:
 	if (fontsrc && !fontsrc->isFile)
 		fontsrc->unref();
@@ -3357,9 +3411,15 @@ void SlaOutputDev::drawChar(GfxState* st
 GBool SlaOutputDev::beginType3Char(GfxState *state, double x, double y, double dx, double dy, CharCode code, POPPLER_CONST_082 Unicode *u, int uLen)
 {
 //	qDebug() << "beginType3Char";
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 4, 0)
 	GfxFont *gfxFont;
+	if (!(gfxFont = state->getFont().get()))
+		return gTrue;
+#else
+	GfxFont* gfxFont;
 	if (!(gfxFont = state->getFont()))
 		return gTrue;
+#endif
 	if (gfxFont->getType() != fontType3)
 		return gTrue;
 	F3Entry f3e;
@@ -3681,9 +3741,16 @@ void SlaOutputDev::getPenState(GfxState 
 			break;
 	}
 	double lw = state->getLineWidth();
-	double *dashPattern;
 	int dashLength;
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 9, 0)
+	const double *dashPattern;
+	const std::vector<double> &dash = state->getLineDash(&DashOffset);
+	dashPattern = dash.data();
+	dashLength = dash.size();
+#else
+	double *dashPattern;
 	state->getLineDash(&dashPattern, &dashLength, &DashOffset);
+#endif
 	QVector<double> pattern(dashLength);
 	for (int i = 0; i < dashLength; ++i)
 	{
