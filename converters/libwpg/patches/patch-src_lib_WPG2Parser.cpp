$NetBSD: patch-src_lib_WPG2Parser.cpp,v 1.2 2014/02/02 07:18:25 ryoon Exp $

Fix clang warning
error: operator '?:' has lower precedence than '-'; '-' will be evaluated first [-Werror,-Wparentheses]

--- src/lib/WPG2Parser.cpp.orig	2013-04-18 13:13:16.000000000 +0000
+++ src/lib/WPG2Parser.cpp
@@ -821,7 +821,7 @@ void WPG2Parser::handleDPPenForeColor()
 	unsigned char red = (m_doublePrecision)   ? readU16()>>8 : readU8();
 	unsigned char green = (m_doublePrecision) ? readU16()>>8 : readU8();
 	unsigned char blue = (m_doublePrecision)  ? readU16()>>8 : readU8();
-	unsigned char alpha = 0xff - ((m_doublePrecision) ? readU16()>>8 : readU8());
+	unsigned char alpha = (0xff - ((m_doublePrecision)) ? readU16()>>8 : readU8());
 
 	m_style.insert("svg:stroke-color", libwpg::WPGColor(red, green, blue, alpha).getColorString());
 	m_style.insert("svg:stroke-opacity", libwpg::WPGColor(red, green, blue, alpha).getOpacity(), WPX_PERCENT);
@@ -1157,7 +1157,7 @@ void WPG2Parser::handleDPBrushForeColor(
 		unsigned char red = (m_doublePrecision)   ? readU16()>>8 : readU8();
 		unsigned char green = (m_doublePrecision)   ? readU16()>>8 : readU8();
 		unsigned char blue = (m_doublePrecision)   ? readU16()>>8 : readU8();
-		unsigned char alpha = 0xff - ((m_doublePrecision)   ? readU16()>>8 : readU8());
+		unsigned char alpha = (0xff - ((m_doublePrecision))   ? readU16()>>8 : readU8());
 		WPG_DEBUG_MSG(("   Foreground color (RGBA): %d %d %d %d\n", red, green, blue, alpha));
 
 		m_brushForeColor = libwpg::WPGColor(red, green, blue, alpha);
@@ -1182,7 +1182,7 @@ void WPG2Parser::handleDPBrushForeColor(
 				unsigned char red = (m_doublePrecision)   ? readU16()>>8 : readU8();
 				unsigned char green = (m_doublePrecision)   ? readU16()>>8 : readU8();
 				unsigned char blue = (m_doublePrecision)   ? readU16()>>8 : readU8();
-				unsigned char alpha = 0xff - ((m_doublePrecision)   ? readU16()>>8 : readU8());
+				unsigned char alpha = (0xff - ((m_doublePrecision))   ? readU16()>>8 : readU8());
 				libwpg::WPGColor color(red, green, blue, alpha);
 				colors.push_back(color);
 				WPG_DEBUG_MSG(("   Color #%d (RGBA): %d %d %d %d\n", i+1, red, green, blue, alpha));
