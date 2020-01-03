$NetBSD: patch-scn2k_scn2k__text.cc,v 1.1 2020/01/03 02:35:51 tsutsui Exp $

- don't assume signed char for arm and powerpc
- explicitly use NULL to pass NULL pointer via varargs

--- scn2k/scn2k_text.cc.orig	2008-08-31 15:26:43.000000000 +0000
+++ scn2k/scn2k_text.cc
@@ -789,7 +789,7 @@ void TextImpl::AddText(const char* str_o
 	/* ＊ = 81 96 A-Z = 0x82 [0x60-0x79] */
 	/* ％ = 81 93 A-Z = 0x82 [0x60-0x79] */
 	for (i=0; cnt<10000 && str_o[i] != 0; i++) {
-		if (str_o[i] < 0) {
+		if ((str_o[i] & 0x80) != 0) {
 			if ( (unsigned char)str_o[i] == 0x81 && (unsigned char)str_o[i+1] == 0x96 && (unsigned char)str_o[i+2] == 0x82) {
 				int c = str_o[i+3];
 				if (c >= 0x60 && c <= 0x79 && replace_name[c-0x60].length() != 0) { // 名前変換
@@ -831,7 +831,7 @@ void TextImpl::AddText(const char* str_o
 					text_stream.AddName(name_top);
 					break;
 				}
-				if (*s < 0 && s[1] != 0) s++; // 全角文字なら２字飛ばす
+				if ((*s & 0x80) != 0 && s[1] != 0) s++; // 全角文字なら２字飛ばす
 			}
 			str_top = s;
 		}
@@ -840,7 +840,7 @@ void TextImpl::AddText(const char* str_o
 			text_stream.Add(str_top);
 			text_stream.AddReturn();
 			str_top = s;
-		} else if (*s < 0 && s[1] != 0) s++;
+		} else if ((*s & 0x80) != 0 && s[1] != 0) s++;
 	}
 	text_stream.Add(str_top);
 	return;
@@ -1874,7 +1874,7 @@ void TextWindow::MakeWaku(PicContainer& 
 		}
 		int x, y, w, h;
 		sprintf(key, "#WAKU.%03d.000.%s_BOX", waku_no, btnname[i]);
-		if (config.GetParam(key, 5, 0, &x, &y, &w, &h) == -1) continue;
+		if (config.GetParam(key, 5, NULL, &x, &y, &w, &h) == -1) continue;
 		int sx, sy, sdx, sdy, cnt;
 		const char* d = data + 9 + btnpos[i]*24*8;
 		sx = read_little_endian_int(d);
@@ -1901,7 +1901,7 @@ TextWindow::TextWindow(PicContainer& par
 	sprintf(key, "#WINDOW.%03d.MOJI_REP", win_no);  if (config.GetParam(key, 2, &rep1, &rep2) == -1) return;
 	sprintf(key, "#WINDOW.%03d.MOJI_CNT", win_no);  if (config.GetParam(key, 2, &cntw, &cnth) == -1) return;
 	sprintf(key, "#WINDOW.%03d.POS", win_no);       if (config.GetParam(key, 3, &posd, &posx, &posy) == -1) return;
-	sprintf(key, "#WINDOW.%03d.MOJI_POS", win_no);  if (config.GetParam(key, 4, &mposy, 0, &mposx, 0) == -1) return;
+	sprintf(key, "#WINDOW.%03d.MOJI_POS", win_no);  if (config.GetParam(key, 4, &mposy, NULL, &mposx, NULL) == -1) return;
 	sprintf(key, "#WINDOW.%03d.MOJI_MIN", win_no);  if (config.GetParam(key, 2, &minx, &miny) == -1) return;
 	sprintf(key, "#WINDOW.%03d.WAKU_SETNO", win_no);if (config.GetParam(key, 1, &waku_no) == -1) return;
 	sprintf(key, "#WINDOW.%03d.LUBY_SIZE", win_no); if (config.GetParam(key, 1, &ruby) == -1) return;
