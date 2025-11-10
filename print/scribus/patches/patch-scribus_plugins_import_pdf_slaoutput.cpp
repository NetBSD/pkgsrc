$NetBSD: patch-scribus_plugins_import_pdf_slaoutput.cpp,v 1.1 2025/11/10 13:54:53 wiz Exp $

Sync with git head as of 2025-11-10 to fix build problems with qt, poppler, podofo.

--- scribus/plugins/import/pdf/slaoutput.cpp.orig	2025-01-25 21:57:14.000000000 +0000
+++ scribus/plugins/import/pdf/slaoutput.cpp
@@ -294,9 +294,9 @@ SlaOutputDev::~SlaOutputDev()
 }
 
 /* get Actions not implemented by Poppler */
-LinkAction* SlaOutputDev::SC_getAction(AnnotWidget *ano)
+std::unique_ptr<LinkAction> SlaOutputDev::SC_getAction(AnnotWidget *ano)
 {
-	LinkAction *linkAction = nullptr;
+	std::unique_ptr<LinkAction> linkAction;
 	Object obj;
 	Ref refa = ano->getRef();
 
@@ -311,11 +311,11 @@ LinkAction* SlaOutputDev::SC_getAction(A
 			Object actionObject = additionalActionsObject.dictLookup("S");
 			if (actionObject.isName("ImportData"))
 			{
-				linkAction = new LinkImportData(&additionalActionsObject);
+				linkAction.reset(new LinkImportData(&additionalActionsObject));
 			}
 			else if (actionObject.isName("SubmitForm"))
 			{
-				linkAction = new LinkSubmitForm(&additionalActionsObject);
+				linkAction.reset(new LinkSubmitForm(&additionalActionsObject));
 			}
 		}
 	}
@@ -580,7 +580,12 @@ bool SlaOutputDev::handleWidgetAnnot(Ann
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
@@ -1060,12 +1065,12 @@ void SlaOutputDev::handleActions(PageIte
 			}
 			else
 			{
-				LinkAction* scact = SC_getAction(ano);
+				std::unique_ptr<LinkAction> scact = SC_getAction(ano);
 				if (scact)
 				{
 					if (actString == "ImportData")
 					{
-						auto *impo = (LinkImportData*) scact;
+						auto *impo = (LinkImportData*) scact.get();
 						if (impo->isOk())
 						{
 							ite->annotation().setActionType(5);
@@ -1074,7 +1079,7 @@ void SlaOutputDev::handleActions(PageIte
 					}
 					else if (actString == "SubmitForm")
 					{
-						auto *impo = (LinkSubmitForm*) scact;
+						auto *impo = (LinkSubmitForm*) scact.get();
 						if (impo->isOk())
 						{
 							ite->annotation().setActionType(3);
@@ -1359,14 +1364,22 @@ void SlaOutputDev::restoreState(GfxState
 	m_graphicStack.restore();
 }
 
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 9, 0)
+void SlaOutputDev::beginTransparencyGroup(GfxState *state, const std::array<double, 4>& bbox, GfxColorSpace * /*blendingColorSpace*/, bool isolated, bool knockout, bool forSoftMask)
+#else
 void SlaOutputDev::beginTransparencyGroup(GfxState *state, const double *bbox, GfxColorSpace * /*blendingColorSpace*/, bool isolated, bool knockout, bool forSoftMask)
+#endif
 {
 // 	qDebug() << "SlaOutputDev::beginTransparencyGroup isolated:" << isolated << "knockout:" << knockout << "forSoftMask:" << forSoftMask;
 	pushGroup("", forSoftMask);
 	m_groupStack.top().isolated = isolated;
 }
 
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 9, 0)
+void SlaOutputDev::paintTransparencyGroup(GfxState *state, const std::array<double, 4>& bbox)
+#else
 void SlaOutputDev::paintTransparencyGroup(GfxState *state, const double *bbox)
+#endif
 {
 // 	qDebug() << "SlaOutputDev::paintTransparencyGroup";
 	if (m_groupStack.count() != 0)
@@ -1465,7 +1478,11 @@ void SlaOutputDev::endTransparencyGroup(
 	m_tmpSel->clear();
 }
 
-void SlaOutputDev::setSoftMask(GfxState * /*state*/, const double * bbox, bool alpha, Function *transferFunc, GfxColor * /*backdropColor*/)
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 9, 0)
+void SlaOutputDev::setSoftMask(GfxState* /*state*/, const std::array<double, 4>& bbox, bool alpha, Function* transferFunc, GfxColor* /*backdropColor*/)
+#else
+void SlaOutputDev::setSoftMask(GfxState* /*state*/, const double* bbox, bool alpha, Function* transferFunc, GfxColor* /*backdropColor*/)
+#endif
 {
 	if (m_groupStack.count() <= 0)
 		return;
@@ -1524,6 +1541,7 @@ void SlaOutputDev::adjustClip(GfxState *
 	QString output = convertPath(state->getPath());
 	if (output.isEmpty())
 		return;
+
 	FPointArray out;
 	out.parseSVG(output);
 	out.svgClosePath();
@@ -1547,6 +1565,7 @@ void SlaOutputDev::stroke(GfxState *stat
 {
 //	qDebug() << "Stroke";
 	const double *ctm = state->getCTM();
+	m_ctm = QTransform(ctm[0], ctm[1], ctm[2], ctm[3], ctm[4], ctm[5]);
 	double xCoor = m_doc->currentPage()->xOffset();
 	double yCoor = m_doc->currentPage()->yOffset();
 	getPenState(state);
@@ -1555,7 +1574,14 @@ void SlaOutputDev::stroke(GfxState *stat
 	graphicState.strokeColor = getColor(state->getStrokeColorSpace(), state->getStrokeColor(), &graphicState.strokeShade);
 
 	QString output = convertPath(state->getPath());
-	if ((m_Elements->count() != 0) && (output == m_coords))			// Path is the same as in last fill
+
+	FPointArray out;
+	out.parseSVG(output);
+	out.map(m_ctm);
+
+	// Path is the same as in last fill
+	if (!m_Elements->isEmpty() &&
+	    ((m_Elements->last()->PoLine == out) || (m_pathIsClosed && (m_coords == output))))
 	{
 		PageItem* ite = m_Elements->last();
 		ite->setLineColor(graphicState.strokeColor);
@@ -1569,10 +1595,6 @@ void SlaOutputDev::stroke(GfxState *stat
 		return;
 	}
 
-	FPointArray out;
-	out.parseSVG(output);
-	m_ctm = QTransform(ctm[0], ctm[1], ctm[2], ctm[3], ctm[4], ctm[5]);
-	out.map(m_ctm);
 	FPoint wh = out.widthHeight();
 	if ((out.size() <= 3) || ((wh.x() <= 0.0) && (wh.y() <= 0.0)))
 		return;
@@ -1673,40 +1695,40 @@ void SlaOutputDev::createFillItem(GfxSta
 	mm.rotate(angle);
 	clippedPath = mm.map(clippedPath);
 
-	m_coords = output;
 	QRectF bbox = clippedPath.boundingRect();
-	if (!clippedPath.isEmpty() && !bbox.isNull())
+	if (clippedPath.isEmpty() || bbox.isNull())
+		return;
+	m_coords = output;
+
+	graphicState.fillColor = getColor(state->getFillColorSpace(), state->getFillColor(), &graphicState.fillShade);
+	int z;
+	if (m_pathIsClosed)
+		z = m_doc->itemAdd(PageItem::Polygon, PageItem::Unspecified, xCoor, yCoor, 10, 10, 0, graphicState.fillColor, CommonStrings::None);
+	else
+		z = m_doc->itemAdd(PageItem::PolyLine, PageItem::Unspecified, xCoor, yCoor, 10, 10, 0, graphicState.fillColor, CommonStrings::None);
+	PageItem* ite = m_doc->Items->at(z);
+	ite->PoLine.fromQPainterPath(clippedPath, m_pathIsClosed);
+	ite->ClipEdited = true;
+	ite->FrameType = 3;
+	ite->setFillShade(graphicState.fillShade);
+	ite->setLineShade(100);
+	ite->setRotation(-angle);
+	// Only the new path has to be interpreted according to fillRule. QPainterPath
+	// could decide to create a final path according to the other rule. Thus
+	// we have to set this from the final path.
+	ite->setFillEvenOdd(clippedPath.fillRule() == Qt::OddEvenFill);
+	ite->setFillTransparency(1.0 - state->getFillOpacity());
+	ite->setFillBlendmode(getBlendMode(state));
+	ite->setLineEnd(m_lineEnd);
+	ite->setLineJoin(m_lineJoin);
+	ite->setWidthHeight(bbox.width(),bbox.height());
+	ite->setTextFlowMode(PageItem::TextFlowDisabled);
+	m_doc->adjustItemSize(ite);
+	m_Elements->append(ite);
+	if (m_groupStack.count() != 0)
 	{
-		graphicState.fillColor = getColor(state->getFillColorSpace(), state->getFillColor(), &graphicState.fillShade);
-		int z;
-		if (m_pathIsClosed)
-			z = m_doc->itemAdd(PageItem::Polygon, PageItem::Unspecified, xCoor, yCoor, 10, 10, 0, graphicState.fillColor, CommonStrings::None);
-		else
-			z = m_doc->itemAdd(PageItem::PolyLine, PageItem::Unspecified, xCoor, yCoor, 10, 10, 0, graphicState.fillColor, CommonStrings::None);
-		PageItem* ite = m_doc->Items->at(z);
-		ite->PoLine.fromQPainterPath(clippedPath, true);
-		ite->ClipEdited = true;
-		ite->FrameType = 3;
-		ite->setFillShade(graphicState.fillShade);
-		ite->setLineShade(100);
-		ite->setRotation(-angle);
-		// Only the new path has to be interpreted according to fillRule. QPainterPath
-		// could decide to create a final path according to the other rule. Thus
-		// we have to set this from the final path.
-		ite->setFillEvenOdd(clippedPath.fillRule() == Qt::OddEvenFill);
-		ite->setFillTransparency(1.0 - state->getFillOpacity());
-		ite->setFillBlendmode(getBlendMode(state));
-		ite->setLineEnd(m_lineEnd);
-		ite->setLineJoin(m_lineJoin);
-		ite->setWidthHeight(bbox.width(),bbox.height());
-		ite->setTextFlowMode(PageItem::TextFlowDisabled);
-		m_doc->adjustItemSize(ite);
-		m_Elements->append(ite);
-		if (m_groupStack.count() != 0)
-		{
-			m_groupStack.top().Items.append(ite);
-			applyMask(ite);
-		}
+		m_groupStack.top().Items.append(ite);
+		applyMask(ite);
 	}
 }
 
@@ -2215,11 +2237,20 @@ bool SlaOutputDev::patchMeshShadedFill(G
 	return true;
 }
 
-bool SlaOutputDev::tilingPatternFill(GfxState *state, Gfx * /*gfx*/, Catalog *cat, GfxTilingPattern *tPat, const double *mat, int x0, int y0, int x1, int y1, double xStep, double yStep)
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 9, 0)
+bool SlaOutputDev::tilingPatternFill(GfxState *state, Gfx* /*gfx*/, Catalog *cat, GfxTilingPattern *tPat, const std::array<double, 6>& mat, int x0, int y0, int x1, int y1, double xStep, double yStep)
+#else
+bool SlaOutputDev::tilingPatternFill(GfxState *state, Gfx* /*gfx*/, Catalog *cat, GfxTilingPattern *tPat, const double *mat, int x0, int y0, int x1, int y1, double xStep, double yStep)
+#endif
 {
 //	qDebug() << "SlaOutputDev::tilingPatternFill";
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 9, 0)
+	const std::array<double, 4>& bbox = tPat->getBBox();
+	const std::array<double, 6>& pmat = tPat->getMatrix();
+#else
 	const double *bbox = tPat->getBBox();
 	const double *pmat = tPat->getMatrix();
+#endif
 	Dict *resDict = tPat->getResDict();
 
 	PDFRectangle box;
@@ -2347,7 +2378,14 @@ void SlaOutputDev::drawImageMask(GfxStat
 {
 //	qDebug() << "Draw Image Mask";
 	auto imgStr = std::make_unique<ImageStream>(str, width, 1, 1);
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 02, 0)
+	bool resetDone = imgStr->reset();
+	if (!resetDone)
+		return;
+#else
 	imgStr->reset();
+#endif
+
 #ifdef WORDS_BIGENDIAN
 	QImage image(width, height, QImage::Format_Mono);
 #else
@@ -2421,7 +2459,14 @@ void SlaOutputDev::drawSoftMaskedImage(G
 {
 //	qDebug() << "SlaOutputDev::drawSoftMaskedImage Masked Image Components" << colorMap->getNumPixelComps();
 	auto imgStr = std::make_unique<ImageStream>(str, width, colorMap->getNumPixelComps(), colorMap->getBits());
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 02, 0)
+	bool resetDone = imgStr->reset();
+	if (!resetDone)
+		return;
+#else
 	imgStr->reset();
+#endif
+
 	unsigned int *dest = nullptr;
 	unsigned char * buffer = new unsigned char[width * height * 4];
 	for (int y = 0; y < height; y++)
@@ -2439,7 +2484,14 @@ void SlaOutputDev::drawSoftMaskedImage(G
 	}
 
 	auto mskStr = std::make_unique<ImageStream>(maskStr, maskWidth, maskColorMap->getNumPixelComps(), maskColorMap->getBits());
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 02, 0)
+	bool mskResetDone = mskStr->reset();
+	if (!mskResetDone)
+		return;
+#else
 	mskStr->reset();
+#endif
+
 	unsigned char *mdest = nullptr;
 	unsigned char * mbuffer = new unsigned char[maskWidth * maskHeight];
 	memset(mbuffer, 0, maskWidth * maskHeight);
@@ -2497,7 +2549,14 @@ void SlaOutputDev::drawMaskedImage(GfxSt
 {
 //	qDebug() << "SlaOutputDev::drawMaskedImage";
 	auto imgStr = std::make_unique<ImageStream>(str, width, colorMap->getNumPixelComps(), colorMap->getBits());
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 02, 0)
+	bool resetDone = imgStr->reset();
+	if (resetDone)
+		return;
+#else
 	imgStr->reset();
+#endif
+
 	unsigned int *dest = nullptr;
 	unsigned char * buffer = new unsigned char[width * height * 4];
 	for (int y = 0; y < height; y++)
@@ -2515,7 +2574,14 @@ void SlaOutputDev::drawMaskedImage(GfxSt
 	}
 
 	auto mskStr = std::make_unique<ImageStream>(maskStr, maskWidth, 1, 1);
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 02, 0)
+	bool mskResetDone = mskStr->reset();
+	if (!mskResetDone)
+		return;
+#else
 	mskStr->reset();
+#endif
+
 	unsigned char *mdest = nullptr;
 	int invert_bit = maskInvert ? 1 : 0;
 	unsigned char * mbuffer = new unsigned char[maskWidth * maskHeight];
@@ -2552,7 +2618,7 @@ void SlaOutputDev::drawMaskedImage(GfxSt
 		}
 	}
 
-	createImageFrame(res, state, colorMap->getNumPixelComps());
+	createImageFrame(res, state, 3);
 
 	delete[] buffer;
 	delete[] mbuffer;
@@ -2561,7 +2627,13 @@ void SlaOutputDev::drawMaskedImage(GfxSt
 void SlaOutputDev::drawImage(GfxState *state, Object *ref, Stream *str, int width, int height, GfxImageColorMap *colorMap, bool interpolate, const int* maskColors, bool inlineImg)
 {
 	auto imgStr = std::make_unique<ImageStream>(str, width, colorMap->getNumPixelComps(), colorMap->getBits());
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 02, 0)
+	bool resetDone = imgStr->reset();
+	if (!resetDone)
+		return;
+#else
 	imgStr->reset();
+#endif
 
 	QImage image(width, height, QImage::Format_ARGB32);
 	if (image.isNull())
@@ -2791,7 +2863,7 @@ void SlaOutputDev::beginMarkedContent(co
 	{
 		if (dictRef->isNull())
 			return;
-		OCGs *contentConfig = m_catalog->getOptContentConfig();
+		const OCGs *contentConfig = m_catalog->getOptContentConfig();
 		OptionalContentGroup *oc;
 		if (dictRef->isRef())
 		{
@@ -2928,7 +3000,11 @@ void SlaOutputDev::updateFont(GfxState *
 	SplashFontFile *fontFile;
 	SplashFontSrc *fontsrc = nullptr;
 	Object refObj, strObj;
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 2, 0)
+	std::vector<int> codeToGID;
+#else
 	int *codeToGID = nullptr;
+#endif
 	const double *textMat = nullptr;
 	double m11, m12, m21, m22, fontSize;
 	SplashCoord mat[4] = { 1.0, 0.0, 0.0, 1.0 };
@@ -3036,7 +3112,12 @@ void SlaOutputDev::updateFont(GfxState *
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
@@ -3055,10 +3136,20 @@ void SlaOutputDev::updateFont(GfxState *
 			}
 			else
 			{
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 2, 0)
+				codeToGID.clear();
+#else
 				codeToGID = nullptr;
+#endif
 				n = 0;
 			}
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 2, 0)
+			if (!(fontFile = m_fontEngine->loadTrueTypeFont(std::move(id), fontsrc, std::move(codeToGID), fontLoc->fontNum)))
+			{
+				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
+				goto err2;
+			}
+#elif POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
 			if (!(fontFile = m_fontEngine->loadTrueTypeFont(std::move(id), fontsrc, codeToGID, n, fontLoc->fontNum)))
 			{
 				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
@@ -3089,6 +3180,18 @@ void SlaOutputDev::updateFont(GfxState *
 #endif
 			break;
 		case fontCIDType0COT:
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 2, 0)
+			if (((GfxCIDFont*) gfxFont)->getCIDToGIDLen() > 0)
+			{
+				codeToGID = ((GfxCIDFont*) gfxFont)->getCIDToGID();
+				n = codeToGID.size();
+			}
+			else
+			{
+				codeToGID.clear();
+				n = 0;
+			}
+#else
 			if (((GfxCIDFont *) gfxFont)->getCIDToGID())
 			{
 				n = ((GfxCIDFont *) gfxFont)->getCIDToGIDLen();
@@ -3100,7 +3203,15 @@ void SlaOutputDev::updateFont(GfxState *
 				codeToGID = nullptr;
 				n = 0;
 			}
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
+#endif
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 2, 0)
+			if (!(fontFile = m_fontEngine->loadOpenTypeCFFFont(std::move(id), fontsrc, std::move(codeToGID), fontLoc->fontNum)))
+			{
+				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'",
+					gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
+				goto err2;
+			}
+#elif POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
 			if (!(fontFile = m_fontEngine->loadOpenTypeCFFFont(std::move(id), fontsrc, codeToGID, n, fontLoc->fontNum)))
 			{
 				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'",
@@ -3118,6 +3229,15 @@ void SlaOutputDev::updateFont(GfxState *
 			break;
 		case fontCIDType2:
 		case fontCIDType2OT:
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 2, 0)
+			codeToGID.clear();
+			n = 0;
+			if (((GfxCIDFont*) gfxFont)->getCIDToGIDLen() > 0)
+			{
+				codeToGID = ((GfxCIDFont*) gfxFont)->getCIDToGID();
+				n = codeToGID.size();
+			}
+#else
 			codeToGID = nullptr;
 			n = 0;
 			if (((GfxCIDFont *) gfxFont)->getCIDToGID())
@@ -3129,9 +3249,15 @@ void SlaOutputDev::updateFont(GfxState *
 					memcpy(codeToGID, ((GfxCIDFont *)gfxFont)->getCIDToGID(), n * sizeof(*codeToGID));
 				}
 			}
+#endif
 			else
 			{
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 7, 0)
+				if (!fileName.empty())
+					ff = FoFiTrueType::load(fileName.c_str(), fontLoc->fontNum);
+				else
+					ff = FoFiTrueType::make(fontsrc->buf, fontLoc->fontNum);
+#elif POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
 				if (!fileName.empty())
 					ff = FoFiTrueType::load(fileName.c_str(), fontLoc->fontNum);
 				else
@@ -3144,10 +3270,20 @@ void SlaOutputDev::updateFont(GfxState *
 #endif
 				if (! ff)
 					goto err2;
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 2, 0)
+				codeToGID = ((GfxCIDFont*) gfxFont)->getCodeToGIDMap(ff.get());
+#else
 				codeToGID = ((GfxCIDFont*) gfxFont)->getCodeToGIDMap(ff.get(), &n);
+#endif
 				ff.reset();
 			}
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 2, 0)
+			if (!(fontFile = m_fontEngine->loadTrueTypeFont(std::move(id), fontsrc, std::move(codeToGID), fontLoc->fontNum)))
+			{
+				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
+				goto err2;
+			}
+#elif POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
 			if (!(fontFile = m_fontEngine->loadTrueTypeFont(std::move(id), fontsrc, codeToGID, n, fontLoc->fontNum)))
 			{
 				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
@@ -3224,75 +3360,73 @@ void SlaOutputDev::drawChar(GfxState* st
 	// Invisible or only used for clipping
 	if (textRenderingMode == 3)
 		return;
-	if (textRenderingMode < 8)
+	if (textRenderingMode >= 8)
+		return;
+
+	SplashPath * fontPath = m_font->getGlyphPath(code);
+	if (!fontPath)
+		return;
+
+	QPainterPath qPath;
+	qPath.setFillRule(Qt::WindingFill);
+	for (int i = 0; i < fontPath->getLength(); ++i)
+	{
+		unsigned char f;
+		fontPath->getPoint(i, &x1, &y1, &f);
+		if (f & splashPathFirst)
+			qPath.moveTo(x1,y1);
+		else if (f & splashPathCurve)
+		{
+			double x3, y3;
+			++i;
+			fontPath->getPoint(i, &x2, &y2, &f);
+			++i;
+			fontPath->getPoint(i, &x3, &y3, &f);
+			qPath.cubicTo(x1, y1, x2, y2, x3, y3);
+		}
+		else
+			qPath.lineTo(x1, y1);
+		if (f & splashPathLast)
+			qPath.closeSubpath();
+	}
+	const double * ctm = state->getCTM();
+	m_ctm = QTransform(ctm[0], ctm[1], ctm[2], ctm[3], ctm[4], ctm[5]);
+	double xCoor = m_doc->currentPage()->xOffset();
+	double yCoor = m_doc->currentPage()->yOffset();
+	FPointArray textPath;
+	textPath.fromQPainterPath(qPath);
+	FPoint wh = textPath.widthHeight();
+	if (textRenderingMode > 3)
 	{
-		SplashPath * fontPath;
-		fontPath = m_font->getGlyphPath(code);
-		if (fontPath)
-		{
-			QPainterPath qPath;
-			qPath.setFillRule(Qt::WindingFill);
-			for (int i = 0; i < fontPath->getLength(); ++i)
-			{
-				unsigned char f;
-				fontPath->getPoint(i, &x1, &y1, &f);
-				if (f & splashPathFirst)
-					qPath.moveTo(x1,y1);
-				else if (f & splashPathCurve)
-				{
-					double x3, y3;
-					++i;
-					fontPath->getPoint(i, &x2, &y2, &f);
-					++i;
-					fontPath->getPoint(i, &x3, &y3, &f);
-					qPath.cubicTo(x1, y1, x2, y2, x3, y3);
-				}
-				else
-					qPath.lineTo(x1, y1);
-				if (f & splashPathLast)
-					qPath.closeSubpath();
-			}
-			const double * ctm = state->getCTM();
-			m_ctm = QTransform(ctm[0], ctm[1], ctm[2], ctm[3], ctm[4], ctm[5]);
-			double xCoor = m_doc->currentPage()->xOffset();
-			double yCoor = m_doc->currentPage()->yOffset();
-			FPointArray textPath;
-			textPath.fromQPainterPath(qPath);
-			FPoint wh = textPath.widthHeight();
-			if (textRenderingMode > 3)
-			{
-				QTransform mm;
-				mm.scale(1, -1);
-				mm.translate(x, -y);
-				// Remember the glyph for later clipping
- 				m_clipTextPath.addPath(m_ctm.map(mm.map(qPath)));
-			}
-			if ((textPath.size() > 3) && ((wh.x() != 0.0) || (wh.y() != 0.0)) && (textRenderingMode != 7))
-			{
-				int z = m_doc->itemAdd(PageItem::Polygon, PageItem::Unspecified, xCoor, yCoor, 10, 10, 0, CommonStrings::None, CommonStrings::None);
-				PageItem* ite = m_doc->Items->at(z);
-
-				// todo: merge this between vector and text implementations.
-				QTransform mm;
-				mm.scale(1, -1);
-				mm.translate(x, -y);
-				textPath.map(mm);
-				textPath.map(m_ctm);
-				ite->PoLine = textPath.copy();
-				setItemFillAndStroke(state, ite);
-				// Fill text rendering modes. See above
-				m_doc->adjustItemSize(ite);
-				m_Elements->append(ite);
-				if (m_groupStack.count() != 0)
-				{
-					m_groupStack.top().Items.append(ite);
-					applyMask(ite);
-				}
-			}
-			delete fontPath;
+		QTransform mm;
+		mm.scale(1, -1);
+		mm.translate(x, -y);
+		// Remember the glyph for later clipping
+ 		m_clipTextPath.addPath(m_ctm.map(mm.map(qPath)));
+	}
+	if ((textPath.size() > 3) && ((wh.x() != 0.0) || (wh.y() != 0.0)) && (textRenderingMode != 7))
+	{
+		int z = m_doc->itemAdd(PageItem::Polygon, PageItem::Unspecified, xCoor, yCoor, 10, 10, 0, CommonStrings::None, CommonStrings::None);
+		PageItem* ite = m_doc->Items->at(z);
 
+		// todo: merge this between vector and text implementations.
+		QTransform mm;
+		mm.scale(1, -1);
+		mm.translate(x, -y);
+		textPath.map(mm);
+		textPath.map(m_ctm);
+		ite->PoLine = textPath.copy();
+		setItemFillAndStroke(state, ite);
+		// Fill text rendering modes. See above
+		m_doc->adjustItemSize(ite);
+		m_Elements->append(ite);
+		if (m_groupStack.count() != 0)
+		{
+			m_groupStack.top().Items.append(ite);
+			applyMask(ite);
 		}
 	}
+	delete fontPath;
 }
 
 
@@ -3526,7 +3660,11 @@ QString SlaOutputDev::getAnnotationColor
 		return CommonStrings::None;
 	if (color->getSpace() == AnnotColor::colorRGB)
 	{
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 9, 0)
+		const std::array<double, 4>& color_data = color->getValues();
+#else
 		const double *color_data = color->getValues();
+#endif
 		double Rc = color_data[0];
 		double Gc = color_data[1];
 		double Bc = color_data[2];
@@ -3535,7 +3673,11 @@ QString SlaOutputDev::getAnnotationColor
 	}
 	else if (color->getSpace() == AnnotColor::colorCMYK)
 	{
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 9, 0)
+		const std::array<double, 4>& color_data = color->getValues();
+#else
 		const double *color_data = color->getValues();
+#endif
 		double Cc = color_data[0];
 		double Mc = color_data[1];
 		double Yc = color_data[2];
@@ -3545,7 +3687,11 @@ QString SlaOutputDev::getAnnotationColor
 	}
 	else if (color->getSpace() == AnnotColor::colorGray)
 	{
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 9, 0)
+		const std::array<double, 4>& color_data = color->getValues();
+#else
 		const double *color_data = color->getValues();
+#endif
 		double Kc = 1.0 - color_data[0];
 		tmp.setCmykColorF(0, 0, 0, Kc);
 		fNam = m_doc->PageColors.tryAddColor(namPrefix+tmp.name(), tmp);
@@ -3567,32 +3713,31 @@ QString SlaOutputDev::convertPath(const 
 	for (int i = 0; i < path->getNumSubpaths(); ++i)
 	{
 		const GfxSubpath * subpath = path->getSubpath(i);
-		if (subpath->getNumPoints() > 0)
-		{
-			output += QString("M %1 %2").arg(subpath->getX(0)).arg(subpath->getY(0));
-			int j = 1;
-			while (j < subpath->getNumPoints())
-			{
-				if (subpath->getCurve(j))
-				{
-					output += QString("C %1 %2 %3 %4 %5 %6")
-					.arg(subpath->getX(j)).arg(subpath->getY(j))
-					.arg(subpath->getX(j + 1)).arg(subpath->getY(j + 1))
-					.arg(subpath->getX(j + 2)).arg(subpath->getY(j + 2));
-					j += 3;
-				}
-				else
-				{
-					output += QString("L %1 %2").arg(subpath->getX(j)).arg(subpath->getY(j));
-					++j;
-				}
+		if (subpath->getNumPoints() <= 0)
+			continue;
+		output += QString("M %1 %2").arg(subpath->getX(0)).arg(subpath->getY(0));
+		int j = 1;
+		while (j < subpath->getNumPoints())
+		{
+			if (subpath->getCurve(j))
+			{
+				output += QString("C %1 %2 %3 %4 %5 %6")
+				.arg(subpath->getX(j)).arg(subpath->getY(j))
+				.arg(subpath->getX(j + 1)).arg(subpath->getY(j + 1))
+				.arg(subpath->getX(j + 2)).arg(subpath->getY(j + 2));
+				j += 3;
 			}
-			if (subpath->isClosed())
+			else
 			{
-				output += QString("Z");
-				m_pathIsClosed = true;
+				output += QString("L %1 %2").arg(subpath->getX(j)).arg(subpath->getY(j));
+				++j;
 			}
 		}
+		if (subpath->isClosed())
+		{
+			output += QString("Z");
+			m_pathIsClosed = true;
+		}
 	}
 	return output;
 }
@@ -3623,21 +3768,11 @@ void SlaOutputDev::getPenState(GfxState 
 			m_lineJoin = Qt::BevelJoin;
 			break;
 	}
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 9, 0)
 	const auto& dashPattern = state->getLineDash(&m_dashOffset);
 	QVector<double> pattern(dashPattern.size());
 	for (size_t i = 0; i < dashPattern.size(); ++i)
 		pattern[i] = dashPattern[i];
 	m_dashValues = pattern;
-#else
-	double* dashPattern;
-	int dashLength;
-	state->getLineDash(&dashPattern, &dashLength, &m_dashOffset);
-	QVector<double> pattern(dashLength);
-	for (int i = 0; i < dashLength; ++i)
-		pattern[i] = dashPattern[i];
-	m_dashValues = pattern;
-#endif
 }
 
 int SlaOutputDev::getBlendMode(GfxState *state) const
@@ -3748,6 +3883,41 @@ void SlaOutputDev::pushGroup(const QStri
 
 QString SlaOutputDev::UnicodeParsedString(const GooString *s1) const
 {
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 10, 0)
+	if (!s1 || s1->size() == 0)
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
+		result += QChar(u);
+	}
+	return result;
+#else
 	if (!s1 || s1->getLength() == 0)
 		return QString();
 	bool isUnicode;
@@ -3781,6 +3951,7 @@ QString SlaOutputDev::UnicodeParsedStrin
 		result += QChar( u );
 	}
 	return result;
+#endif
 }
 
 QString SlaOutputDev::UnicodeParsedString(const std::string& s1) const
