$NetBSD: patch-fbreader_src_formats_doc_OleStorage.cpp,v 1.1.2.2 2019/09/21 18:40:05 bsiegert Exp $

Fix narrowing conversion error

--- fbreader/src/formats/doc/OleStorage.cpp.orig	2012-11-30 12:41:25.000000000 +0000
+++ fbreader/src/formats/doc/OleStorage.cpp
@@ -59,7 +59,8 @@ bool OleStorage::init(shared_ptr<ZLInput
 		clear();
 		return false;
 	}
-	static const char OLE_SIGN[] = {0xD0, 0xCF, 0x11, 0xE0, 0xA1, 0xB1, 0x1A, 0xE1, 0};
+	static const char OLE_SIGN[] = {(char)0xD0, (char)0xCF, (char)0x11,
+		(char)0xE0, (char)0xA1, (char)0xB1, (char)0x1A, (char)0xE1, 0};
 	if (std::strncmp(oleBuf, OLE_SIGN, 8) != 0) {
 		clear();
 		return false;
