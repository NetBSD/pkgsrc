$NetBSD: patch-src_lib_WPS8.cpp,v 1.3 2012/03/28 15:17:19 wiz Exp $

3rd chunk: fix clang error: expression result unused [-Werror,-Wunused-value]

--- src/lib/WPS8.cpp.orig	2011-05-03 13:00:13.000000000 +0000
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
 
@@ -196,8 +196,6 @@ void WPS8Parser::readNotes(std::vector<W
 	if (headerIndexTable.end() == pos)
 		return;
 
-	pos->second.length;
-
 	uint32_t unk1;
 	uint32_t count;
 	uint32_t boff;
@@ -251,7 +249,7 @@ void WPS8Parser::appendUTF16LE(WPXInputS
 	uint16_t high_surrogate = 0;
 	bool fail = false;
 	uint16_t readVal;
-	uint32_t ucs4Character;
+	uint32_t ucs4Character = 0;
 	while (true) {
 		if (input->atEOS()) {
 			fail = true;
