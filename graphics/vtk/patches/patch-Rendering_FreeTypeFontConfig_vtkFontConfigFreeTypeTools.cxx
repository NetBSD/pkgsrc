$NetBSD: patch-Rendering_FreeTypeFontConfig_vtkFontConfigFreeTypeTools.cxx,v 1.1 2021/05/04 14:48:34 prlw1 Exp $

Nice explanation here:
https://bugs.ghostscript.com/show_bug.cgi?id=702985

--- Rendering/FreeTypeFontConfig/vtkFontConfigFreeTypeTools.cxx.orig	2020-06-26 13:24:40.000000000 +0000
+++ Rendering/FreeTypeFontConfig/vtkFontConfigFreeTypeTools.cxx
@@ -29,7 +29,7 @@ vtkStandardNewMacro(vtkFontConfigFreeTyp
 namespace
 {
 // The FreeType face requester callback:
-FT_CALLBACK_DEF(FT_Error)
+extern "C" FT_Error
 vtkFontConfigFreeTypeToolsFaceRequester(
   FTC_FaceID face_id, FT_Library lib, FT_Pointer request_data, FT_Face* face)
 {
