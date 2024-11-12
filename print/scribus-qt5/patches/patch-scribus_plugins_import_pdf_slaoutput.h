$NetBSD: patch-scribus_plugins_import_pdf_slaoutput.h,v 1.3 2024/11/12 21:46:56 markd Exp $
        
fix build with poppler 24.11.0 (via ArchLinux)

diff --git a/scribus/plugins/import/pdf/slaoutput.h b/scribus/plugins/import/pdf/slaoutput.h
index 35de565..9eca5a8 100644
--- scribus/plugins/import/pdf/slaoutput.h
+++ scribus/plugins/import/pdf/slaoutput.h
@@ -30,9 +30,6 @@ for which a new license (GPL+exception) is in place.
 #include "selection.h"
 #include "vgradient.h"
 
-#if POPPLER_ENCODED_VERSION < POPPLER_VERSION_ENCODE(0, 73, 0)
-#include <poppler/goo/gtypes.h>
-#endif
 #include <poppler/Object.h>
 #include <poppler/OutputDev.h>
 #include <poppler/Gfx.h>
@@ -56,9 +53,11 @@ for which a new license (GPL+exception) is in place.
 #include <poppler/splash/SplashGlyphBitmap.h>
 
 //------------------------------------------------------------------------
-// LinkSubmitData
+// LinkSubmitForm
 //------------------------------------------------------------------------
 
+#if POPPLER_ENCODED_VERSION < POPPLER_VERSION_ENCODE(24, 10, 0)
+
 class LinkSubmitForm: public LinkAction
 {
 public:
@@ -68,17 +67,19 @@ public:
 	virtual ~LinkSubmitForm();
 
 	// Was the LinkImportData created successfully?
-	GBool isOk() POPPLER_CONST override { return fileName != nullptr; }
+	bool isOk() const override { return m_url != nullptr; }
 	// Accessors.
-	LinkActionKind getKind() POPPLER_CONST override { return actionUnknown; }
-	GooString *getFileName() { return fileName; }
+	LinkActionKind getKind() const override { return actionUnknown; }
+	GooString *getUrl() { return m_url; }
 	int getFlags() { return m_flags; }
 
 private:
-	GooString *fileName {nullptr};		// file name
+	GooString *m_url {nullptr};		// URL
 	int m_flags {0};
 };
 
+#endif
+
 //------------------------------------------------------------------------
 // LinkImportData
 //------------------------------------------------------------------------
@@ -92,9 +93,9 @@ public:
 	virtual ~LinkImportData();
 
 	// Was the LinkImportData created successfully?
-	GBool isOk() POPPLER_CONST override { return fileName != nullptr; }
+	bool isOk() const override { return fileName != nullptr; }
 	// Accessors.
-	LinkActionKind getKind() POPPLER_CONST override { return actionUnknown; }
+	LinkActionKind getKind() const override { return actionUnknown; }
 	GooString *getFileName() { return fileName; }
 
 private:
@@ -111,10 +112,17 @@ public:
 	SlaOutFontFileID(const Ref *rA) { r = *rA; }
 	~SlaOutFontFileID() {}
 
-	GBool matches(SplashFontFileID *id) override
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(24, 11, 0)
+	bool matches(const SplashFontFileID& id) const override
+	{
+		return ((const SlaOutFontFileID&) id).r.num == r.num && ((const SlaOutFontFileID&) id).r.gen == r.gen;
+	}
+#else
+	bool matches(SplashFontFileID *id) override
 	{
 		return ((SlaOutFontFileID*) id)->r.num == r.num && ((SlaOutFontFileID *) id)->r.gen == r.gen;
 	}
+#endif
 
 private:
 	Ref r;
@@ -127,19 +135,19 @@ public:
 	AnoOutputDev(ScribusDoc* doc, QStringList *importedColors);
 	virtual ~AnoOutputDev();
 
-	GBool isOk() { return gTrue; }
-	GBool upsideDown() override { return gTrue; }
-	GBool useDrawChar() override { return gFalse; }
-	GBool interpretType3Chars() override { return gFalse; }
-	GBool useTilingPatternFill() override  { return gFalse; }
-	GBool useShadedFills(int type) override { return gFalse; }
-	GBool useFillColorStop() override { return gFalse; }
-	GBool useDrawForm() override { return gFalse; }
+	bool isOk() { return true; }
+	bool upsideDown() override { return true; }
+	bool useDrawChar() override { return false; }
+	bool interpretType3Chars() override { return false; }
+	bool useTilingPatternFill() override  { return false; }
+	bool useShadedFills(int type) override { return false; }
+	bool useFillColorStop() override { return false; }
+	bool useDrawForm() override { return false; }
 
 	void stroke(GfxState *state) override;
 	void eoFill(GfxState *state) override;
 	void fill(GfxState *state) override;
-	void drawString(GfxState *state, POPPLER_CONST GooString *s) override;
+	void drawString(GfxState *state, const GooString *s) override;
 
 	QString currColorText;
 	QString currColorFill;
@@ -149,7 +157,7 @@ public:
 	GooString *itemText {nullptr};
 
 private:
-	QString getColor(GfxColorSpace *color_space, POPPLER_CONST_070 GfxColor *color, int *shade);
+	QString getColor(GfxColorSpace *color_space, const GfxColor *color, int *shade);
 	ScribusDoc* m_doc;
 	QStringList *m_importedColors;
 };
@@ -163,12 +171,8 @@ public:
 	virtual ~SlaOutputDev();
 
 	LinkAction* SC_getAction(AnnotWidget *ano);
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(0, 86, 0)
 	std::unique_ptr<LinkAction> SC_getAdditionalAction(const char *key, AnnotWidget *ano);
-#else
-	LinkAction* SC_getAdditionalAction(const char *key, AnnotWidget *ano);
-#endif
-	static GBool annotations_callback(Annot *annota, void *user_data);
+	static bool annotations_callback(Annot *annota, void *user_data);
 	bool handleTextAnnot(Annot* annota, double xCoor, double yCoor, double width, double height);
 	bool handleLinkAnnot(Annot* annota, double xCoor, double yCoor, double width, double height);
 	bool handleWidgetAnnot(Annot* annota, double xCoor, double yCoor, double width, double height);
@@ -176,16 +180,16 @@ public:
 	void handleActions(PageItem* ite, AnnotWidget *ano);
 	void startDoc(PDFDoc *doc, XRef *xrefA, Catalog *catA);
 
-	GBool isOk() { return gTrue; }
-	GBool upsideDown() override { return gTrue; }
-	GBool useDrawChar() override { return gTrue; }
-	GBool interpretType3Chars() override { return gTrue; }
-	GBool useTilingPatternFill() override { return gTrue; }
-	GBool useShadedFills(int type) override { return type <= 7; }
-	GBool useFillColorStop() override { return gTrue; }
-	GBool useDrawForm() override { return gFalse; }
+	bool isOk() { return true; }
+	bool upsideDown() override { return true; }
+	bool useDrawChar() override { return true; }
+	bool interpretType3Chars() override { return true; }
+	bool useTilingPatternFill() override { return true; }
+	bool useShadedFills(int type) override { return type <= 7; }
+	bool useFillColorStop() override { return true; }
+	bool useDrawForm() override { return false; }
 
-//	virtual GBool needClipToCropBox() { return gTrue; }
+//	virtual bool needClipToCropBox() { return true; }
 	void startPage(int pageNum, GfxState *, XRef *) override;
 	void endPage() override;
 
@@ -197,35 +201,31 @@ public:
 	void stroke(GfxState *state) override;
 	void fill(GfxState *state) override;
 	void eoFill(GfxState *state) override;
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(21, 3, 0)
 	bool tilingPatternFill(GfxState *state, Gfx *gfx, Catalog *cat, GfxTilingPattern *tPat, const double *mat, int x0, int y0, int x1, int y1, double xStep, double yStep) override;
-#else
-	GBool tilingPatternFill(GfxState *state, Gfx *gfx, Catalog *cat, Object *str, POPPLER_CONST_070 double *pmat, int paintType, int tilingType, Dict *resDict, POPPLER_CONST_070 double *mat, POPPLER_CONST_070 double *bbox, int x0, int y0, int x1, int y1, double xStep, double yStep) override;
-#endif
-	GBool functionShadedFill(GfxState * /*state*/, GfxFunctionShading * /*shading*/) override { qDebug() << "Function Shaded Fill";  return gFalse; }
-	GBool axialShadedFill(GfxState *state, GfxAxialShading *shading, double tMin, double tMax) override;
-	GBool axialShadedSupportExtend(GfxState *state, GfxAxialShading *shading)  override { return (shading->getExtend0() == shading->getExtend1()); }
-	GBool radialShadedFill(GfxState *state, GfxRadialShading *shading, double sMin, double sMax) override;
-	GBool radialShadedSupportExtend(GfxState *state, GfxRadialShading *shading) override { return (shading->getExtend0() == shading->getExtend1()); }
-	GBool gouraudTriangleShadedFill(GfxState *state, GfxGouraudTriangleShading *shading) override;
-	GBool patchMeshShadedFill(GfxState *state, GfxPatchMeshShading *shading) override;
+	bool functionShadedFill(GfxState * /*state*/, GfxFunctionShading * /*shading*/) override { qDebug() << "Function Shaded Fill";  return false; }
+	bool axialShadedFill(GfxState *state, GfxAxialShading *shading, double tMin, double tMax) override;
+	bool axialShadedSupportExtend(GfxState *state, GfxAxialShading *shading)  override { return (shading->getExtend0() == shading->getExtend1()); }
+	bool radialShadedFill(GfxState *state, GfxRadialShading *shading, double sMin, double sMax) override;
+	bool radialShadedSupportExtend(GfxState *state, GfxRadialShading *shading) override { return (shading->getExtend0() == shading->getExtend1()); }
+	bool gouraudTriangleShadedFill(GfxState *state, GfxGouraudTriangleShading *shading) override;
+	bool patchMeshShadedFill(GfxState *state, GfxPatchMeshShading *shading) override;
 
 	//----- path clipping
 	void clip(GfxState *state) override;
 	void eoClip(GfxState *state) override;
 	void clipToStrokePath(GfxState * /*state*/) override { qDebug() << "Clip to StrokePath"; }
-	virtual GBool deviceHasTextClip(GfxState *state) { return gFalse; }
+	virtual bool deviceHasTextClip(GfxState *state) { return false; }
 
   // If current colorspace is pattern,
   // does this device support text in pattern colorspace?
-	virtual GBool supportTextCSPattern(GfxState *state)
+	virtual bool supportTextCSPattern(GfxState *state)
 	{
 		return state->getFillColorSpace()->getMode() == csPattern;
 	}
 
   // If current colorspace is pattern,
   // need this device special handling for masks in pattern colorspace?
-	virtual GBool fillMaskCSPattern(GfxState * state)
+	virtual bool fillMaskCSPattern(GfxState * state)
 	{
 		return state->getFillColorSpace()->getMode() == csPattern;
 	}
@@ -233,37 +233,37 @@ public:
 	virtual void endMaskClip(GfxState *state) { qDebug() << "End Mask Clip"; }
 
   //----- grouping operators
-	void beginMarkedContent(POPPLER_CONST char *name, Dict *properties) override;
-	virtual void beginMarkedContent(POPPLER_CONST char *name, Object *dictRef);
+	void beginMarkedContent(const char *name, Dict *properties) override;
+	virtual void beginMarkedContent(const char *name, Object *dictRef);
 	void endMarkedContent(GfxState *state) override;
-	void markPoint(POPPLER_CONST char *name) override;
-	void markPoint(POPPLER_CONST char *name, Dict *properties) override;
+	void markPoint(const char *name) override;
+	void markPoint(const char *name, Dict *properties) override;
 
 	//----- image drawing
-	void drawImageMask(GfxState *state, Object *ref, Stream *str, int width, int height, GBool invert, GBool interpolate, GBool inlineImg) override;
-	void drawImage(GfxState *state, Object *ref, Stream *str, int width, int height, GfxImageColorMap *colorMap, GBool interpolate, POPPLER_CONST_082 int *maskColors, GBool inlineImg) override;
+	void drawImageMask(GfxState *state, Object *ref, Stream *str, int width, int height, bool invert, bool interpolate, bool inlineImg) override;
+	void drawImage(GfxState *state, Object *ref, Stream *str, int width, int height, GfxImageColorMap *colorMap, bool interpolate, const int *maskColors, bool inlineImg) override;
 	void drawSoftMaskedImage(GfxState *state, Object *ref, Stream *str,
 				   int width, int height,
 				   GfxImageColorMap *colorMap,
-				   GBool interpolate,
+				   bool interpolate,
 				   Stream *maskStr,
 				   int maskWidth, int maskHeight,
 				   GfxImageColorMap *maskColorMap,
-				   GBool maskInterpolate) override;
+				   bool maskInterpolate) override;
 
 	void drawMaskedImage(GfxState *state, Object *ref, Stream *str,
 				   int width, int height,
 				   GfxImageColorMap *colorMap,
-				   GBool interpolate,
+				   bool interpolate,
 				   Stream *maskStr,
 				   int maskWidth, int maskHeight,
-				   GBool maskInvert, GBool maskInterpolate) override; // { qDebug() << "Draw Masked Image"; }
+				   bool maskInvert, bool maskInterpolate) override; // { qDebug() << "Draw Masked Image"; }
 
 	//----- transparency groups and soft masks
-	void beginTransparencyGroup(GfxState *state, POPPLER_CONST_070 double *bbox, GfxColorSpace * /*blendingColorSpace*/, GBool /*isolated*/, GBool /*knockout*/, GBool /*forSoftMask*/) override;
-	void paintTransparencyGroup(GfxState *state, POPPLER_CONST_070 double *bbox) override;
+	void beginTransparencyGroup(GfxState *state, const double *bbox, GfxColorSpace * /*blendingColorSpace*/, bool /*isolated*/, bool /*knockout*/, bool /*forSoftMask*/) override;
+	void paintTransparencyGroup(GfxState *state, const double *bbox) override;
 	void endTransparencyGroup(GfxState *state) override;
-	void setSoftMask(GfxState * /*state*/, POPPLER_CONST_070 double * /*bbox*/, GBool /*alpha*/, Function * /*transferFunc*/, GfxColor * /*backdropColor*/) override;
+	void setSoftMask(GfxState * /*state*/, const double * /*bbox*/, bool /*alpha*/, Function * /*transferFunc*/, GfxColor * /*backdropColor*/) override;
 	void clearSoftMask(GfxState * /*state*/) override;
 
 	void updateFillColor(GfxState *state) override;
@@ -273,8 +273,8 @@ public:
 	//----- text drawing
 	void  beginTextObject(GfxState *state) override;
 	void  endTextObject(GfxState *state) override;
-	void  drawChar(GfxState *state, double /*x*/, double /*y*/, double /*dx*/, double /*dy*/, double /*originX*/, double /*originY*/, CharCode /*code*/, int /*nBytes*/, POPPLER_CONST_082 Unicode * /*u*/, int /*uLen*/) override;
-	GBool beginType3Char(GfxState * /*state*/, double /*x*/, double /*y*/, double /*dx*/, double /*dy*/, CharCode /*code*/, POPPLER_CONST_082 Unicode * /*u*/, int /*uLen*/) override;
+	void  drawChar(GfxState *state, double /*x*/, double /*y*/, double /*dx*/, double /*dy*/, double /*originX*/, double /*originY*/, CharCode /*code*/, int /*nBytes*/, const Unicode * /*u*/, int /*uLen*/) override;
+	bool  beginType3Char(GfxState * /*state*/, double /*x*/, double /*y*/, double /*dx*/, double /*dy*/, CharCode /*code*/, const Unicode * /*u*/, int /*uLen*/) override;
 	void  endType3Char(GfxState * /*state*/) override;
 	void  type3D0(GfxState * /*state*/, double /*wx*/, double /*wy*/) override;
 	void  type3D1(GfxState * /*state*/, double /*wx*/, double /*wy*/, double /*llx*/, double /*lly*/, double /*urx*/, double /*ury*/) override;
@@ -293,7 +293,7 @@ public:
 protected:
 	void setItemFillAndStroke(GfxState* state, PageItem* textNode);
 	void applyMask(PageItem* ite);
-	void pushGroup(const QString& maskName = "", GBool forSoftMask = gFalse, GBool alpha = gFalse, bool inverted = false);
+	void pushGroup(const QString& maskName = "", bool forSoftMask = false, bool alpha = false, bool inverted = false);
 
 	ScribusDoc* m_doc;
 	Qt::PenCapStyle m_lineEnd { Qt::FlatCap };
@@ -354,9 +354,9 @@ protected:
 	struct groupEntry
 	{
 		QList<PageItem*> Items;
-		GBool forSoftMask { gFalse };
-		GBool isolated { gFalse };
-		GBool alpha { gFalse };
+		bool forSoftMask { false };
+		bool isolated { false };
+		bool alpha { false };
 		QString maskName;
 		QPointF maskPos;
 		bool inverted { false };
@@ -367,11 +367,11 @@ protected:
 
 private:
 	void getPenState(GfxState *state);
-	QString getColor(GfxColorSpace *color_space, POPPLER_CONST_070 GfxColor *color, int *shade);
+	QString getColor(GfxColorSpace *color_space, const GfxColor *color, int *shade);
 	QString getAnnotationColor(const AnnotColor *color);
-	QString convertPath(POPPLER_CONST_083 GfxPath *path);
+	QString convertPath(const GfxPath *path);
 	int getBlendMode(GfxState *state) const;
-	QString UnicodeParsedString(POPPLER_CONST GooString *s1) const;
+	QString UnicodeParsedString(const GooString *s1) const;
 	QString UnicodeParsedString(const std::string& s1) const;
 	bool checkClip();
 
@@ -420,11 +420,7 @@ private:
 	Catalog *m_catalog {nullptr};
 	SplashFontEngine *m_fontEngine {nullptr};
 	SplashFont *m_font {nullptr};
-#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(21, 4, 0)
 	std::unique_ptr<FormPageWidgets> m_formWidgets;
-#else
-	FormPageWidgets *m_formWidgets {nullptr};
-#endif
 	QHash<QString, QList<int> > m_radioMap;
 	QHash<int, PageItem*> m_radioButtons;
 	int m_actPage { 1 };
