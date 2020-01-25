$NetBSD: patch-neo_renderer_Image__init.cpp,v 1.1 2020/01/25 14:38:51 jmcneill Exp $

Use the _alloca define from neo/sys/platform.h

--- neo/renderer/Image_init.cpp.orig	2018-12-15 04:49:59.000000000 +0000
+++ neo/renderer/Image_init.cpp
@@ -1197,7 +1197,7 @@ void R_ListImages_f( const idCmdArgs &ar
 
 	totalSize = 0;
 
-	sortedImage_t	*sortedArray = (sortedImage_t *)alloca( sizeof( sortedImage_t ) * globalImages->images.Num() );
+	sortedImage_t	*sortedArray = (sortedImage_t *)_alloca( sizeof( sortedImage_t ) * globalImages->images.Num() );
 
 	for ( i = 0 ; i < globalImages->images.Num() ; i++ ) {
 		image = globalImages->images[ i ];
