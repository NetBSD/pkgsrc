$NetBSD: patch-src_modules_common_rawstr4.cpp,v 1.1 2016/12/17 14:22:39 joerg Exp $

--- src/modules/common/rawstr4.cpp.orig	2016-12-17 11:19:27.919536682 +0000
+++ src/modules/common/rawstr4.cpp
@@ -74,7 +74,7 @@ RawStr4::RawStr4(const char *ipath, int 
 	buf.setFormatted("%s.dat", path);
 	datfd = FileMgr::getSystemFileMgr()->open(buf, fileMode, true);
 
-	if (datfd < 0) {
+	if (!datfd) {
 		SWLog::getSystemLog()->logError("%d", errno);
 	}
 
@@ -111,7 +111,7 @@ void RawStr4::getIDXBufDat(long ioffset,
 {
 	int size;
 	char ch;
-	if (datfd > 0) {
+	if (datfd) {
 		datfd->seek(ioffset, SEEK_SET);
 		for (size = 0; datfd->read(&ch, 1) == 1; size++) {
 			if ((ch == '\\') || (ch == 10) || (ch == 13))
@@ -145,7 +145,7 @@ void RawStr4::getIDXBuf(long ioffset, ch
 {
 	__u32 offset;
 	
-	if (idxfd > 0) {
+	if (idxfd) {
 		idxfd->seek(ioffset, SEEK_SET);
 
 		idxfd->read(&offset, 4);
