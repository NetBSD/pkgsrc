$NetBSD: patch-src_modules_common_zstr.cpp,v 1.1 2016/12/17 14:22:39 joerg Exp $

--- src/modules/common/zstr.cpp.orig	2016-12-17 11:20:39.892321366 +0000
+++ src/modules/common/zstr.cpp
@@ -83,7 +83,7 @@ zStr::zStr(const char *ipath, int fileMo
 	buf.setFormatted("%s.zdt", path);
 	zdtfd = FileMgr::getSystemFileMgr()->open(buf, fileMode, true);
 
-	if (datfd <= 0) {
+	if (!datfd) {
 		SWLog::getSystemLog()->logError("%d", errno);
 	}
 
@@ -133,7 +133,7 @@ void zStr::getKeyFromDatOffset(long ioff
 {
 	int size;
 	char ch;
-	if (datfd > 0) {
+	if (datfd) {
 		datfd->seek(ioffset, SEEK_SET);
 		for (size = 0; datfd->read(&ch, 1) == 1; size++) {
 			if ((ch == '\\') || (ch == 10) || (ch == 13))
@@ -167,7 +167,7 @@ void zStr::getKeyFromIdxOffset(long ioff
 {
 	__u32 offset;
 	
-	if (idxfd > 0) {
+	if (idxfd) {
 		idxfd->seek(ioffset, SEEK_SET);
 		idxfd->read(&offset, 4);
 		offset = swordtoarch32(offset);
