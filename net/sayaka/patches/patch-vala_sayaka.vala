$NetBSD: patch-vala_sayaka.vala,v 1.4 2020/01/28 15:00:45 tsutsui Exp $

- pull upstream change for monochrome terminal settings:
 https://github.com/isaki68k/sayaka/commit/7746eed85599a72f03ff464e21b5cbeae46ab7c2
--- vala/sayaka.vala.orig	2020-01-12 07:03:03.000000000 +0000
+++ vala/sayaka.vala
@@ -1811,6 +1811,14 @@ public class SayakaMain
 		string fav;
 		string gray;
 
+		// 2色ならテキストに色(も何の属性も)つけない
+		if (color_mode != ColorFixedX68k && color_mode <= 2) {
+			for (var i = 0; i < Color.Max; i++) {
+				color2esc[i] = "";
+			}
+			return;
+		}
+
 		// 黒背景か白背景かで色合いを変えたほうが読みやすい
 		if (bg_white) {
 			blue = BLUE;
