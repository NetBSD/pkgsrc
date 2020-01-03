$NetBSD: patch-font_text__stream.cc,v 1.1 2020/01/03 02:35:51 tsutsui Exp $

- don't assume signed char for arm and powerpc

--- font/text_stream.cc.orig	2008-08-31 15:11:10.000000000 +0000
+++ font/text_stream.cc
@@ -89,10 +89,10 @@ void TextStream::Clear(void) {
 void TextStream::Add(const char* str) {
 	TextElem elem;
 	for (; *str; str++) {
-		if (*str >= 0x20) {
+		if (*str >= 0x20 && (*str & 0x80) == 0) {
 			elem.type = TextElem::glyph;
 			elem.impl.Glyph.code = *str;
-		} else if (*str < 0 && str[1] != 0) {
+		} else if ((*str & 0x80) != 0 && str[1] != 0) {
 			elem.type = TextElem::glyph;
 			elem.impl.Glyph.code = ((int(*(unsigned char*)str))<<8) | int(*(unsigned char*)(str+1));
 			if (kanji_type == sjis) elem.impl.Glyph.code = codeconv_sjis_to_euc(elem.impl.Glyph.code);
@@ -222,9 +222,9 @@ void TextStream::Load(const std::string&
 				s++;
 			}
 		} else {
-			if (*s < 0) { // kanji-code
+			if ((*s & 0x80) != 0) { // kanji-code
 				if (s[1] == 0) break;
-				if (s[1] >= 0 && s[1] < 0x40) break; // not EUC nor SJIS
+				if ((s[1] & 0x80) == 0 && s[1] < 0x40) break; // not EUC nor SJIS
 				e.type = TextElem::glyph;
 				e.impl.Glyph.code = codeconv_sjis_to_euc(int(*(unsigned char*)(s))*0x100 + int(*(unsigned char*)(s+1)));
 				s += 2;
