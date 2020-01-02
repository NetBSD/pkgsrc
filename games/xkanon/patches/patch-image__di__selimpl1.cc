$NetBSD: patch-image__di__selimpl1.cc,v 1.1 2020/01/02 09:56:49 tsutsui Exp $

Explicitly use unsigned char instead of char because
`char' is unsigned by default on arm and powerpc.

--- image_di_selimpl1.cc.orig	2009-08-29 23:35:16.000000000 +0000
+++ image_di_selimpl1.cc
@@ -135,9 +135,9 @@ RegisterSelMacro(10, TLI4(10,11,12,13), 
 		d = dest_buf;
 		m = mask;
 		for (j=0; j<width; j++) {
-			char mask_char = IsMask ? *m : -1;
+			unsigned char mask_char = IsMask ? *m : 0xff;
 			if (mask_char) {
-				if (mask_char == -1) {
+				if (mask_char == 0xff) {
 					Copy1Pixel(d, s);
 				} else {
 					SetMiddleColor(d,s, mask_char);
@@ -709,9 +709,9 @@ RegisterSelMacro(60, TLI4(60,61,62,63), 
 					if (xi+4 < width) xlen = 4;
 					else xlen = width-xi;
 					for (xj=0; xj<xlen; xj++) {
-						char mask_char = IsMask ? *m : -1;
+						unsigned char mask_char = IsMask ? *m : 0xff;
 						if (mask_char) {
-							if (mask_char == -1) Copy1Pixel(d,s);
+							if (mask_char == 0xff) Copy1Pixel(d,s);
 							else SetMiddleColor( d, s, mask_char);
 						}
 						d += ByPP; s += ByPP; m++;
@@ -794,9 +794,9 @@ RegisterSelMacro(120, TLI10(30,31,100,10
 				m = mask - draw_points[i];
 			}
 			for (j=0; j<height; j++) {
-				char mask_char = IsMask ? *m : -1;
+				unsigned char mask_char = IsMask ? *m : 0xff;
 				if (mask_char) {
-					if (mask_char == -1) {
+					if (mask_char == 0xff) {
 						Copy1Pixel(d, s);
 					} else {
 						SetMiddleColor(d,s, mask_char);
@@ -818,9 +818,9 @@ RegisterSelMacro(120, TLI10(30,31,100,10
 				m = mask - draw_points[i]*src.width;
 			}
 			for (j=0; j<width; j++) {
-				char mask_char = IsMask ? *m : -1;
+				unsigned char mask_char = IsMask ? *m : 0xff;
 				if (mask_char) {
-					if (mask_char == -1) {
+					if (mask_char == 0xff) {
 						Copy1Pixel(d, s);
 					} else {
 						SetMiddleColor(d, s, mask_char);
