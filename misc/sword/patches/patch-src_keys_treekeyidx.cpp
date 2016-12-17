$NetBSD: patch-src_keys_treekeyidx.cpp,v 1.1 2016/12/17 14:22:39 joerg Exp $

--- src/keys/treekeyidx.cpp.orig	2016-12-17 11:16:23.463483505 +0000
+++ src/keys/treekeyidx.cpp
@@ -61,7 +61,7 @@ TreeKeyIdx::TreeKeyIdx(const char *idxPa
 	buf.setFormatted("%s.dat", path);
 	datfd = FileMgr::getSystemFileMgr()->open(buf, fileMode, true);
 
-	if (datfd <= 0) {
+	if (!datfd) {
 		SWLog::getSystemLog()->logError("%d", errno);
 		error = errno;
 	}
@@ -331,7 +331,7 @@ void TreeKeyIdx::getTreeNodeFromDatOffse
 	__s32  tmp;
 	__u16  tmp2;
 
-	if (datfd > 0) {
+	if (datfd) {
 
 		datfd->seek(ioffset, SEEK_SET);
 
@@ -385,7 +385,7 @@ char TreeKeyIdx::getTreeNodeFromIdxOffse
 	}
 
 	node->offset = ioffset;
-	if (idxfd > 0) {
+	if (idxfd) {
 		if (idxfd->getFd() > 0) {
 			idxfd->seek(ioffset, SEEK_SET);
 			if (idxfd->read(&offset, 4) == 4) {
@@ -422,7 +422,7 @@ void TreeKeyIdx::saveTreeNodeOffsets(Tre
 	long datOffset = 0;
 	__s32 tmp;
 
-	if (idxfd > 0) {
+	if (idxfd) {
 		idxfd->seek(node->offset, SEEK_SET);
 		if (idxfd->read(&tmp, 4) != 4) {
 			datOffset = datfd->seek(0, SEEK_END);
@@ -488,7 +488,7 @@ void TreeKeyIdx::copyFrom(const TreeKeyI
 void TreeKeyIdx::saveTreeNode(TreeNode *node) {
 	long datOffset = 0;
 	__s32 tmp;
-	if (idxfd > 0) {
+	if (idxfd) {
 
 		idxfd->seek(node->offset, SEEK_SET);
 		datOffset = datfd->seek(0, SEEK_END);
