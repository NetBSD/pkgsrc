$NetBSD: patch-image__di__seldraw.cc,v 1.1 2020/01/02 09:56:49 tsutsui Exp $

Fix LP64 issue.  

--- image_di_seldraw.cc.orig	2008-01-06 06:20:00.000000000 +0000
+++ image_di_seldraw.cc
@@ -36,7 +36,7 @@ static int MaskedDraw(SelDrawBase* drawe
 		masked_src->CreateImage(src.width, src.height, src.bypp);
 		CopyRect(*masked_src, sel->x1, sel->y1, dest, sel->x3, sel->y3, width, height);
 		CopyRectWithMask(masked_src, sel->x1, sel->y1, &src, sel->x1, sel->y1, width, height, mask);
-		sel->params[15] = int(masked_src);
+		sel->params[15] = long(masked_src);
 	}
 	int ret = drawer->Exec(dest, *(DI_Image*)(sel->params[15]), 0, sel, count);
 	if (ret == 2) { /* ½ªÎ» */
