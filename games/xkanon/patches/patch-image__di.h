$NetBSD: patch-image__di.h,v 1.1 2020/01/02 09:56:49 tsutsui Exp $

Fix LP64 issue.

--- image_di.h.orig	2008-01-06 06:20:00.000000000 +0000
+++ image_di.h
@@ -275,7 +275,7 @@ struct SEL_STRUCT {
 	int kasane; // 重ね合わせフラグ
 	int arg1, arg2, arg3, arg4, arg5,arg6; // その他パラメータ
 	// 描画時に使うための一時パラメータ
-	int params[16];
+	long params[16];
 	SEL_STRUCT(void) {
 		x1=y1=x2=y2=x3=y3=0;
 		wait_time = sel_no = kasane=0;
