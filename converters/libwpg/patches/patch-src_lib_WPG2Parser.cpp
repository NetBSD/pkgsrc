$NetBSD: patch-src_lib_WPG2Parser.cpp,v 1.1 2012/03/28 15:16:35 wiz Exp $

Fix clang warning
error: operator '?:' has lower precedence than '-'; '-' will be evaluated first [-Werror,-Wparentheses]

--- src/lib/WPG2Parser.cpp.orig	2010-11-09 08:36:36.000000000 +0000
+++ src/lib/WPG2Parser.cpp
@@ -783,7 +783,7 @@ void WPG2Parser::handleDPPenForeColor()
 	unsigned char red = (m_doublePrecision)   ? readU16()>>8 : readU8();
 	unsigned char green = (m_doublePrecision) ? readU16()>>8 : readU8();
 	unsigned char blue = (m_doublePrecision)  ? readU16()>>8 : readU8();
-	unsigned char alpha = 0xff - (m_doublePrecision) ? readU16()>>8 : readU8();
+	unsigned char alpha = (0xff - (m_doublePrecision)) ? readU16()>>8 : readU8();
 
 	m_style.insert("svg:stroke-color", libwpg::WPGColor(red, green, blue, alpha).getColorString());
 	m_style.insert("svg:stroke-opacity", libwpg::WPGColor(red, green, blue, alpha).getOpacity(), WPX_PERCENT);
@@ -1106,7 +1106,7 @@ void WPG2Parser::handleDPBrushForeColor(
 		unsigned char red = (m_doublePrecision)   ? readU16()>>8 : readU8();
 		unsigned char green = (m_doublePrecision)   ? readU16()>>8 : readU8();
 		unsigned char blue = (m_doublePrecision)   ? readU16()>>8 : readU8();
-		unsigned char alpha = 0xff - (m_doublePrecision)   ? readU16()>>8 : readU8();
+		unsigned char alpha = (0xff - (m_doublePrecision))   ? readU16()>>8 : readU8();
 		WPG_DEBUG_MSG(("   Foreground color (RGBA): %d %d %d %d\n", red, green, blue, alpha));
 
 		m_brushForeColor = libwpg::WPGColor(red, green, blue, alpha);
@@ -1131,7 +1131,7 @@ void WPG2Parser::handleDPBrushForeColor(
 				unsigned char red = (m_doublePrecision)   ? readU16()>>8 : readU8();
 				unsigned char green = (m_doublePrecision)   ? readU16()>>8 : readU8();
 				unsigned char blue = (m_doublePrecision)   ? readU16()>>8 : readU8();
-				unsigned char alpha = 0xff - (m_doublePrecision)   ? readU16()>>8 : readU8();
+				unsigned char alpha = (0xff - (m_doublePrecision))   ? readU16()>>8 : readU8();
 				libwpg::WPGColor color(red, green, blue, alpha);
 				colors.push_back(color);
 				WPG_DEBUG_MSG(("   Color #%d (RGBA): %d %d %d %d\n", i+1, red, green, blue, alpha));
