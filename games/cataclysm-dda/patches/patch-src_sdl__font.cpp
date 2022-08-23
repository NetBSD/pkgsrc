$NetBSD: patch-src_sdl__font.cpp,v 1.1 2022/08/23 10:41:34 wiz Exp $

Fix build with SDL2_ttf-2.20.

--- src/sdl_font.cpp.orig	2021-08-31 13:23:05.000000000 +0000
+++ src/sdl_font.cpp
@@ -22,12 +22,12 @@ static int test_face_size( const std::st
 {
     const TTF_Font_Ptr fnt( TTF_OpenFontIndex( f.c_str(), size, faceIndex ) );
     if( fnt ) {
-        char *style = TTF_FontFaceStyleName( fnt.get() );
+        const char *style = TTF_FontFaceStyleName( fnt.get() );
         if( style != nullptr ) {
             int faces = TTF_FontFaces( fnt.get() );
             for( int i = faces - 1; i >= 0; i-- ) {
                 const TTF_Font_Ptr tf( TTF_OpenFontIndex( f.c_str(), size, i ) );
-                char *ts = nullptr;
+                const char *ts = nullptr;
                 if( tf ) {
                     if( nullptr != ( ts = TTF_FontFaceStyleName( tf.get() ) ) ) {
                         if( 0 == strcasecmp( ts, style ) && TTF_FontHeight( tf.get() ) <= size ) {
