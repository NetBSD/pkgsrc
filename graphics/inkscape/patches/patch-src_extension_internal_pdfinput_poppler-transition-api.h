$NetBSD: patch-src_extension_internal_pdfinput_poppler-transition-api.h,v 1.7 2025/07/13 08:17:38 wiz Exp $

Fix build with poppler 25.7.0
https://gitlab.com/inkscape/inkscape/-/commit/ce52c5f96106ae5747171663a46831f21aa52d95

--- src/extension/internal/pdfinput/poppler-transition-api.h.orig	2025-04-07 17:25:33.000000000 +0000
+++ src/extension/internal/pdfinput/poppler-transition-api.h
@@ -15,6 +15,32 @@
 #include <glib/poppler-features.h>
 #include <poppler/UTF.h>
 
+#if POPPLER_CHECK_VERSION(25, 7, 0)
+#define _POPPLER_TEXT_SHIFT_WITH_USER_COORDS(dx, dy) textShiftWithUserCoords(dx, dy)
+#define _POPPLER_FOFI_TRUETYPE_MAKE(font_data, faceIndex) FoFiTrueType::make(std::span(font_data), faceIndex)
+#define _POPPLER_FOFI_TYPE1C_MAKE(font_data) FoFiType1C::make(std::span(font_data))
+#define _POPPLER_GET_CUR_TEXT_X() getCurTextX()
+#define _POPPLER_GET_CUR_TEXT_Y() getCurTextY()
+#else
+#define _POPPLER_TEXT_SHIFT_WITH_USER_COORDS(dx, dy) shift(dx, dy)
+#define _POPPLER_FOFI_TRUETYPE_MAKE(font_data, faceIndex) FoFiTrueType::make((fontchar)font_data.data(), font_data.size(), faceIndex)
+#define _POPPLER_FOFI_TYPE1C_MAKE(font_data) FoFiType1C::make((fontchar)font_data.data(), font_data.size())
+#define _POPPLER_GET_CUR_TEXT_X() getCurX()
+#define _POPPLER_GET_CUR_TEXT_Y() getCurY()
+#endif
+
+#if POPPLER_CHECK_VERSION(25, 6, 0)
+#define _POPPLER_DECLARE_TRANSFER_FUNCTION_VECTOR(name) std::vector<std::unique_ptr<Function>> name(4)
+#define _POPPLER_DELETE_TRANSFER_FUNCTION(name) name.reset()
+#define _POPPLER_GET_TRANSFER_FUNCTION_POINTER(name) name.get()
+#else
+#define _POPPLER_DECLARE_TRANSFER_FUNCTION_VECTOR(name) Function *name[4] = {}
+#define _POPPLER_DELETE_TRANSFER_FUNCTION(name) \
+    delete name;                                \
+    name = nullptr
+#define _POPPLER_GET_TRANSFER_FUNCTION_POINTER(name) name
+#endif
+
 #if POPPLER_CHECK_VERSION(25,2,0)
 #define _POPPLER_GET_CODE_TO_GID_MAP(ff, len) getCodeToGIDMap(ff)
 #define _POPPLER_GET_CID_TO_GID_MAP(len) getCIDToGIDMap()
