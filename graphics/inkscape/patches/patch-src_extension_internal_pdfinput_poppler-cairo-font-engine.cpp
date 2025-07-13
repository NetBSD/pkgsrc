$NetBSD: patch-src_extension_internal_pdfinput_poppler-cairo-font-engine.cpp,v 1.1 2025/07/13 08:17:38 wiz Exp $

Fix build with poppler 25.7.0
https://gitlab.com/inkscape/inkscape/-/commit/ce52c5f96106ae5747171663a46831f21aa52d95

--- src/extension/internal/pdfinput/poppler-cairo-font-engine.cpp.orig	2025-04-27 18:26:33.000000000 +0000
+++ src/extension/internal/pdfinput/poppler-cairo-font-engine.cpp
@@ -318,7 +318,11 @@ CairoFreeTypeFont *CairoFreeTypeFont::cr
 #endif
     char **enc;
     const char *name;
+#if POPPLER_CHECK_VERSION(25, 7, 0)
+    std::unique_ptr<FoFiType1C> ff1c;
+#else
     FoFiType1C *ff1c;
+#endif
     std::optional<FreeTypeFontFace> font_face;
     std::vector<int> codeToGID;
     bool substitute = false;
@@ -429,7 +433,7 @@ CairoFreeTypeFont *CairoFreeTypeFont::cr
                 FoFiTrueType *ff;
 #endif
                 if (!font_data.empty()) {
-                    ff = FoFiTrueType::make((fontchar)font_data.data(), font_data.size(), 0);
+                    ff = _POPPLER_FOFI_TRUETYPE_MAKE(font_data, 0);
                 } else {
                     ff = FoFiTrueType::load(fileName.c_str(), 0);
                 }
@@ -459,7 +463,7 @@ CairoFreeTypeFont *CairoFreeTypeFont::cr
             FoFiTrueType *ff;
 #endif
             if (!font_data.empty()) {
-                ff = FoFiTrueType::make((fontchar)font_data.data(), font_data.size(), 0);
+                ff = _POPPLER_FOFI_TRUETYPE_MAKE(font_data, 0);
             } else {
                 ff = FoFiTrueType::load(fileName.c_str(), 0);
             }
@@ -493,7 +497,7 @@ CairoFreeTypeFont *CairoFreeTypeFont::cr
         case fontCIDType0C:
             if (!useCIDs) {
                 if (!font_data.empty()) {
-                    ff1c = FoFiType1C::make((fontchar)font_data.data(), font_data.size());
+                    ff1c = _POPPLER_FOFI_TYPE1C_MAKE(font_data);
                 } else {
                     ff1c = FoFiType1C::load(fileName.c_str());
                 }
@@ -506,7 +510,9 @@ CairoFreeTypeFont *CairoFreeTypeFont::cr
                     codeToGID.insert(codeToGID.begin(), src, src + n);
                     gfree(src);
 #endif
+#if !(POPPLER_CHECK_VERSION(25, 7, 0))
                     delete ff1c;
+#endif
                 }
             }
 
@@ -542,13 +548,13 @@ CairoFreeTypeFont *CairoFreeTypeFont::cr
                     FoFiTrueType *ff;
 #endif
                     if (!font_data.empty()) {
-                        ff = FoFiTrueType::make((fontchar)font_data.data(), font_data.size(), 0);
+                        ff = _POPPLER_FOFI_TRUETYPE_MAKE(font_data, 0);
                     } else {
                         ff = FoFiTrueType::load(fileName.c_str(), 0);
                     }
                     if (ff) {
                         if (ff->isOpenTypeCFF()) {
-                            auto src = ff1c->_POPPLER_GET_CID_TO_GID_MAP(&n);
+                            auto src = ff->_POPPLER_GET_CID_TO_GID_MAP(&n);
 #if POPPLER_CHECK_VERSION(25,2,0)
                             codeToGID = std::move(src);
 #else
