$NetBSD: patch-src_modules_lexdict_zld_zld.cpp,v 1.1 2016/12/17 14:22:39 joerg Exp $

--- src/modules/lexdict/zld/zld.cpp.orig	2016-12-17 11:25:18.042867195 +0000
+++ src/modules/lexdict/zld/zld.cpp
@@ -166,7 +166,7 @@ void zLD::deleteEntry() {
 
 long zLD::getEntryCount() const
 {
-	if (idxfd < 0) return 0;
+	if (!idxfd) return 0;
 	return idxfd->seek(0, SEEK_END) / IDXENTRYSIZE;
 }
 
