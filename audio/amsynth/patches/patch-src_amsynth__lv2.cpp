$NetBSD: patch-src_amsynth__lv2.cpp,v 1.1 2020/05/22 01:13:19 joerg Exp $

--- src/amsynth_lv2.cpp.orig	2020-05-21 20:30:13.156423602 +0000
+++ src/amsynth_lv2.cpp
@@ -80,7 +80,7 @@ struct amsynth_wrapper {
 };
 
 static LV2_Handle
-lv2_instantiate(const struct _LV2_Descriptor *descriptor, double sample_rate, const char *bundle_path, const LV2_Feature *const *features)
+lv2_instantiate(const struct LV2_Descriptor *descriptor, double sample_rate, const char *bundle_path, const LV2_Feature *const *features)
 {
 	LOG_FUNCTION_CALL();
 
