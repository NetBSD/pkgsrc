$NetBSD: patch-src_core_download__list.cc,v 1.3 2013/09/18 16:33:08 joerg Exp $

--- src/core/download_list.cc.orig	2012-02-22 07:50:48.000000000 +0000
+++ src/core/download_list.cc
@@ -65,6 +65,14 @@
 #include "download_list.h"
 #include "download_store.h"
 
+#if __cplusplus >= 201103L
+#include <functional>
+using std::bind;
+#else
+#include <tr1/functional>
+using std::tr1::bind;
+#endif
+
 #define DL_TRIGGER_EVENT(download, event_name) \
   rpc::commands.call_catch(event_name, rpc::make_target(download), torrent::Object(), "Event '" event_name "' failed: ");
 
@@ -181,8 +189,8 @@ DownloadList::insert(Download* download)
   lt_log_print_info(torrent::LOG_TORRENT_INFO, download->info(), "download_list", "Inserting download.");
 
   try {
-    (*itr)->data()->slot_initial_hash()        = tr1::bind(&DownloadList::hash_done, this, download);
-    (*itr)->data()->slot_download_done()       = tr1::bind(&DownloadList::received_finished, this, download);
+    (*itr)->data()->slot_initial_hash()        = bind(&DownloadList::hash_done, this, download);
+    (*itr)->data()->slot_download_done()       = bind(&DownloadList::received_finished, this, download);
 
     // This needs to be separated into two different calls to ensure
     // the download remains in the view.
