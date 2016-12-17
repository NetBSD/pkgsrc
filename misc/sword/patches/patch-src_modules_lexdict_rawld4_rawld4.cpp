$NetBSD: patch-src_modules_lexdict_rawld4_rawld4.cpp,v 1.1 2016/12/17 14:22:39 joerg Exp $

--- src/modules/lexdict/rawld4/rawld4.cpp.orig	2016-12-17 11:25:37.737259594 +0000
+++ src/modules/lexdict/rawld4/rawld4.cpp
@@ -166,7 +166,7 @@ void RawLD4::deleteEntry() {
 
 
 long RawLD4::getEntryCount() const {
-	if (idxfd < 0) return 0;
+	if (!idxfd) return 0;
 	return idxfd->seek(0, SEEK_END) / IDXENTRYSIZE;
 }
 
