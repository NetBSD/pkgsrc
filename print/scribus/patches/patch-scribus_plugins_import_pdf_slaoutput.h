$NetBSD: patch-scribus_plugins_import_pdf_slaoutput.h,v 1.1 2025/11/10 13:54:53 wiz Exp $

Sync with git head as of 2025-11-10 to fix build problems with qt, poppler, podofo.

--- scribus/plugins/import/pdf/slaoutput.h.orig	2025-01-25 21:57:14.000000000 +0000
+++ scribus/plugins/import/pdf/slaoutput.h
@@ -20,6 +20,7 @@ for which a new license (GPL+exception) 
 #include <QTextStream>
 #include <QTransform>
 
+#include <array>
 #include <memory>
 
 #include "fpointarray.h"
@@ -164,7 +165,7 @@ public:
 	SlaOutputDev(ScribusDoc* doc, QList<PageItem*> *Elements, QStringList *importedColors, int flags);
 	~SlaOutputDev() override;
 
-	LinkAction* SC_getAction(AnnotWidget *ano);
+	std::unique_ptr<LinkAction> SC_getAction(AnnotWidget *ano);
 	std::unique_ptr<LinkAction> SC_getAdditionalAction(const char *key, AnnotWidget *ano);
 	static bool annotations_callback(Annot *annota, void *user_data);
 	bool handleTextAnnot(Annot* annota, double xCoor, double yCoor, double width, double height);
@@ -195,7 +196,12 @@ public:
 	void stroke(GfxState *state) override;
 	void fill(GfxState *state) override;
 	void eoFill(GfxState *state) override;
+
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 9, 0)
+	bool tilingPatternFill(GfxState *state, Gfx *gfx, Catalog *cat, GfxTilingPattern *tPat, const std::array<double, 6>& mat, int x0, int y0, int x1, int y1, double xStep, double yStep) override;
+#else
 	bool tilingPatternFill(GfxState *state, Gfx *gfx, Catalog *cat, GfxTilingPattern *tPat, const double *mat, int x0, int y0, int x1, int y1, double xStep, double yStep) override;
+#endif
 	bool functionShadedFill(GfxState * /*state*/, GfxFunctionShading * /*shading*/) override { qDebug() << "Function Shaded Fill";  return false; }
 	bool axialShadedFill(GfxState *state, GfxAxialShading *shading, double tMin, double tMax) override;
 	bool axialShadedSupportExtend(GfxState *state, GfxAxialShading *shading)  override { return (shading->getExtend0() == shading->getExtend1()); }
@@ -254,10 +260,20 @@ public:
 				   bool maskInvert, bool maskInterpolate) override;
 
 	//----- transparency groups and soft masks
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 9, 0)
+	void beginTransparencyGroup(GfxState *state, const std::array<double, 4>& bbox, GfxColorSpace* /*blendingColorSpace*/, bool /*isolated*/, bool /*knockout*/, bool /*forSoftMask*/) override;
+	void paintTransparencyGroup(GfxState *state, const std::array<double, 4>& bbox) override;
+#else
 	void beginTransparencyGroup(GfxState *state, const double *bbox, GfxColorSpace * /*blendingColorSpace*/, bool /*isolated*/, bool /*knockout*/, bool /*forSoftMask*/) override;
 	void paintTransparencyGroup(GfxState *state, const double *bbox) override;
+#endif
 	void endTransparencyGroup(GfxState *state) override;
+
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(25, 9, 0)
+	void setSoftMask(GfxState * /*state*/, const std::array<double, 4> & /*bbox*/, bool /*alpha*/, Function * /*transferFunc*/, GfxColor * /*backdropColor*/) override;
+#else
 	void setSoftMask(GfxState * /*state*/, const double * /*bbox*/, bool /*alpha*/, Function * /*transferFunc*/, GfxColor * /*backdropColor*/) override;
+#endif
 	void clearSoftMask(GfxState * /*state*/) override;
 
 	void updateFillColor(GfxState *state) override;
@@ -394,7 +410,7 @@ private:
 	QTransform m_ctm;
 	struct F3Entry
 	{
-		bool colored;
+		bool colored = false;
 	};
 	QStack<F3Entry> m_F3Stack;
 	struct mContent
