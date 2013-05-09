$NetBSD: patch-src_torrent_download_resource__manager.cc,v 1.1 2013/05/09 14:26:41 joerg Exp $

--- src/torrent/download/resource_manager.cc.orig	2012-04-20 06:41:43.000000000 +0000
+++ src/torrent/download/resource_manager.cc
@@ -38,8 +38,16 @@
 
 #include <algorithm>
 #include <functional>
-#include <tr1/functional>
 #include <limits>
+#if __cplusplus >= 201103L
+#include <functional>
+using std::bind;
+#define STD_PLACEHOLDERS std::placeholders
+#else
+#include <tr1/functional>
+using std::tr1::bind;
+#define STD_PLACEHOLDERS std::tr1::placeholders
+#endif
 #include <rak/functional.h>
 
 #include "torrent/exceptions.h"
@@ -51,8 +59,6 @@
 #include "choke_queue.h"
 #include "resource_manager.h"
 
-namespace tr1 { using namespace std::tr1; }
-
 namespace torrent {
 
 const Rate* resource_manager_entry::up_rate() const { return m_download->info()->up_rate(); }
@@ -73,12 +79,12 @@ ResourceManager::ResourceManager() :
   choke_base_type::back()->up_queue()->set_heuristics(choke_queue::HEURISTICS_UPLOAD_LEECH);
   choke_base_type::back()->down_queue()->set_heuristics(choke_queue::HEURISTICS_DOWNLOAD_LEECH);
 
-  choke_base_type::back()->up_queue()->set_slot_unchoke(tr1::bind(&ResourceManager::receive_upload_unchoke, this, tr1::placeholders::_1));
-  choke_base_type::back()->down_queue()->set_slot_unchoke(tr1::bind(&ResourceManager::receive_download_unchoke, this, tr1::placeholders::_1));
-  choke_base_type::back()->up_queue()->set_slot_can_unchoke(tr1::bind(&ResourceManager::retrieve_upload_can_unchoke, this));
-  choke_base_type::back()->down_queue()->set_slot_can_unchoke(tr1::bind(&ResourceManager::retrieve_download_can_unchoke, this));
-  choke_base_type::back()->up_queue()->set_slot_connection(tr1::bind(&PeerConnectionBase::receive_upload_choke, tr1::placeholders::_1, tr1::placeholders::_2));
-  choke_base_type::back()->down_queue()->set_slot_connection(tr1::bind(&PeerConnectionBase::receive_download_choke, tr1::placeholders::_1, tr1::placeholders::_2));
+  choke_base_type::back()->up_queue()->set_slot_unchoke(bind(&ResourceManager::receive_upload_unchoke, this, STD_PLACEHOLDERS::_1));
+  choke_base_type::back()->down_queue()->set_slot_unchoke(bind(&ResourceManager::receive_download_unchoke, this, STD_PLACEHOLDERS::_1));
+  choke_base_type::back()->up_queue()->set_slot_can_unchoke(bind(&ResourceManager::retrieve_upload_can_unchoke, this));
+  choke_base_type::back()->down_queue()->set_slot_can_unchoke(bind(&ResourceManager::retrieve_download_can_unchoke, this));
+  choke_base_type::back()->up_queue()->set_slot_connection(bind(&PeerConnectionBase::receive_upload_choke, STD_PLACEHOLDERS::_1, STD_PLACEHOLDERS::_2));
+  choke_base_type::back()->down_queue()->set_slot_connection(bind(&PeerConnectionBase::receive_download_choke, STD_PLACEHOLDERS::_1, STD_PLACEHOLDERS::_2));
 }
 
 ResourceManager::~ResourceManager() {
