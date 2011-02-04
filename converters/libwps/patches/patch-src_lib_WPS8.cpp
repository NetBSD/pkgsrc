$NetBSD: patch-src_lib_WPS8.cpp,v 1.1 2011/02/04 20:10:32 adam Exp $

--- src/lib/WPS8.cpp.orig	2011-02-04 20:04:48.000000000 +0000
+++ src/lib/WPS8.cpp
@@ -128,7 +128,7 @@ void WPS8Parser::appendUTF16LE(WPXInputS
 	uint16_t high_surrogate = 0;
 	bool fail = false;
 	uint16_t readVal;
-	uint32_t ucs4Character;
+	uint32_t ucs4Character = 0;
 	while (true) {
 		if (input->atEOS()) {
 			fail = true;
