$NetBSD: patch-src_lib_WPS8.cpp,v 1.2 2012/02/16 18:04:08 hans Exp $

--- src/lib/WPS8.cpp.orig	2011-02-04 20:04:48.000000000 +0000
+++ src/lib/WPS8.cpp
@@ -159,7 +159,7 @@ void WPS8Parser::readStreams(WPXInputStr
 
 	for (unsigned i=0; i < n_streams; i++) {
 		uint16_t len;
-		uint32_t unknown, type = 0;
+		uint32_t type = 0;
 
 		len = readU16(input);
 		if (len > 10) {
@@ -168,7 +168,7 @@ void WPS8Parser::readStreams(WPXInputStr
 		}
 
 		if (len > 4) {
-			unknown = readU32(input); // assume == 0x22000000
+			(void) readU32(input); // assume == 0x22000000
 			type = readU32(input);
 		} else input->seek(len-2,WPX_SEEK_CUR);
 
@@ -251,7 +251,7 @@ void WPS8Parser::appendUTF16LE(WPXInputS
 	uint16_t high_surrogate = 0;
 	bool fail = false;
 	uint16_t readVal;
-	uint32_t ucs4Character;
+	uint32_t ucs4Character = 0;
 	while (true) {
 		if (input->atEOS()) {
 			fail = true;
