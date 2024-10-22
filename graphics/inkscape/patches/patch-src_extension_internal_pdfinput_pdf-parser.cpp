$NetBSD: patch-src_extension_internal_pdfinput_pdf-parser.cpp,v 1.21 2024/10/22 09:00:10 wiz Exp $

Fix build with poppler 24.10.0.
https://github.com/OpenMandrivaAssociation/inkscape/blob/master/inkscape-1.4-poppler-24.10.patch

--- src/extension/internal/pdfinput/pdf-parser.cpp.orig	2024-07-28 11:27:55.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-parser.cpp
@@ -810,7 +810,7 @@ void PdfParser::opSetExtGState(Object ar
             _POPPLER_FREE(obj3);
             if (_POPPLER_CALL_ARGS_DEREF(obj3, obj2.dictLookup, "G").isStream()) {
                 if (_POPPLER_CALL_ARGS_DEREF(obj4, obj3.streamGetDict()->lookup, "Group").isDict()) {
-                    GfxColorSpace *blendingColorSpace = nullptr;
+                    std::unique_ptr<GfxColorSpace> blendingColorSpace = nullptr;
                     GBool isolated = gFalse;
                     GBool knockout = gFalse;
                     if (!_POPPLER_CALL_ARGS_DEREF(obj5, obj4.dictLookup, "CS").isNull()) {
@@ -857,7 +857,7 @@ void PdfParser::opSetExtGState(Object ar
 }
 
 void PdfParser::doSoftMask(Object *str, GBool alpha,
-		     GfxColorSpace *blendingColorSpace,
+		     std::unique_ptr<GfxColorSpace> const &blendingColorSpace,
 		     GBool isolated, GBool knockout,
 		     Function *transferFunc, GfxColor *backdropColor) {
   Dict *dict, *resDict;
@@ -920,9 +920,9 @@ void PdfParser::doSoftMask(Object *str, 
 	  alpha, transferFunc, backdropColor);
   --formDepth;
 
-  if (blendingColorSpace) {
-    delete blendingColorSpace;
-  }
+//  if (blendingColorSpace) {
+//    delete blendingColorSpace;
+//  }
   _POPPLER_FREE(obj1);
 }
 
@@ -936,41 +936,28 @@ void PdfParser::opSetRenderingIntent(Obj
 
 /**
  * Get a newly allocated color space instance by CS operation argument.
- *
- * Maintains a cache for named color spaces to avoid expensive re-parsing.
  */
-GfxColorSpace *PdfParser::lookupColorSpaceCopy(Object &arg)
+std::unique_ptr<GfxColorSpace> PdfParser::lookupColorSpaceCopy(Object &arg)
 {
     assert(!arg.isNull());
-    GfxColorSpace *colorSpace = nullptr;
 
     if (char const *name = arg.isName() ? arg.getName() : nullptr) {
-        auto const cache_name = std::to_string(formDepth) + "-" + name;
-        if ((colorSpace = colorSpacesCache[cache_name].get())) {
-            return colorSpace->copy();
-        }
-
         Object obj = res->lookupColorSpace(name);
         if (obj.isNull()) {
-            colorSpace = GfxColorSpace::parse(res, &arg, nullptr, state);
+            return GfxColorSpace::parse(res, &arg, nullptr, state);
         } else {
-            colorSpace = GfxColorSpace::parse(res, &obj, nullptr, state);
-        }
-
-        if (colorSpace && colorSpace->getMode() != csPattern) {
-            colorSpacesCache[cache_name].reset(colorSpace->copy());
+            return GfxColorSpace::parse(res, &obj, nullptr, state);
         }
     } else {
         // We were passed in an object directly.
-        colorSpace = GfxColorSpace::parse(res, &arg, nullptr, state);
+        return GfxColorSpace::parse(res, &arg, nullptr, state);
     }
-    return colorSpace;
 }
 
 /**
  * Look up pattern/gradients from the GfxResource dictionary
  */
-GfxPattern *PdfParser::lookupPattern(Object *obj, GfxState *state)
+std::unique_ptr<GfxPattern> PdfParser::lookupPattern(Object *obj, GfxState *state)
 {
     if (!obj->isName())
         return nullptr;
@@ -983,7 +970,7 @@ void PdfParser::opSetFillGray(Object arg
   GfxColor color;
   builder->beforeStateChange(state);
   state->setFillPattern(nullptr);
-  state->setFillColorSpace(new GfxDeviceGrayColorSpace());
+  state->setFillColorSpace(std::unique_ptr<GfxColorSpace>(new GfxDeviceGrayColorSpace()));
   color.c[0] = dblToCol(args[0].getNum());
   state->setFillColor(&color);
   builder->updateStyle(state);
@@ -995,7 +982,7 @@ void PdfParser::opSetStrokeGray(Object a
   GfxColor color;
   builder->beforeStateChange(state);
   state->setStrokePattern(nullptr);
-  state->setStrokeColorSpace(new GfxDeviceGrayColorSpace());
+  state->setStrokeColorSpace(std::unique_ptr<GfxColorSpace>(new GfxDeviceGrayColorSpace()));
   color.c[0] = dblToCol(args[0].getNum());
   state->setStrokeColor(&color);
   builder->updateStyle(state);
@@ -1008,7 +995,7 @@ void PdfParser::opSetFillCMYKColor(Objec
   int i;
   builder->beforeStateChange(state);
   state->setFillPattern(nullptr);
-  state->setFillColorSpace(new GfxDeviceCMYKColorSpace());
+  state->setFillColorSpace(std::unique_ptr<GfxColorSpace>(new GfxDeviceCMYKColorSpace()));
   for (i = 0; i < 4; ++i) {
     color.c[i] = dblToCol(args[i].getNum());
   }
@@ -1022,7 +1009,7 @@ void PdfParser::opSetStrokeCMYKColor(Obj
   GfxColor color;
   builder->beforeStateChange(state);
   state->setStrokePattern(nullptr);
-  state->setStrokeColorSpace(new GfxDeviceCMYKColorSpace());
+  state->setStrokeColorSpace(std::unique_ptr<GfxColorSpace>(new GfxDeviceCMYKColorSpace()));
   for (int i = 0; i < 4; ++i) {
     color.c[i] = dblToCol(args[i].getNum());
   }
@@ -1036,7 +1023,7 @@ void PdfParser::opSetFillRGBColor(Object
   GfxColor color;
   builder->beforeStateChange(state);
   state->setFillPattern(nullptr);
-  state->setFillColorSpace(new GfxDeviceRGBColorSpace());
+  state->setFillColorSpace(std::unique_ptr<GfxColorSpace>(new GfxDeviceRGBColorSpace()));
   for (int i = 0; i < 3; ++i) {
     color.c[i] = dblToCol(args[i].getNum());
   }
@@ -1049,7 +1036,7 @@ void PdfParser::opSetStrokeRGBColor(Obje
   GfxColor color;
   builder->beforeStateChange(state);
   state->setStrokePattern(nullptr);
-  state->setStrokeColorSpace(new GfxDeviceRGBColorSpace());
+  state->setStrokeColorSpace(std::unique_ptr<GfxColorSpace>(new GfxDeviceRGBColorSpace()));
   for (int i = 0; i < 3; ++i) {
     color.c[i] = dblToCol(args[i].getNum());
   }
@@ -1061,13 +1048,13 @@ void PdfParser::opSetStrokeRGBColor(Obje
 void PdfParser::opSetFillColorSpace(Object args[], int numArgs)
 {
   assert(numArgs >= 1);
-  GfxColorSpace *colorSpace = lookupColorSpaceCopy(args[0]);
+  std::unique_ptr<GfxColorSpace> colorSpace = lookupColorSpaceCopy(args[0]);
   builder->beforeStateChange(state);
   state->setFillPattern(nullptr);
 
   if (colorSpace) {
     GfxColor color;
-    state->setFillColorSpace(colorSpace);
+    state->setFillColorSpace(colorSpace->copy());
     colorSpace->getDefaultColor(&color);
     state->setFillColor(&color);
     builder->updateStyle(state);
@@ -1082,13 +1069,13 @@ void PdfParser::opSetStrokeColorSpace(Ob
   assert(numArgs >= 1);
   builder->beforeStateChange(state);
 
-  GfxColorSpace *colorSpace = lookupColorSpaceCopy(args[0]);
+  std::unique_ptr<GfxColorSpace> colorSpace = lookupColorSpaceCopy(args[0]);
 
   state->setStrokePattern(nullptr);
 
   if (colorSpace) {
     GfxColor color;
-    state->setStrokeColorSpace(colorSpace);
+    state->setStrokeColorSpace(colorSpace->copy());
     colorSpace->getDefaultColor(&color);
     state->setStrokeColor(&color);
     builder->updateStyle(state);
@@ -1152,7 +1139,7 @@ void PdfParser::opSetFillColorN(Object a
       builder->updateStyle(state);
     }
     if (auto pattern = lookupPattern(&(args[numArgs - 1]), state)) {
-        state->setFillPattern(pattern);
+        state->setFillPattern(pattern->copy());
         builder->updateStyle(state);
     }
 
@@ -1195,7 +1182,7 @@ void PdfParser::opSetStrokeColorN(Object
       builder->updateStyle(state);
     }
     if (auto pattern = lookupPattern(&(args[numArgs - 1]), state)) {
-        state->setStrokePattern(pattern);
+        state->setStrokePattern(pattern->copy());
         builder->updateStyle(state);
     }
 
@@ -1572,7 +1559,7 @@ void PdfParser::doShadingPatternFillFall
 // TODO not good that numArgs is ignored but args[] is used:
 void PdfParser::opShFill(Object args[], int /*numArgs*/)
 {
-  GfxShading *shading = nullptr;
+  std::unique_ptr<GfxShading> shading = nullptr;
   GfxPath *savedPath = nullptr;
   bool savedState = false;
 
@@ -1608,19 +1595,19 @@ void PdfParser::opShFill(Object args[], 
   // do shading type-specific operations
   switch (shading->getType()) {
   case 1: // Function-based shading
-    doFunctionShFill(static_cast<GfxFunctionShading *>(shading));
+    doFunctionShFill(static_cast<GfxFunctionShading *>(shading.get()));
     break;
   case 2: // Axial shading
   case 3: // Radial shading
-      builder->addClippedFill(shading, stateToAffine(state));
+      builder->addClippedFill(shading.get(), stateToAffine(state));
       break;
   case 4: // Free-form Gouraud-shaded triangle mesh
   case 5: // Lattice-form Gouraud-shaded triangle mesh
-    doGouraudTriangleShFill(static_cast<GfxGouraudTriangleShading *>(shading));
+    doGouraudTriangleShFill(static_cast<GfxGouraudTriangleShading *>(shading.get()));
     break;
   case 6: // Coons patch mesh
   case 7: // Tensor-product patch mesh
-    doPatchMeshShFill(static_cast<GfxPatchMeshShading *>(shading));
+    doPatchMeshShFill(static_cast<GfxPatchMeshShading *>(shading.get()));
     break;
   }
 
@@ -1630,7 +1617,6 @@ void PdfParser::opShFill(Object args[], 
     state->setPath(savedPath);
   }
 
-  delete shading;
 }
 
 void PdfParser::doFunctionShFill(GfxFunctionShading *shading) {
@@ -2521,7 +2507,7 @@ void PdfParser::doImage(Object * /*ref*/
         
     } else {
         // get color space and color map
-        GfxColorSpace *colorSpace;
+        std::unique_ptr<GfxColorSpace> colorSpace;
         _POPPLER_CALL_ARGS(obj1, dict->lookup, "ColorSpace");
         if (obj1.isNull()) {
             _POPPLER_FREE(obj1);
@@ -2530,11 +2516,11 @@ void PdfParser::doImage(Object * /*ref*/
         if (!obj1.isNull()) {
             colorSpace = lookupColorSpaceCopy(obj1);
         } else if (csMode == streamCSDeviceGray) {
-            colorSpace = new GfxDeviceGrayColorSpace();
+            colorSpace = std::unique_ptr<GfxColorSpace>(new GfxDeviceGrayColorSpace());
         } else if (csMode == streamCSDeviceRGB) {
-            colorSpace = new GfxDeviceRGBColorSpace();
+            colorSpace = std::unique_ptr<GfxColorSpace>(new GfxDeviceRGBColorSpace());
         } else if (csMode == streamCSDeviceCMYK) {
-            colorSpace = new GfxDeviceCMYKColorSpace();
+            colorSpace = std::unique_ptr<GfxColorSpace>(new GfxDeviceCMYKColorSpace());
         } else {
             colorSpace = nullptr;
         }
@@ -2547,7 +2533,7 @@ void PdfParser::doImage(Object * /*ref*/
             _POPPLER_FREE(obj1);
             _POPPLER_CALL_ARGS(obj1, dict->lookup, "D");
         }
-        GfxImageColorMap *colorMap = new GfxImageColorMap(bits, &obj1, colorSpace);
+        GfxImageColorMap *colorMap = new GfxImageColorMap(bits, &obj1, colorSpace->copy());
         _POPPLER_FREE(obj1);
         if (!colorMap->isOk()) {
             delete colorMap;
@@ -2617,7 +2603,7 @@ void PdfParser::doImage(Object * /*ref*/
 	            _POPPLER_FREE(obj1);
                     _POPPLER_CALL_ARGS(obj1, maskDict->lookup, "CS");
             }
-            GfxColorSpace *maskColorSpace = lookupColorSpaceCopy(obj1);
+            std::unique_ptr<GfxColorSpace> maskColorSpace = lookupColorSpaceCopy(obj1);
             _POPPLER_FREE(obj1);
             if (!maskColorSpace || maskColorSpace->getMode() != csDeviceGray) {
                 goto err1;
@@ -2627,7 +2613,7 @@ void PdfParser::doImage(Object * /*ref*/
                 _POPPLER_FREE(obj1);
                 _POPPLER_CALL_ARGS(obj1, maskDict->lookup, "D");
             }
-            maskColorMap = new GfxImageColorMap(maskBits, &obj1, maskColorSpace);
+            maskColorMap = new GfxImageColorMap(maskBits, &obj1, maskColorSpace->copy());
             _POPPLER_FREE(obj1);
             if (!maskColorMap->isOk()) {
                 delete maskColorMap;
@@ -2739,7 +2725,7 @@ void PdfParser::doForm(Object *str, doub
 {
     Dict *dict;
     GBool transpGroup, isolated, knockout;
-    GfxColorSpace *blendingColorSpace;
+    std::unique_ptr<GfxColorSpace> blendingColorSpace;
     Object matrixObj, bboxObj;
     double m[6], bbox[4];
     Object resObj;
@@ -2831,14 +2817,11 @@ void PdfParser::doForm(Object *str, doub
     doForm1(str, resDict, m, bbox, transpGroup, gFalse, blendingColorSpace, isolated, knockout);
     --formDepth;
 
-    if (blendingColorSpace) {
-        delete blendingColorSpace;
-    }
     _POPPLER_FREE(resObj);
 }
 
 void PdfParser::doForm1(Object *str, Dict *resDict, double *matrix, double *bbox, GBool transpGroup, GBool softMask,
-                        GfxColorSpace *blendingColorSpace, GBool isolated, GBool knockout, GBool alpha,
+                        std::unique_ptr<GfxColorSpace> const &blendingColorSpace, GBool isolated, GBool knockout, GBool alpha,
                         Function *transferFunc, GfxColor *backdropColor)
 {
     Parser *oldParser;
@@ -2847,7 +2830,7 @@ void PdfParser::doForm1(Object *str, Dic
     pushResources(resDict);
 
     // Add a new container group before saving the state
-    builder->startGroup(state, bbox, blendingColorSpace, isolated, knockout, softMask);
+    builder->startGroup(state, bbox, blendingColorSpace.get(), isolated, knockout, softMask);
 
     // save current graphics state
     saveState();
