$NetBSD: patch-src_extension_internal_pdfinput_pdf-parser.h,v 1.8 2024/10/22 09:00:11 wiz Exp $

Fix build with poppler 24.10.0.
https://github.com/OpenMandrivaAssociation/inkscape/blob/master/inkscape-1.4-poppler-24.10.patch

--- src/extension/internal/pdfinput/pdf-parser.h.orig	2024-04-22 21:00:30.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-parser.h
@@ -138,7 +138,7 @@ public:
     void loadPatternColorProfiles(Dict *resources);
     void loadColorProfile();
     void loadColorSpaceProfile(GfxColorSpace *space, Object *obj);
-    GfxPattern *lookupPattern(Object *obj, GfxState *state);
+    std::unique_ptr<GfxPattern> lookupPattern(Object *obj, GfxState *state);
 
     std::shared_ptr<CairoFontEngine> getFontEngine();
 
@@ -174,10 +174,7 @@ private:
 
     OpHistoryEntry *operatorHistory; // list containing the last N operators
 
-    //! Caches color spaces by name
-    std::map<std::string, std::unique_ptr<GfxColorSpace>> colorSpacesCache;
-
-    GfxColorSpace *lookupColorSpaceCopy(Object &);
+    std::unique_ptr<GfxColorSpace> lookupColorSpaceCopy(Object &);
 
     void setDefaultApproximationPrecision(); // init color deltas
     void pushOperator(const char *name);
@@ -203,7 +200,7 @@ private:
     void opSetMiterLimit(Object args[], int numArgs);
     void opSetLineWidth(Object args[], int numArgs);
     void opSetExtGState(Object args[], int numArgs);
-    void doSoftMask(Object *str, GBool alpha, GfxColorSpace *blendingColorSpace, GBool isolated, GBool knockout,
+    void doSoftMask(Object *str, GBool alpha, std::unique_ptr<GfxColorSpace> const &blendingColorSpace, GBool isolated, GBool knockout,
                     Function *transferFunc, GfxColor *backdropColor);
     void opSetRenderingIntent(Object args[], int numArgs);
 
@@ -297,7 +294,7 @@ private:
   void doForm(Object *str, double *offset = nullptr);
   void doForm1(Object *str, Dict *resDict, double *matrix, double *bbox,
 	       GBool transpGroup = gFalse, GBool softMask = gFalse,
-	       GfxColorSpace *blendingColorSpace = nullptr,
+	       std::unique_ptr<GfxColorSpace> const &blendingColorSpace = nullptr,
 	       GBool isolated = gFalse, GBool knockout = gFalse,
 	       GBool alpha = gFalse, Function *transferFunc = nullptr,
 	       GfxColor *backdropColor = nullptr);
