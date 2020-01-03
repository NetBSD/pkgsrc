$NetBSD: patch-window_picture.cc,v 1.1 2020/01/03 02:35:51 tsutsui Exp $

- avoid unaligned copy for RISC cpus

--- window/picture.cc.orig	2008-01-06 05:17:14.000000000 +0000
+++ window/picture.cc
@@ -370,7 +370,7 @@ err_ret:
 			char* s = (char*)((SDL_Surface*)surface_own)->pixels + ((SDL_Surface*)surface_own)->pitch*i;
 			int bpp = ((SDL_Surface*)surface_own)->format->BytesPerPixel;
 			for (j=0; j<w; j++) {
-				if ( ((*(int*)s) & 0xffffff) == 0) *a = 0;
+				if ( (read_little_endian_int(s) & 0xffffff) == 0) *a = 0;
 				else if (*a == 0) *a = 0xff;
 				s += bpp; a++;
 			}
@@ -730,10 +730,10 @@ inline Surface* FileToSurface::LoadSurfa
 		MaskType is_mask = conv->IsMask() ? ALPHA_MASK : NO_MASK;
 		if (is_mask == ALPHA_MASK) { // alpha がすべて 0xff ならマスク無しとする
 			int len = conv->Width()*conv->Height();
-			unsigned int* d = (unsigned int*)mem;
+			char* d = mem;
 			int i; for (i=0; i<len; i++) {
-				if ( (*d&0xff000000) != 0xff000000) break;
-				d++;
+				if ( (read_little_endian_int(d)&0xff000000) != 0xff000000) break;
+				d += 4;
 			}
 			if (i == len) {
 				is_mask = NO_MASK;
