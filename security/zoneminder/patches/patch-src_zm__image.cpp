$NetBSD: patch-src_zm__image.cpp,v 1.1 2020/03/29 01:06:11 joerg Exp $

std::abs works better with a signed argument.

--- src/zm_image.cpp.orig	2020-03-28 21:54:25.650909348 +0000
+++ src/zm_image.cpp
@@ -1580,7 +1580,7 @@ Image *Image::Highlight( unsigned int n_
 			{
 				uint8_t *psrc = images[j]->buffer+c;
 
-				if ( (unsigned)abs((*psrc)-RGB_VAL(ref_colour,c)) >= RGB_VAL(threshold,c) )
+				if ( (unsigned)abs(int(*psrc)-int(RGB_VAL(ref_colour,c))) >= RGB_VAL(threshold,c) )
 				{
 					count++;
 				}
