$NetBSD: patch-plugins_xslfo_xp_ie__exp__XSL-FO.cpp,v 1.1 2018/06/30 12:43:29 maya Exp $

Bug 13754 - Fix build on gcc-6 (default to C++11)
https://github.com/AbiWord/abiword/commit/a83e6f50dbd5efa16fb39efe32b9de370f103130

--- plugins/xslfo/xp/ie_exp_XSL-FO.cpp.orig	2013-04-07 13:53:03.000000000 +0000
+++ plugins/xslfo/xp/ie_exp_XSL-FO.cpp
@@ -1451,7 +1451,7 @@ void s_XSL_FO_Listener::_openSection(PT_
 	{ \
 		UT_UTF8String esc = szValue; \
 		esc.escapeXML(); \
-		buf += " "x"=\""; \
+		buf += " " x"=\""; \
 		buf += esc.utf8_str(); \
 		buf += "\""; \
 	}
