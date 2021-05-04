$NetBSD: patch-Rendering_FreeType_vtkFreeTypeTools.cxx,v 1.1 2021/05/04 14:48:34 prlw1 Exp $

Nice explanation here:
https://bugs.ghostscript.com/show_bug.cgi?id=702985

--- Rendering/FreeType/vtkFreeTypeTools.cxx.orig	2020-06-26 13:24:40.000000000 +0000
+++ Rendering/FreeType/vtkFreeTypeTools.cxx
@@ -378,7 +378,7 @@ FTC_CMapCache* vtkFreeTypeTools::GetCMap
 }
 
 //----------------------------------------------------------------------------
-FT_CALLBACK_DEF(FT_Error)
+extern "C" FT_Error
 vtkFreeTypeToolsFaceRequester(
   FTC_FaceID face_id, FT_Library lib, FT_Pointer request_data, FT_Face* face)
 {
