$NetBSD: patch-src_gui_sdlmain.cpp,v 1.1 2017/02/07 23:56:14 joerg Exp $

Pointers are not ordered with 0. Fix format string.

--- src/gui/sdlmain.cpp.orig	2017-01-08 18:35:26.455430930 +0000
+++ src/gui/sdlmain.cpp
@@ -1134,8 +1134,8 @@ static void GUI_StartUp(Section * sec) {
 #endif
 	const char * gl_ext = (const char *)glGetString (GL_EXTENSIONS);
 	if(gl_ext && *gl_ext){
-		sdl.opengl.packed_pixel=(strstr(gl_ext,"EXT_packed_pixels") > 0);
-		sdl.opengl.paletted_texture=(strstr(gl_ext,"EXT_paletted_texture") > 0);
+		sdl.opengl.packed_pixel=(strstr(gl_ext,"EXT_packed_pixels") != NULL);
+		sdl.opengl.paletted_texture=(strstr(gl_ext,"EXT_paletted_texture") != NULL);
 #if defined(NVIDIA_PixelDataRange)
 		sdl.opengl.pixel_data_range=(strstr(gl_ext,"GL_NV_pixel_data_range") >0 ) &&
 			glPixelDataRangeNV && db_glAllocateMemoryNV && db_glFreeMemoryNV;
@@ -1529,7 +1529,7 @@ static void show_warning(char const * co
 	if ( !sdl.inited && SDL_Init(SDL_INIT_VIDEO|SDL_INIT_NOPARACHUTE) < 0 ) textonly = true;
 	sdl.inited = true;
 #endif
-	printf(message);
+	printf("%s", message);
 	if(textonly) return;
 	if(!sdl.surface) sdl.surface = SDL_SetVideoMode(640,400,0,0);
 	if(!sdl.surface) return;
