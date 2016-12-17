$NetBSD: patch-src_modules_lexdict_rawld_rawld.cpp,v 1.1 2016/12/17 14:22:39 joerg Exp $

--- src/modules/lexdict/rawld/rawld.cpp.orig	2016-12-17 11:25:49.864362105 +0000
+++ src/modules/lexdict/rawld/rawld.cpp
@@ -168,7 +168,7 @@ void RawLD::deleteEntry() {
 
 
 long RawLD::getEntryCount() const {
-	if (idxfd < 0) return 0;
+	if (!idxfd) return 0;
 	return idxfd->seek(0, SEEK_END) / IDXENTRYSIZE;
 }
 
