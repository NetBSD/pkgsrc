$NetBSD: patch-src_core_download__factory.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/core/download_factory.cc.orig	2013-05-03 22:37:54.000000000 +0000
+++ src/core/download_factory.cc
@@ -41,7 +41,15 @@
 #include <sstream>
 #include <stdexcept>
 #include <rak/path.h>
+#if __cplusplus >= 201103L
+#include <functional>
+using std::bind;
+#define STD_PLACEHOLDERS std::placeholders
+#else
 #include <tr1/functional>
+using std::tr1::bind;
+#define STD_PLACEHOLDERS std::tr1::placeholders
+#endif
 #include <torrent/utils/log.h>
 #include <torrent/utils/resume.h>
 #include <torrent/object.h>
@@ -107,8 +115,8 @@ DownloadFactory::DownloadFactory(Manager
   m_printLog(true),
   m_isFile(false) {
 
-  m_taskLoad.slot() = std::tr1::bind(&DownloadFactory::receive_load, this);
-  m_taskCommit.slot() = std::tr1::bind(&DownloadFactory::receive_commit, this);
+  m_taskLoad.slot() = bind(&DownloadFactory::receive_load, this);
+  m_taskCommit.slot() = bind(&DownloadFactory::receive_commit, this);
 
   // m_variables["connection_leech"] = rpc::call_command_void("protocol.connection.leech");
   // m_variables["connection_seed"]  = rpc::call_command_void("protocol.connection.seed");
@@ -158,8 +166,8 @@ DownloadFactory::receive_load() {
     m_stream = new std::stringstream;
     HttpQueue::iterator itr = m_manager->http_queue()->insert(m_uri, m_stream);
 
-    (*itr)->signal_done().push_front(std::tr1::bind(&DownloadFactory::receive_loaded, this));
-    (*itr)->signal_failed().push_front(std::tr1::bind(&DownloadFactory::receive_failed, this, std::tr1::placeholders::_1));
+    (*itr)->signal_done().push_front(bind(&DownloadFactory::receive_loaded, this));
+    (*itr)->signal_failed().push_front(bind(&DownloadFactory::receive_failed, this, STD_PLACEHOLDERS::_1));
 
     m_variables["tied_to_file"] = (int64_t)false;
 
