$NetBSD: patch-window__text.cc,v 1.1 2020/01/02 09:56:49 tsutsui Exp $

Don't use signedness checks to check 8bit chars
because `char' is unsigned by default on arm and powerpc.

--- window_text.cc.orig	2009-08-29 23:28:52.000000000 +0000
+++ window_text.cc
@@ -624,7 +624,7 @@ void AyuWindow::DrawOneChar(int flag) {
 	if (drawed_text[text_pos] == 0) {
 		if (twinfo) twinfo->End();
 	}
-	if (drawed_text[text_pos] < 0 && drawed_text[text_pos+1] == 0) {
+	if ((drawed_text[text_pos] & 0x80) != 0 && drawed_text[text_pos+1] == 0) {
 		text_pos++;
 		if (twinfo) twinfo->End();
 		return;
@@ -641,7 +641,7 @@ void AyuWindow::DrawOneChar(int flag) {
 	}
 	int is_kin = NO_KINSOKU;
 	// 1�Х���ʸ�� : ���褷�ʤ�
-	if (drawed_text[text_pos] > 0) {
+	if (drawed_text[text_pos] > 0 && (drawed_text[text_pos] & 0x80) == 0) {
 		// ���ԡ����⸵���᤹
 		if (drawed_text[text_pos] == '\n') {
 			text_x_pos = text_x_first;
