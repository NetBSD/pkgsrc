$NetBSD: patch-src_core_download__list.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/core/download_list.cc.orig	2013-05-03 22:46:43.000000000 +0000
+++ src/core/download_list.cc
@@ -181,8 +181,8 @@ DownloadList::insert(Download* download)
   lt_log_print_info(torrent::LOG_TORRENT_INFO, download->info(), "download_list", "Inserting download.");
 
   try {
-    (*itr)->data()->slot_initial_hash()        = tr1::bind(&DownloadList::hash_done, this, download);
-    (*itr)->data()->slot_download_done()       = tr1::bind(&DownloadList::received_finished, this, download);
+    (*itr)->data()->slot_initial_hash()        = bind(&DownloadList::hash_done, this, download);
+    (*itr)->data()->slot_download_done()       = bind(&DownloadList::received_finished, this, download);
 
     // This needs to be separated into two different calls to ensure
     // the download remains in the view.
