$NetBSD: patch-image__di__selimpl3.cc,v 1.1 2020/01/02 09:56:49 tsutsui Exp $

- Explicitly use unsigned char instead of char because
  `char' is unsigned by default on arm and powerpc.
- Fix LP64 issue.  
- Appease LP64 warnings.

--- image_di_selimpl3.cc.orig	2009-08-29 23:12:54.000000000 +0000
+++ image_di_selimpl3.cc
@@ -22,10 +22,10 @@ RegisterSelMacro(70, TLI4(70,71,72,73), 
 		int i; for (i=0; i<line_deal; i++) {
 			line_counts[i] = -sel->arg4 * (AyuSys::Rand(sel->arg5));
 		}
-		sel->params[0] = int(line_counts);
+		sel->params[0] = long(line_counts);
 		sel->params[1] = line_deal;
 		sel->params[2] = line_width;
-		sel->params[3] = int(line_firsts);
+		sel->params[3] = long(line_firsts);
 		sel->params[4] = -1;
 	}
 	int* line_counts = (int*)sel->params[0];
@@ -82,9 +82,9 @@ RegisterSelMacro(70, TLI4(70,71,72,73), 
 			char* s = src_pt + lf * ByPP;
 			char* m = mask_pt + lf;
 			int j; for (j=0; j<dw; j++) {
-				char mask_char = IsMask ? *m : -1;
+				unsigned char mask_char = IsMask ? *m : 0xff;
 				if (mask_char) {
-					if (mask_char == -1) Copy1Pixel(d ,s);
+					if (mask_char == 0xff) Copy1Pixel(d ,s);
 					else SetMiddleColor(d, s, mask_char);
 				}
 				d+= ByPP; s+=ByPP; if (IsMask) m++;
@@ -101,9 +101,9 @@ RegisterSelMacro(70, TLI4(70,71,72,73), 
 			char* s = src_pt + lf*src.bpl;
 			char* m = mask_pt + lf*src.width;
 			int j; for (j=0; j<dw; j++) {
-				char mask_char = IsMask ? *m : -1;
+				unsigned char mask_char = IsMask ? *m : 0xff;
 				if (mask_char) {
-					if (mask_char == -1) Copy1Pixel(d,s);
+					if (mask_char == 0xff) Copy1Pixel(d,s);
 					else SetMiddleColor(d, s, mask_char);
 				}
 				d += dest.bpl; s += src.bpl; if (IsMask) m += src.width;
@@ -139,10 +139,10 @@ RegisterSelMacro(80, TLI4(80,81,82,83), 
 		int i; for (i=0; i<line_deal; i++) {
 			line_counts[i] = -sel->arg4 * (AyuSys::Rand(sel->arg5));
 		}
-		sel->params[0] = int(line_counts);
+		sel->params[0] = long(line_counts);
 		sel->params[1] = line_deal;
 		sel->params[2] = line_width;
-		sel->params[3] = int(line_firsts);
+		sel->params[3] = long(line_firsts);
 		sel->params[4] = -1;
 	}
 	int* line_counts = (int*)sel->params[0];
@@ -364,8 +364,8 @@ RegisterSelMacro(170, TLI1(170), WithMas
 		DI_Image* dest_orig = new DI_Image;
 		dest_orig->CreateImage(width, height, ByPP);
 		CopyRect(*dest_orig, 0, 0, dest, sel->x3, sel->y3, width, height);
-		sel->params[0] = int(dest_orig->data);
-		sel->params[1] = int(dest_orig);
+		sel->params[0] = long(dest_orig->data);
+		sel->params[1] = long(dest_orig);
 	}
 	int w_width = 0; int copy_line = 0;
 	DI_Image& dest_orig = *(DI_Image*)sel->params[1];
@@ -387,7 +387,7 @@ RegisterSelMacro(170, TLI1(170), WithMas
 			else
 				CopyRect(dest_orig, 0, sel->params[2]+i, src, sel->x1, sel->y1+sel->params[2]+i, width, copy_line-sel->params[2]);
 		}
-printf("copy line %3d->%3d\n",sel->params[2],copy_line);
+printf("copy line %3ld->%3d\n",sel->params[2],copy_line);
 		sel->params[2] = copy_line;
 	}
 	double theta = sel->params[3]*(4*3.141592*2/360); /* sin うねりの最初の角度は radian 単位で sel->params[3]*4 度 */
