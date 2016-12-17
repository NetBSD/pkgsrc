$NetBSD: patch-src_mgr_swmgr.cpp,v 1.1 2016/12/17 14:22:39 joerg Exp $

--- src/mgr/swmgr.cpp.orig	2016-12-17 11:17:23.119076977 +0000
+++ src/mgr/swmgr.cpp
@@ -1362,7 +1362,7 @@ void SWMgr::InstallScan(const char *dirn
 					else {
 						if (!conffd) {
 							conffd = FileMgr::getSystemFileMgr()->open(config->filename.c_str(), FileMgr::WRONLY|FileMgr::APPEND);
-							if (conffd > 0)
+							if (conffd)
 								conffd->seek(0L, SEEK_END);
 							else {
 								FileMgr::getSystemFileMgr()->close(conffd);
