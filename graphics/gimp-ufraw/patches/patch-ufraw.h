$NetBSD: patch-ufraw.h,v 1.1 2013/08/30 22:35:32 joerg Exp $

--- ufraw.h.orig	2013-08-30 20:12:47.000000000 +0000
+++ ufraw.h
@@ -55,6 +55,10 @@ extern const char uf_auto_wb[];
  * UFObject Definitions for ufraw_settings.cc
  */
 
+#ifdef __cplusplus
+extern "C" {
+#endif // __cplusplus
+
 extern UFName ufWB;
 extern UFName ufPreset;
 extern UFName ufWBFineTuning;
@@ -78,10 +82,6 @@ extern UFName ufRawImage;
 extern UFName ufRawResources;
 extern UFName ufCommandLine;
 
-#ifdef __cplusplus
-extern "C" {
-#endif // __cplusplus
-
     UFObject *ufraw_image_new();
 #ifdef HAVE_LENSFUN
     UFObject *ufraw_lensfun_new();
