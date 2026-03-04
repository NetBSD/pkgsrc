$NetBSD: patch-window_widget.cc,v 1.1 2026/03/04 10:27:20 tsutsui Exp $

- appease -Wwrite-strings warning

--- window/widget.cc.orig	2026-03-03 20:57:17.461689932 +0000
+++ window/widget.cc
@@ -37,7 +37,7 @@ void DSurfaceMove(Surface* src, const Re
 
 //static char* wdefault_font_orig = "msgothic.ttc;times.ttf;";
 static std::map<int, XKFont::HorizLayout*> size_to_layout;
-static char* wdefault_font_orig = "times.ttf;msgothic.ttc";
+static const char* wdefault_font_orig = "times.ttf;msgothic.ttc";
 static std::string wdefault_font = wdefault_font_orig;
 
 void SetFont(const char* font) {
