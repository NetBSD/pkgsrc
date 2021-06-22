$NetBSD: patch-scribus_plugins_import_pdf_slaoutput.h,v 1.1 2021/06/22 21:24:15 markd Exp $

fixes for poppler >=21.3

--- scribus/plugins/import/pdf/slaoutput.h.orig	2020-06-11 09:56:15.000000000 +0000
+++ scribus/plugins/import/pdf/slaoutput.h
@@ -195,7 +195,11 @@ public:
 	void stroke(GfxState *state) override;
 	void fill(GfxState *state) override;
 	void eoFill(GfxState *state) override;
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(21, 3, 0)
+	bool tilingPatternFill(GfxState *state, Gfx *gfx, Catalog *cat, GfxTilingPattern *tPat, const double *mat, int x0, int y0, int x1, int y1, double xStep, double yStep) override;
+#else
 	GBool tilingPatternFill(GfxState *state, Gfx *gfx, Catalog *cat, Object *str, POPPLER_CONST_070 double *pmat, int paintType, int tilingType, Dict *resDict, POPPLER_CONST_070 double *mat, POPPLER_CONST_070 double *bbox, int x0, int y0, int x1, int y1, double xStep, double yStep) override;
+#endif
 	GBool functionShadedFill(GfxState * /*state*/, GfxFunctionShading * /*shading*/) override { qDebug() << "Function Shaded Fill";  return gFalse; }
 	GBool axialShadedFill(GfxState *state, GfxAxialShading *shading, double tMin, double tMax) override;
 	GBool axialShadedSupportExtend(GfxState *state, GfxAxialShading *shading)  override { return (shading->getExtend0() == shading->getExtend1()); }
@@ -367,7 +371,11 @@ private:
 	Catalog *catalog {nullptr};
 	SplashFontEngine *m_fontEngine {nullptr};
 	SplashFont *m_font {nullptr};
+#if POPPLER_ENCODED_VERSION >= POPPLER_VERSION_ENCODE(21, 4, 0)
+	std::unique_ptr<FormPageWidgets> m_formWidgets;
+#else
 	FormPageWidgets *m_formWidgets {nullptr};
+#endif
 	QHash<QString, QList<int> > m_radioMap;
 	QHash<int, PageItem*> m_radioButtons;
 	int m_actPage;
