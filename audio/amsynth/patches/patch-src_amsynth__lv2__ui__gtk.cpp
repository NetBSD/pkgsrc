$NetBSD: patch-src_amsynth__lv2__ui__gtk.cpp,v 1.1 2020/05/22 01:13:19 joerg Exp $

--- src/amsynth_lv2_ui_gtk.cpp.orig	2020-05-21 20:27:29.952873260 +0000
+++ src/amsynth_lv2_ui_gtk.cpp
@@ -139,7 +139,7 @@ struct SynthesizerStub : ISynthesizer
 ////////////////////////////////////////////////////////////////////////////////
 
 static LV2UI_Handle
-lv2_ui_instantiate(const struct _LV2UI_Descriptor* descriptor,
+lv2_ui_instantiate(const struct LV2UI_Descriptor* descriptor,
 				   const char*                     plugin_uri,
 				   const char*                     bundle_path,
 				   LV2UI_Write_Function            write_function,
