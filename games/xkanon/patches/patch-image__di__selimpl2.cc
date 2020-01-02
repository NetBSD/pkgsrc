$NetBSD: patch-image__di__selimpl2.cc,v 1.1 2020/01/02 09:56:49 tsutsui Exp $

Fix LP64 issue.  

--- image_di_selimpl2.cc.orig	2009-08-29 23:12:45.000000000 +0000
+++ image_di_selimpl2.cc
@@ -19,7 +19,7 @@ RegisterSelMacro(50, TLI1(50), WithMask)
 	if (count == 0) {
 		// 描画開始時の初期化
 		difimage = MakeDifImage(dest, src, mask, sel);
-		sel->params[0] = int(difimage);
+		sel->params[0] = long(difimage);
 		sel->params[2] = 0;
 		return 1;
 	}
@@ -119,7 +119,7 @@ RegisterSelMacro(54, TLI1(54), NoMask) /
 			sel->arg5 ? CalcKido(dest.data+sel->x3*ByPP+sel->y3*dest.bpl, dest.bpl, width, height, sel->arg4)
 			: CalcKido(src_buf, src.bpl, width, height, sel->arg4);
 		/* バッファに格納 */
-		sel->params[0] = int(src_buf); sel->params[1] = int(kido_buf);
+		sel->params[0] = long(src_buf); sel->params[1] = long(kido_buf);
 		sel->params[2] = width; sel->params[3] = height; sel->params[4] = src.bpl;
 		sel->params[5] = 0; sel->params[6] = 0;
 		return 1;
@@ -189,8 +189,8 @@ RegisterSelMacro(161, TLI1(161), NoMask)
 		DI_Image* dest_orig = new DI_Image;
 		dest_orig->CreateImage(width, height, ByPP);
 		CopyRect(*dest_orig, 0, 0, dest, sel->x3, sel->y3, width, height);
-		sel->params[0] = int(dest_orig->data);
-		sel->params[1] = int(dest_orig);
+		sel->params[0] = long(dest_orig->data);
+		sel->params[1] = long(dest_orig);
 		sel->params[2] = width; sel->params[3] = height;
 	}
 	if (sel->arg4 != 0) {
@@ -250,8 +250,8 @@ RegisterSelMacro(162, TLI1(162), NoMask)
 		DI_Image* dest_orig = new DI_Image;
 		dest_orig->CreateImage(width, height, ByPP);
 		CopyRect(*dest_orig, 0, 0, dest, sel->x3, sel->y3, width, height);
-		sel->params[0] = int(dest_orig->data);
-		sel->params[1] = int(dest_orig);
+		sel->params[0] = long(dest_orig->data);
+		sel->params[1] = long(dest_orig);
 		if (sel->arg4 != 0) {
 			max_count = (width > height) ? width : height;
 			max_count /= sel->arg4;
@@ -292,8 +292,8 @@ RegisterSelMacro(163, TLI1(163), NoMask)
 		DI_Image* dest_orig = new DI_Image;
 		dest_orig->CreateImage(width, height, ByPP);
 		CopyRect(*dest_orig, 0, 0, dest, sel->x3, sel->y3, width, height);
-		sel->params[0] = int(dest_orig->data);
-		sel->params[1] = int(dest_orig);
+		sel->params[0] = long(dest_orig->data);
+		sel->params[1] = long(dest_orig);
 		/* max count の計算 */
 		int i; for (i=0; i<16; i++) {
 			int c = 1<<i;
@@ -340,7 +340,7 @@ RegisterSelMacro(200, TLI1(200), NoMask)
 		DI_Image* orig = new DI_Image;
 		orig->CreateImage(src.width, src.height, ByPP);
 		CopyRect(*orig, 0, 0, src, 0, 0, src.width, src.height);
-		sel->params[0] = int(orig);
+		sel->params[0] = long(orig);
 	}
 	DI_Image* src_orig = (DI_Image*)sel->params[0];
 	int max_count = (sel->arg6 >> 16) - 1;
@@ -395,7 +395,7 @@ RegisterSelMacro(210, TLI3(210,211,213),
 		DI_Image* orig = new DI_Image;
 		orig->CreateImage(dest.width, dest.height, ByPP);
 		CopyRect(*orig, 0, 0, dest, 0, 0, dest.width, dest.height);
-		sel->params[0] = int(orig);
+		sel->params[0] = long(orig);
 		sel->params[1] = 0;
 	}
 	DI_Image* dest_orig = (DI_Image*)sel->params[0];
@@ -477,7 +477,7 @@ RegisterSelMacro(212, TLI1(212), NoMask)
 		DI_Image* orig = new DI_Image;
 		orig->CreateImage(dest.width, dest.height, ByPP);
 		CopyRect(*orig, 0, 0, dest, 0, 0, dest.width, dest.height);
-		sel->params[0] = int(orig);
+		sel->params[0] = long(orig);
 		sel->params[1] = 0;
 		return 0;
 	}
@@ -555,7 +555,7 @@ RegisterSelMacro(220, TLI2(220,221), NoM
 		DI_Image* orig = new DI_Image;
 		orig->CreateImage(dest.width, dest.height, ByPP);
 		CopyRect(*orig, 0, 0, dest, 0, 0, dest.width, dest.height);
-		sel->params[0] = int(orig);
+		sel->params[0] = long(orig);
 	}
 	int max_count = 31;
 	if (sel->arg4 != 0) max_count = sel->arg4;
@@ -609,7 +609,7 @@ RegisterSelMacro(222, TLI1(222), NoMask)
 		DI_Image* orig = new DI_Image;
 		orig->CreateImage(dest.width, dest.height, ByPP);
 		CopyRect(*orig, 0, 0, dest, 0, 0, dest.width, dest.height);
-		sel->params[0] = int(orig);
+		sel->params[0] = long(orig);
 		sel->params[1] = 0;
 		return 0;
 	}
@@ -673,7 +673,7 @@ RegisterSelMacro(230, TLI9(230,231,232,2
 	if (count == 0) {
 		// 画像の差分を得る
 		difimage = MakeDifImage(dest, src, mask, sel);
-		sel->params[0] = int(difimage);
+		sel->params[0] = long(difimage);
 
 		// テーブルを初期化
 		if (sel->sel_no < 234) { /* 上下左右に fade */
@@ -715,7 +715,7 @@ RegisterSelMacro(230, TLI9(230,231,232,2
 			cur->direction = UtoD;
 			blockdata->next->next->next = cur;
 		}
-		sel->params[1] = int(blockdata);
+		sel->params[1] = long(blockdata);
 		return 0;
 	}
 
@@ -747,12 +747,12 @@ RegisterSelMacro(260, TLI8(260,261,262,2
 	if (count == 0) {
 		// 画像の差分を得る
 		difimage = MakeDifImage(dest, src, mask, sel);
-		sel->params[0] = int(difimage);
+		sel->params[0] = long(difimage);
 
 		// テーブルを初期化
 		blockdata = new BlockFadeData(4, 4, 0, 0, width, height);
 		blockdata->diag_dir = BlockFadeData::DDIR( (sel->sel_no-260)%4);
-		sel->params[1] = int(blockdata);
+		sel->params[1] = long(blockdata);
 		return 0;
 	}
 
@@ -787,7 +787,7 @@ RegisterSelMacro(270, TLI4(270,271,272,2
 	if (count == 0) {
 		// 画像の差分を得る
 		difimage = MakeDifImage(dest, src, mask, sel);
-		sel->params[0] = int(difimage);
+		sel->params[0] = long(difimage);
 
 		// テーブルを初期化
 		curblock = new BlockFadeData(4, 4, 0, 0, width/2, height/2);
@@ -818,7 +818,7 @@ RegisterSelMacro(270, TLI4(270,271,272,2
 			blockdata->next->next->next->diag_dir = BlockFadeData::DRtoUL;
 			break;
 		}
-		sel->params[1] = int(blockdata);
+		sel->params[1] = long(blockdata);
 		return 0;
 	}
 
@@ -847,7 +847,7 @@ RegisterSelMacro(240, TLI4(240,241,242,2
 		DI_Image* orig = new DI_Image;
 		orig->CreateImage(dest.width, dest.height, ByPP);
 		CopyRect(*orig, 0, 0, dest, 0, 0, dest.width, dest.height);
-		sel->params[0] = int(orig);
+		sel->params[0] = long(orig);
 	}
 	DI_Image* dest_orig = (DI_Image*)sel->params[0];
 	int width = sel->x2 - sel->x1 + 1; int height = sel->y2 - sel->y1 + 1;
