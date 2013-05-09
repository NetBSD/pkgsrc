$NetBSD: patch-src_download_download__wrapper.cc,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/download/download_wrapper.cc.orig	2012-04-20 06:42:32.000000000 +0000
+++ src/download/download_wrapper.cc
@@ -62,7 +62,13 @@
 
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
 
@@ -73,13 +79,13 @@ DownloadWrapper::DownloadWrapper() :
   m_hashChecker(NULL),
   m_connectionType(0) {
 
-  m_main->delay_download_done().slot() = std::tr1::bind(&download_data::call_download_done, data());
+  m_main->delay_download_done().slot() = bind(&download_data::call_download_done, data());
 
   m_main->tracker_list()->set_info(info());
-  m_main->tracker_controller()->slot_success() = tr1::bind(&DownloadWrapper::receive_tracker_success, this, tr1::placeholders::_1);
-  m_main->tracker_controller()->slot_failure() = tr1::bind(&DownloadWrapper::receive_tracker_failed, this, tr1::placeholders::_1);
+  m_main->tracker_controller()->slot_success() = bind(&DownloadWrapper::receive_tracker_success, this, STD_PLACEHOLDERS::_1);
+  m_main->tracker_controller()->slot_failure() = bind(&DownloadWrapper::receive_tracker_failed, this, STD_PLACEHOLDERS::_1);
 
-  m_main->chunk_list()->slot_storage_error() = tr1::bind(&DownloadWrapper::receive_storage_error, this, tr1::placeholders::_1);
+  m_main->chunk_list()->slot_storage_error() = bind(&DownloadWrapper::receive_storage_error, this, STD_PLACEHOLDERS::_1);
 }
 
 DownloadWrapper::~DownloadWrapper() {
@@ -122,7 +128,7 @@ DownloadWrapper::initialize(const std::s
   m_hashChecker->slot_check(rak::make_mem_fun(this, &DownloadWrapper::check_chunk_hash));
 //   m_hashChecker->slot_storage_error(rak::make_mem_fun(this, &DownloadWrapper::receive_storage_error));
 
-  m_hashChecker->delay_checked().slot() = std::tr1::bind(&DownloadWrapper::receive_initial_hash, this);
+  m_hashChecker->delay_checked().slot() = bind(&DownloadWrapper::receive_initial_hash, this);
 }
 
 void
@@ -241,7 +247,7 @@ DownloadWrapper::check_chunk_hash(ChunkH
   ChunkHandle new_handle = m_main->chunk_list()->get(handle.index(), ChunkList::get_blocking);
   m_main->chunk_list()->release(&handle);
 
-  hash_queue()->push_back(new_handle, data(), tr1::bind(&DownloadWrapper::receive_hash_done, this, tr1::placeholders::_1, tr1::placeholders::_2));
+  hash_queue()->push_back(new_handle, data(), bind(&DownloadWrapper::receive_hash_done, this, STD_PLACEHOLDERS::_1, STD_PLACEHOLDERS::_2));
 }
 
 void
