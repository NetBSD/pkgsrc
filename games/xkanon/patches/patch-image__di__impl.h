$NetBSD: patch-image__di__impl.h,v 1.1 2020/01/02 09:56:49 tsutsui Exp $

Explicitly use unsigned char instead of char because
`char' is unsigned by default on arm and powerpc.

--- image_di_impl.h.orig	2009-08-29 23:30:51.000000000 +0000
+++ image_di_impl.h
@@ -276,9 +276,9 @@ DifImage* Drawer<T>::MakeDifImage(DI_Ima
 			char* m = mask + i*mbpl;
 			memcpy(masked_line, dest+i*dbpl, width*ByPP);
 			for (j=0; j<width; j++) {
-				char mask_char = *m;
+				unsigned char mask_char = *m;
 				if (mask_char) {
-					if (mask_char == -1) {
+					if (mask_char == 0xff) {
 						Copy1Pixel(d, s);
 					 }else {
 						SetMiddleColor(d, s, mask_char);
