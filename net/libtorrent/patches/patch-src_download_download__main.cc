$NetBSD: patch-src_download_download__main.cc,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/download/download_main.cc.orig	2012-04-20 06:42:32.000000000 +0000
+++ src/download/download_main.cc
@@ -64,7 +64,13 @@
 #include "download_main.h"
 #include "download_wrapper.h"
 
-namespace tr1 { using namespace std::tr1; }
+#if __cplusplus >= 201103L
+using std::bind;
+#define STD_PLACEHOLDERS std::placeholders
+#else
+using std::tr1::bind;
+#define STD_PLACEHOLDERS std::tr1::placeholders
+#endif
 
 namespace torrent {
 
@@ -103,11 +109,11 @@ DownloadMain::DownloadMain() :
   m_tracker_list = new TrackerList();
   m_tracker_controller = new TrackerController(m_tracker_list);
 
-  m_tracker_list->slot_success() = tr1::bind(&TrackerController::receive_success, m_tracker_controller, tr1::placeholders::_1, tr1::placeholders::_2);
-  m_tracker_list->slot_failure() = tr1::bind(&TrackerController::receive_failure, m_tracker_controller, tr1::placeholders::_1, tr1::placeholders::_2);
-  m_tracker_list->slot_scrape_success() = tr1::bind(&TrackerController::receive_scrape, m_tracker_controller, tr1::placeholders::_1);
-  m_tracker_list->slot_tracker_enabled()  = tr1::bind(&TrackerController::receive_tracker_enabled, m_tracker_controller, tr1::placeholders::_1);
-  m_tracker_list->slot_tracker_disabled() = tr1::bind(&TrackerController::receive_tracker_disabled, m_tracker_controller, tr1::placeholders::_1);
+  m_tracker_list->slot_success() = bind(&TrackerController::receive_success, m_tracker_controller, STD_PLACEHOLDERS::_1, STD_PLACEHOLDERS::_2);
+  m_tracker_list->slot_failure() = bind(&TrackerController::receive_failure, m_tracker_controller, STD_PLACEHOLDERS::_1, STD_PLACEHOLDERS::_2);
+  m_tracker_list->slot_scrape_success() = bind(&TrackerController::receive_scrape, m_tracker_controller, STD_PLACEHOLDERS::_1);
+  m_tracker_list->slot_tracker_enabled()  = bind(&TrackerController::receive_tracker_enabled, m_tracker_controller, STD_PLACEHOLDERS::_1);
+  m_tracker_list->slot_tracker_disabled() = bind(&TrackerController::receive_tracker_disabled, m_tracker_controller, STD_PLACEHOLDERS::_1);
 
   m_connectionList = new ConnectionList(this);
 
@@ -119,12 +125,12 @@ DownloadMain::DownloadMain() :
   m_delegator.transfer_list()->slot_completed(std::bind1st(std::mem_fun(&DownloadMain::receive_chunk_done), this));
   m_delegator.transfer_list()->slot_corrupt(std::bind1st(std::mem_fun(&DownloadMain::receive_corrupt_chunk), this));
 
-  m_delayDisconnectPeers.slot() = std::tr1::bind(&ConnectionList::disconnect_queued, m_connectionList);
-  m_taskTrackerRequest.slot() = std::tr1::bind(&DownloadMain::receive_tracker_request, this);
+  m_delayDisconnectPeers.slot() = bind(&ConnectionList::disconnect_queued, m_connectionList);
+  m_taskTrackerRequest.slot() = bind(&DownloadMain::receive_tracker_request, this);
 
   m_chunkList->set_data(file_list()->mutable_data());
-  m_chunkList->slot_create_chunk() = tr1::bind(&FileList::create_chunk_index, file_list(), tr1::placeholders::_1, tr1::placeholders::_2);
-  m_chunkList->slot_free_diskspace() = tr1::bind(&FileList::free_diskspace, file_list());
+  m_chunkList->slot_create_chunk() = bind(&FileList::create_chunk_index, file_list(), STD_PLACEHOLDERS::_1, STD_PLACEHOLDERS::_2);
+  m_chunkList->slot_free_diskspace() = bind(&FileList::free_diskspace, file_list());
 }
 
 DownloadMain::~DownloadMain() {
