$NetBSD: patch-scribus_plugins_import_pdf_slaoutput.cpp,v 1.4 2024/11/12 21:46:56 markd Exp $

fix build with poppler 24.11.0 (via ArchLinux)

diff --git a/scribus/plugins/import/pdf/slaoutput.cpp b/scribus/plugins/import/pdf/slaoutput.cpp
index c002a88..f76bc00 100644
--- scribus/plugins/import/pdf/slaoutput.cpp
+++ scribus/plugins/import/pdf/slaoutput.cpp
@@ -8,9 +8,7 @@ for which a new license (GPL+exception) is in place.
 #include "slaoutput.h"
 
 #include <memory>
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 2, 0)
 #include <optional>
-#endif
 
 #include <poppler/GlobalParams.h>
 #include <poppler/poppler-config.h>
@@ -81,6 +79,8 @@ namespace
 	}
 }
 
+#if POPPLER_ENCODED_VERSION < POPPLER_VERSION_ENCODE(24, 10, 0)
+
 LinkSubmitForm::LinkSubmitForm(Object *actionObj)
 {
 	if (!actionObj->isDict())
@@ -92,12 +92,12 @@ LinkSubmitForm::LinkSubmitForm(Object *actionObj)
 		Object obj3 = obj1.dictLookup("FS");
 		if (!obj3.isNull() && obj3.isName())
 		{
-			POPPLER_CONST char *name = obj3.getName();
+			const char *name = obj3.getName();
 			if (!strcmp(name, "URL"))
 			{
 				Object obj2 = obj1.dictLookup("F");
 				if (!obj2.isNull())
-					fileName = obj2.getString()->copy();
+					m_url = obj2.getString()->copy();
 			}
 		}
 	}
@@ -108,9 +108,11 @@ LinkSubmitForm::LinkSubmitForm(Object *actionObj)
 
 LinkSubmitForm::~LinkSubmitForm()
 {
-	delete fileName;
+	delete m_url;
 }
 
+#endif
+
 LinkImportData::LinkImportData(Object *actionObj)
 {
 	if (!actionObj->isDict())
@@ -162,7 +164,7 @@ void AnoOutputDev::stroke(GfxState *state)
 	currColorStroke = getColor(state->getStrokeColorSpace(), state->getStrokeColor(), &shade);
 }
 
-void AnoOutputDev::drawString(GfxState *state, POPPLER_CONST GooString *s)
+void AnoOutputDev::drawString(GfxState *state, const GooString *s)
 {
 	int shade = 100;
 	currColorText = getColor(state->getFillColorSpace(), state->getFillColor(), &shade);
@@ -177,7 +179,7 @@ void AnoOutputDev::drawString(GfxState *state, POPPLER_CONST GooString *s)
 	itemText = s->copy();
 }
 
-QString AnoOutputDev::getColor(GfxColorSpace *color_space, POPPLER_CONST_070 GfxColor *color, int *shade)
+QString AnoOutputDev::getColor(GfxColorSpace *color_space, const GfxColor *color, int *shade)
 {
 	QString fNam;
 	QString namPrefix = "FromPDF";
@@ -218,7 +220,7 @@ QString AnoOutputDev::getColor(GfxColorSpace *color_space, POPPLER_CONST_070 Gfx
 	{
 		auto* sepColorSpace = (GfxSeparationColorSpace*) color_space;
 		GfxColorSpace* altColorSpace = sepColorSpace->getAlt();
-		QString name(sepColorSpace->getName()->getCString());
+		QString name(sepColorSpace->getName()->c_str());
 		bool isRegistrationColor = (name == "All");
 		if (isRegistrationColor)
 		{
@@ -308,8 +310,8 @@ LinkAction* SlaOutputDev::SC_getAction(AnnotWidget *ano)
 	obj = m_xref->fetch(refa.num, refa.gen);
 	if (obj.isDict())
 	{
-		Dict* adic = obj.getDict();
-		POPPLER_CONST_075 Object POPPLER_REF additionalActions = adic->lookupNF("A");
+		const Dict* adic = obj.getDict();
+		const Object & additionalActions = adic->lookupNF("A");
 		Object additionalActionsObject = additionalActions.fetch(m_pdfDoc->getXRef());
 		if (additionalActionsObject.isDict())
 		{
@@ -328,23 +330,17 @@ LinkAction* SlaOutputDev::SC_getAction(AnnotWidget *ano)
 }
 
 /* Replacement for the crippled Poppler function LinkAction* AnnotWidget::getAdditionalAction(AdditionalActionsType type) */
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
 std::unique_ptr<LinkAction> SlaOutputDev::SC_getAdditionalAction(const char *key, AnnotWidget *ano)
 {
 	std::unique_ptr<LinkAction> linkAction;
-#else
-LinkAction* SlaOutputDev::SC_getAdditionalAction(const char *key, AnnotWidget *ano)
-{
-	LinkAction *linkAction = nullptr;
-#endif
 	Object obj;
 	Ref refa = ano->getRef();
 
 	obj = m_xref->fetch(refa.num, refa.gen);
 	if (obj.isDict())
 	{
-		Dict* adic = obj.getDict();
-		POPPLER_CONST_075 Object POPPLER_REF additionalActions = adic->lookupNF("AA");
+		const Dict* adic = obj.getDict();
+		const Object & additionalActions = adic->lookupNF("AA");
 		Object additionalActionsObject = additionalActions.fetch(m_pdfDoc->getXRef());
 		if (additionalActionsObject.isDict())
 		{
@@ -356,7 +352,7 @@ LinkAction* SlaOutputDev::SC_getAdditionalAction(const char *key, AnnotWidget *a
 	return linkAction;
 }
 
-GBool SlaOutputDev::annotations_callback(Annot *annota, void *user_data)
+bool SlaOutputDev::annotations_callback(Annot *annota, void *user_data)
 {
 	auto *dev = (SlaOutputDev*) user_data;
 #if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 4, 0)
@@ -396,7 +392,7 @@ GBool SlaOutputDev::annotations_callback(Annot *annota, void *user_data)
 
 bool SlaOutputDev::handleTextAnnot(Annot* annota, double xCoor, double yCoor, double width, double height)
 {
-	auto *anl = (AnnotText*) annota;
+	const auto *anl = (AnnotText*) annota;
 	int z = m_doc->itemAdd(PageItem::TextFrame, PageItem::Rectangle, xCoor, yCoor, width, height, 0, CommonStrings::None, CommonStrings::None);
 	PageItem *ite = m_doc->Items->at(z);
 	int flg = annota->getFlags();
@@ -448,7 +444,7 @@ bool SlaOutputDev::handleTextAnnot(Annot* annota, double xCoor, double yCoor, do
 
 bool SlaOutputDev::handleLinkAnnot(Annot* annota, double xCoor, double yCoor, double width, double height)
 {
-	auto *anl = (AnnotLink*) annota;
+	const auto *anl = (AnnotLink*) annota;
 	LinkAction *act = anl->getAction();
 	if (!act)
 		return false;
@@ -459,8 +455,8 @@ bool SlaOutputDev::handleLinkAnnot(Annot* annota, double xCoor, double yCoor, do
 	QString fileName;
 	if (act->getKind() == actionGoTo)
 	{
-		auto *gto = (LinkGoTo*) act;
-		POPPLER_CONST LinkDest *dst = gto->getDest();
+		const auto *gto = (LinkGoTo*) act;
+		const LinkDest *dst = gto->getDest();
 		if (dst)
 		{
 			if (dst->getKind() == destXYZ)
@@ -468,11 +464,7 @@ bool SlaOutputDev::handleLinkAnnot(Annot* annota, double xCoor, double yCoor, do
 				if (dst->isPageRef())
 				{
 					Ref dstr = dst->getPageRef();
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 76, 0)
 					pagNum = m_pdfDoc->findPage(dstr);
-#else
-					pagNum = m_pdfDoc->findPage(dstr.num, dstr.gen);
-#endif
 				}
 				else
 					pagNum = dst->getPageNum();
@@ -483,24 +475,16 @@ bool SlaOutputDev::handleLinkAnnot(Annot* annota, double xCoor, double yCoor, do
 		}
 		else
 		{
-			POPPLER_CONST GooString *ndst = gto->getNamedDest();
+			const GooString *ndst = gto->getNamedDest();
 			if (ndst)
 			{
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
 				std::unique_ptr<LinkDest> dstn = m_pdfDoc->findDest(ndst);
-#else
-				LinkDest *dstn = m_pdfDoc->findDest(ndst);
-#endif
 				if (dstn && (dstn->getKind() == destXYZ))
 				{
 					if (dstn->isPageRef())
 					{
 						Ref dstr = dstn->getPageRef();
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 76, 0)
 						pagNum = m_pdfDoc->findPage(dstr);
-#else
-						pagNum = m_pdfDoc->findPage(dstr.num, dstr.gen);
-#endif
 					}
 					else
 						pagNum = dstn->getPageNum();
@@ -513,9 +497,9 @@ bool SlaOutputDev::handleLinkAnnot(Annot* annota, double xCoor, double yCoor, do
 	}
 	else if (act->getKind() == actionGoToR)
 	{
-		auto *gto = (LinkGoToR*) act;
+		const auto *gto = (LinkGoToR*) act;
 		fileName = UnicodeParsedString(gto->getFileName());
-		POPPLER_CONST LinkDest *dst = gto->getDest();
+		const LinkDest *dst = gto->getDest();
 		if (dst)
 		{
 			if (dst->getKind() == destXYZ)
@@ -528,14 +512,10 @@ bool SlaOutputDev::handleLinkAnnot(Annot* annota, double xCoor, double yCoor, do
 		}
 		else
 		{
-			POPPLER_CONST GooString *ndst = gto->getNamedDest();
+			const GooString *ndst = gto->getNamedDest();
 			if (ndst)
 			{
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
 				std::unique_ptr<LinkDest> dstn = m_pdfDoc->findDest(ndst);
-#else
-				LinkDest *dstn = m_pdfDoc->findDest(ndst);
-#endif
 				if (dstn && (dstn->getKind() == destXYZ))
 				{
 					pagNum = dstn->getPageNum();
@@ -548,7 +528,7 @@ bool SlaOutputDev::handleLinkAnnot(Annot* annota, double xCoor, double yCoor, do
 	}
 	else if (act->getKind() == actionURI)
 	{
-		auto *gto = (LinkURI*) act;
+		const auto *gto = (LinkURI*) act;
 		validLink = true;
 		fileName = UnicodeParsedString(gto->getURI());
 	}
@@ -621,7 +601,7 @@ bool SlaOutputDev::handleWidgetAnnot(Annot* annota, double xCoor, double yCoor,
 		int wtyp = -1;
 		if (fm->getType() == formButton)
 		{
-			auto *btn = (FormWidgetButton*) fm;
+			const auto *btn = (FormWidgetButton*) fm;
 			if (btn)
 			{
 				if (btn->getButtonType() == formButtonCheck)
@@ -648,7 +628,7 @@ bool SlaOutputDev::handleWidgetAnnot(Annot* annota, double xCoor, double yCoor,
 		}
 		else if (fm->getType() == formChoice)
 		{
-			auto *btn = (FormWidgetChoice*) fm;
+			const auto *btn = (FormWidgetChoice*) fm;
 			if (btn)
 			{
 				if (btn->isCombo())
@@ -670,7 +650,7 @@ bool SlaOutputDev::handleWidgetAnnot(Annot* annota, double xCoor, double yCoor,
 			bool bgFound = false;
 			if (achar)
 			{
-				POPPLER_CONST AnnotColor *bgCol = achar->getBackColor();
+				const AnnotColor *bgCol = achar->getBackColor();
 				if (bgCol)
 				{
 					bgFound = true;
@@ -678,7 +658,7 @@ bool SlaOutputDev::handleWidgetAnnot(Annot* annota, double xCoor, double yCoor,
 				}
 				else
 					m_graphicStack.top().fillColor = CommonStrings::None;
-				POPPLER_CONST AnnotColor *fgCol = achar->getBorderColor();
+				const AnnotColor *fgCol = achar->getBorderColor();
 				if (fgCol)
 				{
 					fgFound = true;
@@ -739,7 +719,7 @@ bool SlaOutputDev::handleWidgetAnnot(Annot* annota, double xCoor, double yCoor,
 			}
 			ite->setIsAnnotation(true);
 			ite->AutoName = false;
-			AnnotBorder *brd = annota->getBorder();
+			const AnnotBorder *brd = annota->getBorder();
 			if (brd)
 			{
 				int bsty = brd->getStyle();
@@ -761,7 +741,7 @@ bool SlaOutputDev::handleWidgetAnnot(Annot* annota, double xCoor, double yCoor,
 				ite->annotation().setBorderColor(CommonStrings::None);
 				ite->annotation().setBorderWidth(0);
 			}
-			QString tmTxt = UnicodeParsedString(fm->getPartialName());
+			QString tmTxt(UnicodeParsedString(fm->getPartialName()));
 			if (!tmTxt.isEmpty())
 				ite->setItemName(tmTxt);
 			tmTxt.clear();
@@ -794,7 +774,7 @@ bool SlaOutputDev::handleWidgetAnnot(Annot* annota, double xCoor, double yCoor,
 					ite->itemText.insertChars(itemText);
 				applyTextStyle(ite, fontName, currTextColor, fontSize);
 				ite->annotation().addToFlag(Annotation::Flag_PushButton);
-				auto *btn = (FormWidgetButton*) fm;
+				const auto *btn = (FormWidgetButton*) fm;
 				if (!btn->isReadOnly())
 					ite->annotation().addToFlag(Annotation::Flag_Edit);
 				handleActions(ite, ano);
@@ -829,7 +809,7 @@ bool SlaOutputDev::handleWidgetAnnot(Annot* annota, double xCoor, double yCoor,
 			}
 			else if (wtyp == Annotation::Checkbox)
 			{
-				auto *btn = (FormWidgetButton*) fm;
+				const auto *btn = (FormWidgetButton*) fm;
 				if (btn)
 				{
 					ite->annotation().setIsChk(btn->getState());
@@ -855,7 +835,7 @@ bool SlaOutputDev::handleWidgetAnnot(Annot* annota, double xCoor, double yCoor,
 			}
 			else if ((wtyp == Annotation::Combobox) || (wtyp == Annotation::Listbox))
 			{
-				auto *btn = (FormWidgetChoice*) fm;
+				const auto *btn = (FormWidgetChoice*) fm;
 				if (btn)
 				{
 					if (wtyp == 5)
@@ -878,7 +858,7 @@ bool SlaOutputDev::handleWidgetAnnot(Annot* annota, double xCoor, double yCoor,
 			}
 			else if (wtyp == Annotation::RadioButton)
 			{
-				auto *btn = (FormWidgetButton*) fm;
+				const auto *btn = (FormWidgetButton*) fm;
 				if (btn)
 				{
 					ite->setItemName( CommonStrings::itemName_RadioButton + QString("%1").arg(m_doc->TotalItems));
@@ -898,7 +878,7 @@ bool SlaOutputDev::handleWidgetAnnot(Annot* annota, double xCoor, double yCoor,
 		obj1 = m_xref->fetch(refa.num, refa.gen);
 		if (obj1.isDict())
 		{
-			Dict* dict = obj1.getDict();
+			const Dict* dict = obj1.getDict();
 			Object obj2 = dict->lookup("Kids");
 			//childs
 			if (obj2.isArray())
@@ -907,7 +887,7 @@ bool SlaOutputDev::handleWidgetAnnot(Annot* annota, double xCoor, double yCoor,
 				QList<int> radList;
 				for (int i = 0; i < obj2.arrayGetLength(); i++)
 				{
-					POPPLER_CONST_075 Object POPPLER_REF childRef = obj2.arrayGetNF(i);
+					const Object & childRef = obj2.arrayGetNF(i);
 					if (!childRef.isRef())
 						continue;
 					Object childObj = obj2.arrayGet(i);
@@ -966,7 +946,7 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotWidget *ano)
 	{
 		if (Lact->getKind() == actionJavaScript)
 		{
-			auto *jsa = (LinkJavaScript*) Lact;
+			const auto *jsa = (LinkJavaScript*) Lact;
 			if (jsa->isOk())
 			{
 				ite->annotation().setActionType(1);
@@ -978,8 +958,8 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotWidget *ano)
 			int pagNum = 0;
 			int xco = 0;
 			int yco = 0;
-			auto *gto = (LinkGoTo*) Lact;
-			POPPLER_CONST LinkDest *dst = gto->getDest();
+			const auto *gto = (LinkGoTo*) Lact;
+			const LinkDest *dst = gto->getDest();
 			if (dst)
 			{
 				if (dst->getKind() == destXYZ)
@@ -987,11 +967,7 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotWidget *ano)
 					if (dst->isPageRef())
 					{
 						Ref dstr = dst->getPageRef();
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 76, 0)
 						pagNum = m_pdfDoc->findPage(dstr);
-#else
-						pagNum = m_pdfDoc->findPage(dstr.num, dstr.gen);
-#endif
 					}
 					else
 						pagNum = dst->getPageNum();
@@ -1004,24 +980,16 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotWidget *ano)
 			}
 			else
 			{
-				POPPLER_CONST GooString *ndst = gto->getNamedDest();
+				const GooString *ndst = gto->getNamedDest();
 				if (ndst)
 				{
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
 					std::unique_ptr<LinkDest> dstn = m_pdfDoc->findDest(ndst);
-#else
-					LinkDest *dstn = m_pdfDoc->findDest(ndst);
-#endif
 					if (dstn && (dstn->getKind() == destXYZ))
 					{
 						if (dstn->isPageRef())
 						{
 							Ref dstr = dstn->getPageRef();
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 76, 0)
 							pagNum = m_pdfDoc->findPage(dstr);
-#else
-							pagNum = m_pdfDoc->findPage(dstr.num, dstr.gen);
-#endif
 						}
 						else
 							pagNum = dstn->getPageNum();
@@ -1039,9 +1007,9 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotWidget *ano)
 			int pagNum = 0;
 			int xco = 0;
 			int yco = 0;
-			auto *gto = (LinkGoToR*) Lact;
+			const auto *gto = (LinkGoToR*) Lact;
 			QString fileName = UnicodeParsedString(gto->getFileName());
-			POPPLER_CONST LinkDest *dst = gto->getDest();
+			const LinkDest *dst = gto->getDest();
 			if (dst)
 			{
 				if (dst->getKind() == destXYZ)
@@ -1057,14 +1025,10 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotWidget *ano)
 			}
 			else
 			{
-				POPPLER_CONST GooString *ndst = gto->getNamedDest();
+				const GooString *ndst = gto->getNamedDest();
 				if (ndst)
 				{
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
 					std::unique_ptr<LinkDest> dstn = m_pdfDoc->findDest(ndst);
-#else
-					LinkDest *dstn = m_pdfDoc->findDest(ndst);
-#endif
 					if (dstn && (dstn->getKind() == destXYZ))
 					{
 						pagNum = dstn->getPageNum();
@@ -1078,9 +1042,33 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotWidget *ano)
 				}
 			}
 		}
+		else if (Lact->getKind() == actionResetForm)
+		{
+			ite->annotation().setActionType(4);
+		}
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 10, 0)
+		else if (Lact->getKind() == actionSubmitForm)
+		{
+			const auto* impo = (LinkSubmitForm*) Lact;
+			if (impo->isOk())
+			{
+				ite->annotation().setActionType(3);
+				ite->annotation().setAction(UnicodeParsedString(impo->getUrl()));
+				int fl = impo->getFlags();
+				if (fl == 0)
+					ite->annotation().setHTML(0);
+				else if (fl == 4)
+					ite->annotation().setHTML(1);
+				else if (fl == 64)
+					ite->annotation().setHTML(2);
+				else if (fl == 512)
+					ite->annotation().setHTML(3);
+			}
+		}
+#endif
 		else if (Lact->getKind() == actionUnknown)
 		{
-			auto *uno = (LinkUnknown*) Lact;
+			const auto *uno = (LinkUnknown*) Lact;
 			QString actString = UnicodeParsedString(uno->getAction());
 			if (actString == "ResetForm")
 			{
@@ -1106,7 +1094,7 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotWidget *ano)
 						if (impo->isOk())
 						{
 							ite->annotation().setActionType(3);
-							ite->annotation().setAction(UnicodeParsedString(impo->getFileName()));
+							ite->annotation().setAction(UnicodeParsedString(impo->getUrl()));
 							int fl = impo->getFlags();
 							if (fl == 0)
 								ite->annotation().setHTML(0);
@@ -1123,7 +1111,7 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotWidget *ano)
 		}
 		else if (Lact->getKind() == actionNamed)
 		{
-			auto *uno = (LinkNamed*) Lact;
+			const auto *uno = (LinkNamed*) Lact;
 			ite->annotation().setActionType(10);
 			ite->annotation().setAction(UnicodeParsedString(uno->getName()));
 		}
@@ -1135,143 +1123,91 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotWidget *ano)
 	{
 		if (Aact->getKind() == actionJavaScript)
 		{
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
-			auto *jsa = (LinkJavaScript*) Aact.get();
-#else
-			auto *jsa = (LinkJavaScript*) Aact;
-#endif
+			const auto *jsa = (LinkJavaScript*) Aact.get();
 			if (jsa->isOk())
 			{
 				ite->annotation().setD_act(UnicodeParsedString(jsa->getScript()));
 				ite->annotation().setAAact(true);
 			}
 		}
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
 		Aact.reset();
-#else
-		Aact = nullptr;
-#endif
 	}
 	Aact = SC_getAdditionalAction("E", ano);
 	if (Aact)
 	{
 		if (Aact->getKind() == actionJavaScript)
 		{
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
-			auto *jsa = (LinkJavaScript*) Aact.get();
-#else
-			auto *jsa = (LinkJavaScript*) Aact;
-#endif
+			const auto *jsa = (LinkJavaScript*) Aact.get();
 			if (jsa->isOk())
 			{
 				ite->annotation().setE_act(UnicodeParsedString(jsa->getScript()));
 				ite->annotation().setAAact(true);
 			}
 		}
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
 		Aact.reset();
-#else
-		Aact = nullptr;
-#endif
 	}
 	Aact = SC_getAdditionalAction("X", ano);
 	if (Aact)
 	{
 		if (Aact->getKind() == actionJavaScript)
 		{
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
-			auto *jsa = (LinkJavaScript*) Aact.get();
-#else
-			auto *jsa = (LinkJavaScript*) Aact;
-#endif
+			const auto *jsa = (LinkJavaScript*) Aact.get();
 			if (jsa->isOk())
 			{
 				ite->annotation().setX_act(UnicodeParsedString(jsa->getScript()));
 				ite->annotation().setAAact(true);
 			}
 		}
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
 		Aact.reset();
-#else
-		Aact = nullptr;
-#endif
 	}
 	Aact = SC_getAdditionalAction("Fo", ano);
 	if (Aact)
 	{
 		if (Aact->getKind() == actionJavaScript)
 		{
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
-			auto *jsa = (LinkJavaScript*) Aact.get();
-#else
-			auto *jsa = (LinkJavaScript*) Aact;
-#endif
+			const auto *jsa = (LinkJavaScript*) Aact.get();
 			if (jsa->isOk())
 			{
 				ite->annotation().setFo_act(UnicodeParsedString(jsa->getScript()));
 				ite->annotation().setAAact(true);
 			}
 		}
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
 		Aact.reset();
-#else
-		Aact = nullptr;
-#endif
 	}
 	Aact = SC_getAdditionalAction("Bl", ano);
 	if (Aact)
 	{
 		if (Aact->getKind() == actionJavaScript)
 		{
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
-			auto *jsa = (LinkJavaScript*) Aact.get();
-#else
-			auto *jsa = (LinkJavaScript*) Aact;
-#endif
+			const auto *jsa = (LinkJavaScript*) Aact.get();
 			if (jsa->isOk())
 			{
 				ite->annotation().setBl_act(UnicodeParsedString(jsa->getScript()));
 				ite->annotation().setAAact(true);
 			}
 		}
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
 		Aact.reset();
-#else
-		Aact = nullptr;
-#endif
 	}
 	Aact = SC_getAdditionalAction("C", ano);
 	if (Aact)
 	{
 		if (Aact->getKind() == actionJavaScript)
 		{
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
-			auto *jsa = (LinkJavaScript*) Aact.get();
-#else
-			auto *jsa = (LinkJavaScript*) Aact;
-#endif
+			const auto *jsa = (LinkJavaScript*) Aact.get();
 			if (jsa->isOk())
 			{
 				ite->annotation().setC_act(UnicodeParsedString(jsa->getScript()));
 				ite->annotation().setAAact(true);
 			}
 		}
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
 		Aact.reset();
-#else
-		Aact = nullptr;
-#endif
 	}
 	Aact = SC_getAdditionalAction("F", ano);
 	if (Aact)
 	{
 		if (Aact->getKind() == actionJavaScript)
 		{
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
-			auto *jsa = (LinkJavaScript*) Aact.get();
-#else
-			autoz*jsa = (LinkJavaScript*) Aact;
-#endif
+			const auto *jsa = (LinkJavaScript*) Aact.get();
 			if (jsa->isOk())
 			{
 				ite->annotation().setF_act(UnicodeParsedString(jsa->getScript()));
@@ -1279,22 +1215,14 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotWidget *ano)
 				ite->annotation().setFormat(5);
 			}
 		}
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
 		Aact.reset();
-#else
-		Aact = nullptr;
-#endif
 	}
 	Aact = SC_getAdditionalAction("K", ano);
 	if (Aact)
 	{
 		if (Aact->getKind() == actionJavaScript)
 		{
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
-			auto *jsa = (LinkJavaScript*) Aact.get();
-#else
-			auto *jsa = (LinkJavaScript*) Aact;
-#endif
+			const auto *jsa = (LinkJavaScript*) Aact.get();
 			if (jsa->isOk())
 			{
 				ite->annotation().setK_act(UnicodeParsedString(jsa->getScript()));
@@ -1302,33 +1230,21 @@ void SlaOutputDev::handleActions(PageItem* ite, AnnotWidget *ano)
 				ite->annotation().setFormat(5);
 			}
 		}
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
 		Aact.reset();
-#else
-		Aact = nullptr;
-#endif
 	}
 	Aact = SC_getAdditionalAction("V", ano);
 	if (Aact)
 	{
 		if (Aact->getKind() == actionJavaScript)
 		{
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
-			auto *jsa = (LinkJavaScript*) Aact.get();
-#else
-			auto *jsa = (LinkJavaScript*) Aact;
-#endif
+			const auto *jsa = (LinkJavaScript*) Aact.get();
 			if (jsa->isOk())
 			{
 				ite->annotation().setV_act(UnicodeParsedString(jsa->getScript()));
 				ite->annotation().setAAact(true);
 			}
 		}
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
 		Aact.reset();
-#else
-		Aact = nullptr;
-#endif
 	}
 }
 
@@ -1338,11 +1254,7 @@ void SlaOutputDev::startDoc(PDFDoc *doc, XRef *xrefA, Catalog *catA)
 	m_catalog = catA;
 	m_pdfDoc = doc;
 	m_updateGUICounter = 0;
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 84, 0)
 	m_fontEngine = new SplashFontEngine(true, false, false, true);
-#else
-	m_fontEngine = new SplashFontEngine(globalParams->getEnableFreeType(), false, false, true);
-#endif
 }
 
 void SlaOutputDev::startPage(int pageNum, GfxState *, XRef *)
@@ -1459,18 +1371,18 @@ void SlaOutputDev::restoreState(GfxState *state)
 			}
 		}
 	}
-	
+
 	m_graphicStack.restore();
 }
 
-void SlaOutputDev::beginTransparencyGroup(GfxState *state, POPPLER_CONST_070 double *bbox, GfxColorSpace * /*blendingColorSpace*/, GBool isolated, GBool knockout, GBool forSoftMask)
+void SlaOutputDev::beginTransparencyGroup(GfxState *state, const double *bbox, GfxColorSpace * /*blendingColorSpace*/, bool isolated, bool knockout, bool forSoftMask)
 {
 // 	qDebug() << "SlaOutputDev::beginTransparencyGroup isolated:" << isolated << "knockout:" << knockout << "forSoftMask:" << forSoftMask;
 	pushGroup("", forSoftMask);
 	m_groupStack.top().isolated = isolated;
 }
 
-void SlaOutputDev::paintTransparencyGroup(GfxState *state, POPPLER_CONST_070 double *bbox)
+void SlaOutputDev::paintTransparencyGroup(GfxState *state, const double *bbox)
 {
 // 	qDebug() << "SlaOutputDev::paintTransparencyGroup";
 	if (m_groupStack.count() != 0)
@@ -1569,7 +1481,7 @@ void SlaOutputDev::endTransparencyGroup(GfxState *state)
 	m_tmpSel->clear();
 }
 
-void SlaOutputDev::setSoftMask(GfxState * /*state*/, POPPLER_CONST_070 double * bbox, GBool alpha, Function *transferFunc, GfxColor * /*backdropColor*/)
+void SlaOutputDev::setSoftMask(GfxState * /*state*/, const double * bbox, bool alpha, Function *transferFunc, GfxColor * /*backdropColor*/)
 {
 	if (m_groupStack.count() <= 0)
 		return;
@@ -1657,7 +1569,7 @@ void SlaOutputDev::stroke(GfxState *state)
 
 	auto& graphicState = m_graphicStack.top();
 	graphicState.strokeColor = getColor(state->getStrokeColorSpace(), state->getStrokeColor(), &graphicState.strokeShade);
-	
+
 	QString output = convertPath(state->getPath());
 	if ((m_Elements->count() != 0) && (output == m_coords))			// Path is the same as in last fill
 	{
@@ -1814,7 +1726,7 @@ void SlaOutputDev::createFillItem(GfxState *state, Qt::FillRule fillRule)
 	}
 }
 
-GBool SlaOutputDev::axialShadedFill(GfxState *state, GfxAxialShading *shading, double tMin, double tMax)
+bool SlaOutputDev::axialShadedFill(GfxState *state, GfxAxialShading *shading, double tMin, double tMax)
 {
 //	qDebug() << "SlaOutputDev::axialShadedFill";
 	double GrStartX;
@@ -1822,7 +1734,7 @@ GBool SlaOutputDev::axialShadedFill(GfxState *state, GfxAxialShading *shading, d
 	double GrEndX;
 	double GrEndY;
 	int shade = 100;
-	POPPLER_CONST_070 Function *func = shading->getFunc(0);
+	const Function *func = shading->getFunc(0);
 	VGradient fillGradient(VGradient::linear);
 	fillGradient.clearStops();
 	GfxColorSpace *color_space = shading->getColorSpace();
@@ -1832,7 +1744,7 @@ GBool SlaOutputDev::axialShadedFill(GfxState *state, GfxAxialShading *shading, d
 	if (func->getType() == 3)
 #endif
 	{
-		auto *stitchingFunc = (StitchingFunction*) func;
+		const auto *stitchingFunc = (const StitchingFunction*) func;
 		const double *bounds = stitchingFunc->getBounds();
 		int num_funcs = stitchingFunc->getNumFuncs();
 		double domain_min = stitchingFunc->getDomainMin(0);
@@ -1953,10 +1865,10 @@ GBool SlaOutputDev::axialShadedFill(GfxState *state, GfxAxialShading *shading, d
 		m_groupStack.top().Items.append(ite);
 		applyMask(ite);
 	}
-	return gTrue;
+	return true;
 }
 
-GBool SlaOutputDev::radialShadedFill(GfxState *state, GfxRadialShading *shading, double sMin, double sMax)
+bool SlaOutputDev::radialShadedFill(GfxState *state, GfxRadialShading *shading, double sMin, double sMax)
 {
 //	qDebug() << "SlaOutputDev::radialShadedFill";
 	double GrStartX;
@@ -1964,7 +1876,7 @@ GBool SlaOutputDev::radialShadedFill(GfxState *state, GfxRadialShading *shading,
 	double GrEndX;
 	double GrEndY;
 	int shade = 100;
-	POPPLER_CONST_070 Function *func = shading->getFunc(0);
+	const Function *func = shading->getFunc(0);
 	VGradient fillGradient(VGradient::linear);
 	fillGradient.clearStops();
 	GfxColorSpace *color_space = shading->getColorSpace();
@@ -1974,7 +1886,7 @@ GBool SlaOutputDev::radialShadedFill(GfxState *state, GfxRadialShading *shading,
 	if (func->getType() == 3)
 #endif
 	{
-		auto *stitchingFunc = (StitchingFunction*) func;
+		const auto *stitchingFunc = (const StitchingFunction*) func;
 		const double *bounds = stitchingFunc->getBounds();
 		int num_funcs = stitchingFunc->getNumFuncs();
 		double domain_min = stitchingFunc->getDomainMin(0);
@@ -2085,10 +1997,10 @@ GBool SlaOutputDev::radialShadedFill(GfxState *state, GfxRadialShading *shading,
 		m_groupStack.top().Items.append(ite);
 		applyMask(ite);
 	}
-	return gTrue;
+	return true;
 }
 
-GBool SlaOutputDev::gouraudTriangleShadedFill(GfxState *state, GfxGouraudTriangleShading *shading)
+bool SlaOutputDev::gouraudTriangleShadedFill(GfxState *state, GfxGouraudTriangleShading *shading)
 {
 //	qDebug() << "SlaOutputDev::gouraudTriangleShadedFill";
 	double xCoor = m_doc->currentPage()->xOffset();
@@ -2166,10 +2078,10 @@ GBool SlaOutputDev::gouraudTriangleShadedFill(GfxState *state, GfxGouraudTriangl
 		ite->meshGradientPatches.append(patchM);
 	}
 	ite->GrType = 12;
-	return gTrue;
+	return true;
 }
 
-GBool SlaOutputDev::patchMeshShadedFill(GfxState *state, GfxPatchMeshShading *shading)
+bool SlaOutputDev::patchMeshShadedFill(GfxState *state, GfxPatchMeshShading *shading)
 {
 //	qDebug() << "SlaOutputDev::patchMeshShadedFill";
 	double xCoor = m_doc->currentPage()->xOffset();
@@ -2316,21 +2228,15 @@ GBool SlaOutputDev::patchMeshShadedFill(GfxState *state, GfxPatchMeshShading *sh
 		ite->meshGradientPatches.append(patchM);
 	}
 	ite->GrType = 12;
-	return gTrue;
+	return true;
 }
 
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(21, 3, 0)
 bool SlaOutputDev::tilingPatternFill(GfxState *state, Gfx * /*gfx*/, Catalog *cat, GfxTilingPattern *tPat, const double *mat, int x0, int y0, int x1, int y1, double xStep, double yStep)
-#else
-GBool SlaOutputDev::tilingPatternFill(GfxState *state, Gfx * /*gfx*/, Catalog *cat, Object *str, POPPLER_CONST_070 double *pmat, int /*paintType*/, int /*tilingType*/, Dict *resDict, POPPLER_CONST_070 double *mat, POPPLER_CONST_070 double *bbox, int x0, int y0, int x1, int y1, double xStep, double yStep)
-#endif
 {
 //	qDebug() << "SlaOutputDev::tilingPatternFill";
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(21, 3, 0)
 	const double *bbox = tPat->getBBox();
 	const double *pmat = tPat->getMatrix();
 	Dict *resDict = tPat->getResDict();
-#endif
 
 	PDFRectangle box;
 	Gfx *gfx;
@@ -2342,7 +2248,7 @@ GBool SlaOutputDev::tilingPatternFill(GfxState *state, Gfx * /*gfx*/, Catalog *c
 	width = bbox[2] - bbox[0];
 	height = bbox[3] - bbox[1];
 	if (xStep != width || yStep != height)
-		return gFalse;
+		return false;
 	box.x1 = bbox[0];
 	box.y1 = bbox[1];
 	box.x2 = bbox[2];
@@ -2358,17 +2264,12 @@ GBool SlaOutputDev::tilingPatternFill(GfxState *state, Gfx * /*gfx*/, Catalog *c
 	// Unset the clip path as it is unrelated to the pattern's coordinate space.
 	QPainterPath savedClip = m_graphicStack.top().clipPath;
 	m_graphicStack.top().clipPath = QPainterPath();
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(21, 3, 0)
 	gfx->display(tPat->getContentStream());
-#else
-	gfx->display(str);
-#endif
 	m_graphicStack.top().clipPath = savedClip;
 	m_inPattern--;
-	gElements = m_groupStack.pop();
 	m_doc->m_Selection->clear();
-//	double pwidth = 0;
-//	double pheight = 0;
+
+	gElements = m_groupStack.pop();
 	if (gElements.Items.count() > 0)
 	{
 		for (int dre = 0; dre < gElements.Items.count(); ++dre)
@@ -2393,8 +2294,6 @@ GBool SlaOutputDev::tilingPatternFill(GfxState *state, Gfx * /*gfx*/, Catalog *c
 		m_doc->DoDrawing = false;
 		pat.width = ite->width();
 		pat.height = ite->height();
-	//	pwidth = ite->width();
-	//	pheight = ite->height();
 		ite->gXpos = 0;
 		ite->gYpos = 0;
 		ite->setXYPos(ite->gXpos, ite->gYpos, true);
@@ -2457,13 +2356,13 @@ GBool SlaOutputDev::tilingPatternFill(GfxState *state, Gfx * /*gfx*/, Catalog *c
 		applyMask(ite);
 	}
 	delete gfx;
-	return gTrue;
+	return true;
 }
 
-void SlaOutputDev::drawImageMask(GfxState *state, Object *ref, Stream *str, int width, int height, GBool invert, GBool interpolate, GBool inlineImg)
+void SlaOutputDev::drawImageMask(GfxState *state, Object *ref, Stream *str, int width, int height, bool invert, bool interpolate, bool inlineImg)
 {
 //	qDebug() << "Draw Image Mask";
-	auto imgStr = std::make_shared<ImageStream>(str, width, 1, 1);
+	auto imgStr = std::make_unique<ImageStream>(str, width, 1, 1);
 	imgStr->reset();
 #ifdef WORDS_BIGENDIAN
 	QImage image(width, height, QImage::Format_Mono);
@@ -2476,9 +2375,9 @@ void SlaOutputDev::drawImageMask(GfxState *state, Object *ref, Stream *str, int
 	int invertBit = invert ? 1 : 0;
 	unsigned char* buffer = image.bits();
 	unsigned char* dest = nullptr;
-	int rowStride = image.bytesPerLine();
+	qsizetype rowStride = image.bytesPerLine();
 	int i, bit;
-	Guchar* pix;
+	unsigned char* pix;
 
 	for (int y = 0; y < height; y++)
 	{
@@ -2533,18 +2432,18 @@ void SlaOutputDev::drawImageMask(GfxState *state, Object *ref, Stream *str, int
 	imgStr->close();
 }
 
-void SlaOutputDev::drawSoftMaskedImage(GfxState *state, Object *ref, Stream *str, int width, int height, GfxImageColorMap *colorMap, GBool interpolate, Stream *maskStr, int maskWidth, int maskHeight,
-				   GfxImageColorMap *maskColorMap, GBool maskInterpolate)
+void SlaOutputDev::drawSoftMaskedImage(GfxState *state, Object *ref, Stream *str, int width, int height, GfxImageColorMap *colorMap, bool interpolate, Stream *maskStr, int maskWidth, int maskHeight,
+				   GfxImageColorMap *maskColorMap, bool maskInterpolate)
 {
 //	qDebug() << "SlaOutputDev::drawSoftMaskedImage Masked Image Components" << colorMap->getNumPixelComps();
-	auto imgStr = std::make_shared<ImageStream>(str, width, colorMap->getNumPixelComps(), colorMap->getBits());
+	auto imgStr = std::make_unique<ImageStream>(str, width, colorMap->getNumPixelComps(), colorMap->getBits());
 	imgStr->reset();
 	unsigned int *dest = nullptr;
 	unsigned char * buffer = new unsigned char[width * height * 4];
 	for (int y = 0; y < height; y++)
 	{
 		dest = (unsigned int *)(buffer + y * 4 * width);
-		Guchar * pix = imgStr->getLine();
+		unsigned char * pix = imgStr->getLine();
 		colorMap->getRGBLine(pix, dest, width);
 	}
 
@@ -2555,15 +2454,15 @@ void SlaOutputDev::drawSoftMaskedImage(GfxState *state, Object *ref, Stream *str
 		return;
 	}
 
-	auto mskStr = std::make_shared<ImageStream>(maskStr, maskWidth, maskColorMap->getNumPixelComps(), maskColorMap->getBits());
+	auto mskStr = std::make_unique<ImageStream>(maskStr, maskWidth, maskColorMap->getNumPixelComps(), maskColorMap->getBits());
 	mskStr->reset();
-	Guchar *mdest = nullptr;
+	unsigned char *mdest = nullptr;
 	unsigned char * mbuffer = new unsigned char[maskWidth * maskHeight];
 	memset(mbuffer, 0, maskWidth * maskHeight);
 	for (int y = 0; y < maskHeight; y++)
 	{
-		mdest = (Guchar *)(mbuffer + y * maskWidth);
-		Guchar * pix = mskStr->getLine();
+		mdest = mbuffer + y * maskWidth;
+		unsigned char * pix = mskStr->getLine();
 		maskColorMap->getGrayLine(pix, mdest, maskWidth);
 	}
 	if ((maskWidth != width) || (maskHeight != height))
@@ -2571,7 +2470,7 @@ void SlaOutputDev::drawSoftMaskedImage(GfxState *state, Object *ref, Stream *str
 	QImage res = image.convertToFormat(QImage::Format_ARGB32);
 
 	int matteRc, matteGc, matteBc;
-	POPPLER_CONST_070 GfxColor *matteColor = maskColorMap->getMatteColor();
+	const GfxColor *matteColor = maskColorMap->getMatteColor();
 	if (matteColor != nullptr)
 	{
 		GfxRGB matteRgb;
@@ -2610,17 +2509,17 @@ void SlaOutputDev::drawSoftMaskedImage(GfxState *state, Object *ref, Stream *str
 	delete[] mbuffer;
 }
 
-void SlaOutputDev::drawMaskedImage(GfxState *state, Object *ref, Stream *str,  int width, int height, GfxImageColorMap *colorMap, GBool interpolate, Stream *maskStr, int maskWidth, int maskHeight, GBool maskInvert, GBool maskInterpolate)
+void SlaOutputDev::drawMaskedImage(GfxState *state, Object *ref, Stream *str,  int width, int height, GfxImageColorMap *colorMap, bool interpolate, Stream *maskStr, int maskWidth, int maskHeight, bool maskInvert, bool maskInterpolate)
 {
 //	qDebug() << "SlaOutputDev::drawMaskedImage";
-	auto imgStr = std::make_shared<ImageStream>(str, width, colorMap->getNumPixelComps(), colorMap->getBits());
+	auto imgStr = std::make_unique<ImageStream>(str, width, colorMap->getNumPixelComps(), colorMap->getBits());
 	imgStr->reset();
 	unsigned int *dest = nullptr;
 	unsigned char * buffer = new unsigned char[width * height * 4];
 	for (int y = 0; y < height; y++)
 	{
 		dest = (unsigned int *)(buffer + y * 4 * width);
-		Guchar * pix = imgStr->getLine();
+		unsigned char * pix = imgStr->getLine();
 		colorMap->getRGBLine(pix, dest, width);
 	}
 
@@ -2631,16 +2530,16 @@ void SlaOutputDev::drawMaskedImage(GfxState *state, Object *ref, Stream *str,  i
 		return;
 	}
 
-	auto mskStr = std::make_shared<ImageStream>(maskStr, maskWidth, 1, 1);
+	auto mskStr = std::make_unique<ImageStream>(maskStr, maskWidth, 1, 1);
 	mskStr->reset();
-	Guchar *mdest = nullptr;
+	unsigned char *mdest = nullptr;
 	int invert_bit = maskInvert ? 1 : 0;
 	unsigned char * mbuffer = new unsigned char[maskWidth * maskHeight];
 	memset(mbuffer, 0, maskWidth * maskHeight);
 	for (int y = 0; y < maskHeight; y++)
 	{
-		mdest = (Guchar *)(mbuffer + y * maskWidth);
-		Guchar * pix = mskStr->getLine();
+		mdest = mbuffer + y * maskWidth;
+		unsigned char * pix = mskStr->getLine();
 		for (int x = 0; x < maskWidth; x++)
 		{
 			if (pix[x] ^ invert_bit)
@@ -2675,9 +2574,9 @@ void SlaOutputDev::drawMaskedImage(GfxState *state, Object *ref, Stream *str,  i
 	delete[] mbuffer;
 }
 
-void SlaOutputDev::drawImage(GfxState *state, Object *ref, Stream *str, int width, int height, GfxImageColorMap *colorMap, GBool interpolate, POPPLER_CONST_082 int* maskColors, GBool inlineImg)
+void SlaOutputDev::drawImage(GfxState *state, Object *ref, Stream *str, int width, int height, GfxImageColorMap *colorMap, bool interpolate, const int* maskColors, bool inlineImg)
 {
-	auto imgStr = std::make_shared<ImageStream>(str, width, colorMap->getNumPixelComps(), colorMap->getBits());
+	auto imgStr = std::make_unique<ImageStream>(str, width, colorMap->getNumPixelComps(), colorMap->getBits());
 	imgStr->reset();
 
 	QImage image(width, height, QImage::Format_ARGB32);
@@ -2689,7 +2588,7 @@ void SlaOutputDev::drawImage(GfxState *state, Object *ref, Stream *str, int widt
 		for (int y = 0; y < height; y++)
 		{
 			QRgb *s = (QRgb*)(image.scanLine(y));
-			Guchar *pix = imgStr->getLine();
+			unsigned char *pix = imgStr->getLine();
 			for (int x = 0; x < width; x++)
 			{
 				GfxRGB rgb;
@@ -2716,7 +2615,7 @@ void SlaOutputDev::drawImage(GfxState *state, Object *ref, Stream *str, int widt
 		for (int y = 0; y < height; y++)
 		{
 			QRgb *s = (QRgb*)(image.scanLine(y));
-			Guchar *pix = imgStr->getLine();
+			unsigned char *pix = imgStr->getLine();
 			for (int x = 0; x < width; x++)
 			{
 				if (colorMap->getNumPixelComps() == 4)
@@ -2899,7 +2798,7 @@ void SlaOutputDev::createImageFrame(QImage& image, GfxState *state, int numColor
 	}
 }
 
-void SlaOutputDev::beginMarkedContent(POPPLER_CONST char *name, Object *dictRef)
+void SlaOutputDev::beginMarkedContent(const char *name, Object *dictRef)
 {
 	mContent mSte;
 	mSte.name = QString(name);
@@ -2925,14 +2824,14 @@ void SlaOutputDev::beginMarkedContent(POPPLER_CONST char *name, Object *dictRef)
 			Object dictObj = dictRef->fetch(m_xref);
 			if (!dictObj.isDict())
 				return;
-			Dict* dict = dictObj.getDict();
+			const Dict* dict = dictObj.getDict();
 			Object dictType = dict->lookup("Type");
 			if (dictType.isName("OCG"))
 			{
 				oc = contentConfig->findOcgByRef(dictRef->getRef());
 				if (oc)
 				{
-					//					qDebug() << "Begin OCG Content with Name " << UnicodeParsedString(oc->getName());
+//					qDebug() << "Begin OCG Content with Name " << UnicodeParsedString(oc->getName());
 					m_doc->setActiveLayer(UnicodeParsedString(oc->getName()));
 					mSte.ocgName = UnicodeParsedString(oc->getName());
 				}
@@ -2942,7 +2841,7 @@ void SlaOutputDev::beginMarkedContent(POPPLER_CONST char *name, Object *dictRef)
 	m_mcStack.push(mSte);
 }
 
-void SlaOutputDev::beginMarkedContent(POPPLER_CONST char *name, Dict *properties)
+void SlaOutputDev::beginMarkedContent(const char *name, Dict *properties)
 {
 //	qDebug() << "Begin Marked Content with Name " << QString(name);
 	QString nam(name);
@@ -2959,7 +2858,7 @@ void SlaOutputDev::beginMarkedContent(POPPLER_CONST char *name, Dict *properties
 			QString lName = QString("Layer_%1").arg(m_layerNum + 1);
 			Object obj = properties->lookup("Title");
 			if (obj.isString())
-				lName = QString(obj.getString()->getCString());
+				lName = QString(obj.getString()->c_str());
 			for (const auto& layer : m_doc->Layers)
 			{
 				if (layer.Name == lName)
@@ -3019,12 +2918,12 @@ void SlaOutputDev::endMarkedContent(GfxState *state)
 	}
 }
 
-void SlaOutputDev::markPoint(POPPLER_CONST char *name)
+void SlaOutputDev::markPoint(const char *name)
 {
 //	qDebug() << "Begin Marked Point with Name " << QString(name);
 }
 
-void SlaOutputDev::markPoint(POPPLER_CONST char *name, Dict *properties)
+void SlaOutputDev::markPoint(const char *name, Dict *properties)
 {
 //	qDebug() << "Begin Marked Point with Name " << QString(name) << "and Properties";
 	beginMarkedContent(name, properties);
@@ -3037,19 +2936,18 @@ void SlaOutputDev::updateFont(GfxState *state)
 	std::string fileName;
 	std::unique_ptr<FoFiTrueType> ff;
 	std::optional<std::vector<unsigned char>> tmpBuf;
-#elif POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 2, 0)
+#else
 	std::optional<GfxFontLoc> fontLoc;
 	const GooString * fileName = nullptr;
 	std::unique_ptr<FoFiTrueType> ff;
 	char* tmpBuf = nullptr;
-#else
-	GfxFontLoc * fontLoc = nullptr;
-	GooString * fileName = nullptr;
-	FoFiTrueType * ff = nullptr;
-	char* tmpBuf = nullptr;
 #endif
 	GfxFontType fontType;
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
+	std::unique_ptr<SlaOutFontFileID> id;
+#else
 	SlaOutFontFileID *id;
+#endif
 	SplashFontFile *fontFile;
 	SplashFontSrc *fontsrc = nullptr;
 	Object refObj, strObj;
@@ -3079,15 +2977,21 @@ void SlaOutputDev::updateFont(GfxState *state)
 		goto err1;
 
 	// check the font file cache
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
+	id = std::make_unique<SlaOutFontFileID>(gfxFont->getID());
+	if ((fontFile = m_fontEngine->getFontFile(*id)))
+		id.reset();
+#else
 	id = new SlaOutFontFileID(gfxFont->getID());
 	if ((fontFile = m_fontEngine->getFontFile(id)))
 		delete id;
+#endif
 	else
 	{
 		fontLoc = gfxFont->locateFont(m_xref ? m_xref : m_pdfDoc->getXRef(), nullptr);
 		if (!fontLoc)
 		{
-			error(errSyntaxError, -1, "Couldn't find a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+			error(errSyntaxError, -1, "Couldn't find a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
 			goto err2;
 		}
 
@@ -3111,10 +3015,8 @@ void SlaOutputDev::updateFont(GfxState *state)
 		{ // gfxFontLocExternal
 #if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 4, 0)
 			fileName = fontLoc->path;
-#elif POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 2, 0)
-			fileName = fontLoc->pathAsGooString();
 #else
-			fileName = fontLoc->path;
+			fileName = fontLoc->pathAsGooString();
 #endif
 			fontType = fontLoc->fontType;
 		}
@@ -3127,56 +3029,80 @@ void SlaOutputDev::updateFont(GfxState *state)
 			fontsrc->setBuf(std::move(tmpBuf.value()));
 #else
 		if (fileName)
-			fontsrc->setFile(fileName, gFalse);
+			fontsrc->setFile(fileName, false);
 		else
-			fontsrc->setBuf(tmpBuf, tmpBufLen, gTrue);
+			fontsrc->setBuf(tmpBuf, tmpBufLen, true);
 #endif
 
 		// load the font file
 		switch (fontType) {
 		case fontType1:
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
+			if (!(fontFile = m_fontEngine->loadType1Font(std::move(id), fontsrc, (const char**) ((Gfx8BitFont*) gfxFont)->getEncoding(), fontLoc->fontNum)))
+			{
+				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
+				goto err2;
+			}
+#else
 			if (!(fontFile = m_fontEngine->loadType1Font(id, fontsrc, (const char **)((Gfx8BitFont *) gfxFont)->getEncoding())))
 			{
-				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
 				goto err2;
 			}
+#endif
 			break;
 		case fontType1C:
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
+			if (!(fontFile = m_fontEngine->loadType1CFont(std::move(id), fontsrc, (const char**) ((Gfx8BitFont*) gfxFont)->getEncoding(), fontLoc->fontNum)))
+			{
+				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
+				goto err2;
+			}
+#else
 			if (!(fontFile = m_fontEngine->loadType1CFont(id, fontsrc, (const char **)((Gfx8BitFont *) gfxFont)->getEncoding())))
 			{
-				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
 				goto err2;
 			}
+#endif
 			break;
 		case fontType1COT:
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
+			if (!(fontFile = m_fontEngine->loadOpenTypeT1CFont(std::move(id), fontsrc, (const char **)((Gfx8BitFont *) gfxFont)->getEncoding(), fontLoc->fontNum)))
+			{
+				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
+				goto err2;
+			}
+#else
 			if (!(fontFile = m_fontEngine->loadOpenTypeT1CFont(id, fontsrc, (const char **)((Gfx8BitFont *) gfxFont)->getEncoding())))
 			{
-				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
 				goto err2;
 			}
+#endif
 			break;
 		case fontTrueType:
 		case fontTrueTypeOT:
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 4, 0)
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
+			if (!fileName.empty())
+				ff = FoFiTrueType::load(fileName.c_str(), fontLoc->fontNum);
+			else
+				ff = FoFiTrueType::make(fontsrc->buf.data(), fontsrc->buf.size(), fontLoc->fontNum);
+#elif POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 4, 0)
 			if (!fileName.empty())
 				ff = FoFiTrueType::load(fileName.c_str());
 			else
 				ff = FoFiTrueType::make(fontsrc->buf.data(), fontsrc->buf.size());
 #else
 			if (fileName)
-				ff = FoFiTrueType::load(fileName->getCString());
+				ff = FoFiTrueType::load(fileName->c_str());
 			else
 				ff = FoFiTrueType::make(tmpBuf, tmpBufLen);
 #endif
 			if (ff)
 			{
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 2, 0)
 				codeToGID = ((Gfx8BitFont*) gfxFont)->getCodeToGIDMap(ff.get());
 				ff.reset();
-#else
-				codeToGID = ((Gfx8BitFont *)gfxFont)->getCodeToGIDMap(ff);
-				delete ff;
-#endif
 				n = 256;
 			}
 			else
@@ -3184,19 +3110,35 @@ void SlaOutputDev::updateFont(GfxState *state)
 				codeToGID = nullptr;
 				n = 0;
 			}
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
+			if (!(fontFile = m_fontEngine->loadTrueTypeFont(std::move(id), fontsrc, codeToGID, n, fontLoc->fontNum)))
+			{
+				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
+				goto err2;
+			}
+#else
 			if (!(fontFile = m_fontEngine->loadTrueTypeFont(id, fontsrc, codeToGID, n)))
 			{
-				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
 				goto err2;
 			}
+#endif
 			break;
 		case fontCIDType0:
 		case fontCIDType0C:
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
+			if (!(fontFile = m_fontEngine->loadCIDFont(std::move(id), fontsrc, fontLoc->fontNum)))
+			{
+				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
+				goto err2;
+			}
+#else
 			if (!(fontFile = m_fontEngine->loadCIDFont(id, fontsrc)))
 			{
-				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
 				goto err2;
 			}
+#endif
 			break;
 		case fontCIDType0COT:
 			if (((GfxCIDFont *) gfxFont)->getCIDToGID())
@@ -3210,12 +3152,21 @@ void SlaOutputDev::updateFont(GfxState *state)
 				codeToGID = nullptr;
 				n = 0;
 			}
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
+			if (!(fontFile = m_fontEngine->loadOpenTypeCFFFont(std::move(id), fontsrc, codeToGID, n, fontLoc->fontNum)))
+			{
+				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'",
+					gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
+				goto err2;
+			}
+#else
 			if (!(fontFile = m_fontEngine->loadOpenTypeCFFFont(id, fontsrc, codeToGID, n)))
 			{
 				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'",
-				gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+				gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
 				goto err2;
 			}
+#endif
 			break;
 		case fontCIDType2:
 		case fontCIDType2OT:
@@ -3232,32 +3183,40 @@ void SlaOutputDev::updateFont(GfxState *state)
 			}
 			else
 			{
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 4, 0)
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
+				if (!fileName.empty())
+					ff = FoFiTrueType::load(fileName.c_str(), fontLoc->fontNum);
+				else
+					ff = FoFiTrueType::make(fontsrc->buf.data(), fontsrc->buf.size(), fontLoc->fontNum);
+#elif POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 4, 0)
 				if (!fileName.empty())
 					ff = FoFiTrueType::load(fileName.c_str());
 				else
 					ff = FoFiTrueType::make(fontsrc->buf.data(), fontsrc->buf.size());
 #else
 				if (fileName)
-					ff = FoFiTrueType::load(fileName->getCString());
+					ff = FoFiTrueType::load(fileName->c_str());
 				else
 					ff = FoFiTrueType::make(tmpBuf, tmpBufLen);
 #endif
 				if (! ff)
 					goto err2;
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 2, 0)
 				codeToGID = ((GfxCIDFont*) gfxFont)->getCodeToGIDMap(ff.get(), &n);
 				ff.reset();
-#else
-				codeToGID = ((GfxCIDFont *)gfxFont)->getCodeToGIDMap(ff, &n);
-				delete ff;
-#endif
 			}
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
+			if (!(fontFile = m_fontEngine->loadTrueTypeFont(std::move(id), fontsrc, codeToGID, n, fontLoc->fontNum)))
+			{
+				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
+				goto err2;
+			}
+#else
 			if (!(fontFile = m_fontEngine->loadTrueTypeFont(id, fontsrc, codeToGID, n, faceIndex)))
 			{
-				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->getCString() : "(unnamed)");
+				error(errSyntaxError, -1, "Couldn't create a font for '{0:s}'", gfxFont->getName() ? gfxFont->getName()->c_str() : "(unnamed)");
 				goto err2;
 			}
+#endif
 			break;
 		default:
 			// this shouldn't happen
@@ -3284,17 +3243,15 @@ void SlaOutputDev::updateFont(GfxState *state)
 	mat[3] = -m22;
 	m_font = m_fontEngine->getFont(fontFile, mat, matrix);
 
-#if POPPLER_ENCODED_VERSION < POPPLER_VERSION_ENCODE(22, 2, 0)
-	delete fontLoc;
-#endif
 	if (fontsrc && !fontsrc->isFile)
 		fontsrc->unref();
 	return;
 
 err2:
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
+	id.reset();
+#else
 	delete id;
-#if POPPLER_ENCODED_VERSION < POPPLER_VERSION_ENCODE(22, 2, 0)
-	delete fontLoc;
 #endif
 
 err1:
@@ -3302,7 +3259,7 @@ err1:
 		fontsrc->unref();
 }
 
-void SlaOutputDev::drawChar(GfxState* state, double x, double y, double dx, double dy, double originX, double originY, CharCode code, int nBytes, POPPLER_CONST_082 Unicode* u, int uLen)
+void SlaOutputDev::drawChar(GfxState* state, double x, double y, double dx, double dy, double originX, double originY, CharCode code, int nBytes, const Unicode* u, int uLen)
 {
 //	qDebug() << "SlaOutputDev::drawChar code:" << code << "bytes:" << nBytes << "Unicode:" << u << "ulen:" << uLen << "render:" << state->getRender();
 	double x1, y1, x2, y2;
@@ -3334,7 +3291,7 @@ void SlaOutputDev::drawChar(GfxState* state, double x, double y, double dx, doub
 			qPath.setFillRule(Qt::WindingFill);
 			for (int i = 0; i < fontPath->getLength(); ++i)
 			{
-				Guchar f;
+				unsigned char f;
 				fontPath->getPoint(i, &x1, &y1, &f);
 				if (f & splashPathFirst)
 					qPath.moveTo(x1,y1);
@@ -3396,25 +3353,25 @@ void SlaOutputDev::drawChar(GfxState* state, double x, double y, double dx, doub
 }
 
 
-GBool SlaOutputDev::beginType3Char(GfxState *state, double x, double y, double dx, double dy, CharCode code, POPPLER_CONST_082 Unicode *u, int uLen)
+bool SlaOutputDev::beginType3Char(GfxState *state, double x, double y, double dx, double dy, CharCode code, const Unicode *u, int uLen)
 {
 //	qDebug() << "beginType3Char";
 #if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(22, 4, 0)
 	GfxFont *gfxFont;
 	if (!(gfxFont = state->getFont().get()))
-		return gTrue;
+		return true;
 #else
 	GfxFont* gfxFont;
 	if (!(gfxFont = state->getFont()))
-		return gTrue;
+		return true;
 #endif
 	if (gfxFont->getType() != fontType3)
-		return gTrue;
+		return true;
 	F3Entry f3e;
 	f3e.colored = false;
 	m_F3Stack.push(f3e);
 	pushGroup();
-	return gFalse;
+	return false;
 }
 
 void SlaOutputDev::endType3Char(GfxState *state)
@@ -3514,7 +3471,7 @@ void SlaOutputDev::endTextObject(GfxState *state)
 	}
 }
 
-QString SlaOutputDev::getColor(GfxColorSpace *color_space, POPPLER_CONST_070 GfxColor *color, int *shade)
+QString SlaOutputDev::getColor(GfxColorSpace *color_space, const GfxColor *color, int *shade)
 {
 	QString fNam;
 	QString namPrefix = "FromPDF";
@@ -3561,7 +3518,7 @@ QString SlaOutputDev::getColor(GfxColorSpace *color_space, POPPLER_CONST_070 Gfx
 	{
 		auto* sepColorSpace = (GfxSeparationColorSpace*) color_space;
 		GfxColorSpace* altColorSpace = sepColorSpace->getAlt();
-		QString name(sepColorSpace->getName()->getCString());
+		QString name(sepColorSpace->getName()->c_str());
 		bool isRegistrationColor = (name == "All");
 		if (isRegistrationColor)
 		{
@@ -3661,7 +3618,7 @@ QString SlaOutputDev::getAnnotationColor(const AnnotColor *color)
 	return fNam;
 }
 
-QString SlaOutputDev::convertPath(POPPLER_CONST_083 GfxPath *path)
+QString SlaOutputDev::convertPath(const GfxPath *path)
 {
 //	qDebug() << "SlaOutputDev::convertPath";
 	if (! path)
@@ -3672,7 +3629,7 @@ QString SlaOutputDev::convertPath(POPPLER_CONST_083 GfxPath *path)
 
 	for (int i = 0; i < path->getNumSubpaths(); ++i)
 	{
-		POPPLER_CONST_083 GfxSubpath * subpath = path->getSubpath(i);
+		const GfxSubpath * subpath = path->getSubpath(i);
 		if (subpath->getNumPoints() > 0)
 		{
 			output += QString("M %1 %2").arg(subpath->getX(0)).arg(subpath->getY(0));
@@ -3736,7 +3693,7 @@ void SlaOutputDev::getPenState(GfxState *state)
 		pattern[i] = dashPattern[i];
 	m_dashValues = pattern;
 #else
-	double *dashPattern;
+	double* dashPattern;
 	int dashLength;
 	state->getLineDash(&dashPattern, &dashLength, &m_dashOffset);
 	QVector<double> pattern(dashLength);
@@ -3842,7 +3799,7 @@ void SlaOutputDev::applyMask(PageItem *ite)
 	}
 }
 
-void SlaOutputDev::pushGroup(const QString& maskName, GBool forSoftMask, GBool alpha, bool inverted)
+void SlaOutputDev::pushGroup(const QString& maskName, bool forSoftMask, bool alpha, bool inverted)
 {
 	groupEntry gElements;
 	gElements.forSoftMask = forSoftMask;
@@ -3852,23 +3809,23 @@ void SlaOutputDev::pushGroup(const QString& maskName, GBool forSoftMask, GBool a
 	m_groupStack.push(gElements);
 }
 
-QString SlaOutputDev::UnicodeParsedString(POPPLER_CONST GooString *s1) const
+QString SlaOutputDev::UnicodeParsedString(const GooString *s1) const
 {
 	if ( !s1 || s1->getLength() == 0 )
 		return QString();
-	GBool isUnicode;
+	bool isUnicode;
 	int i;
 	Unicode u;
 	QString result;
 	if ((s1->getChar(0) & 0xff) == 0xfe && (s1->getLength() > 1 && (s1->getChar(1) & 0xff) == 0xff))
 	{
-		isUnicode = gTrue;
+		isUnicode = true;
 		i = 2;
 		result.reserve((s1->getLength() - 2) / 2);
 	}
 	else
 	{
-		isUnicode = gFalse;
+		isUnicode = false;
 		i = 0;
 		result.reserve(s1->getLength());
 	}
@@ -3893,19 +3850,19 @@ QString SlaOutputDev::UnicodeParsedString(const std::string& s1) const
 {
 	if (s1.length() == 0)
 		return QString();
-	GBool isUnicode;
+	bool isUnicode;
 	size_t i;
 	Unicode u;
 	QString result;
 	if ((s1.at(0) & 0xff) == 0xfe && (s1.length() > 1 && (s1.at(1) & 0xff) == 0xff))
 	{
-		isUnicode = gTrue;
+		isUnicode = true;
 		i = 2;
 		result.reserve((s1.length() - 2) / 2);
 	}
 	else
 	{
-		isUnicode = gFalse;
+		isUnicode = false;
 		i = 0;
 		result.reserve(s1.length());
 	}
