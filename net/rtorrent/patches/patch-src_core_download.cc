$NetBSD: patch-src_core_download.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/core/download.cc.orig	2013-05-03 22:45:22.000000000 +0000
+++ src/core/download.cc
@@ -53,6 +53,16 @@
 #include "download.h"
 #include "manager.h"
 
+#if __cplusplus >= 201103L
+#include <functional>
+using std::bind;
+#define STD_PLACEHOLDERS std::placeholders
+#else
+#include <tr1/functional>
+using std::tr1::bind;
+#define STD_PLACEHOLDERS std::tr1::placeholders
+#endif
+
 namespace core {
 
 Download::Download(download_type d) :
@@ -63,10 +73,10 @@ Download::Download(download_type d) :
   m_resumeFlags(~uint32_t()),
   m_group(0) {
 
-  m_download.info()->signal_tracker_success().push_back(tr1::bind(&Download::receive_tracker_msg, this, ""));
-  m_download.info()->signal_tracker_failed().push_back(tr1::bind(&Download::receive_tracker_msg, this, tr1::placeholders::_1));
-  m_download.info()->signal_storage_error().push_back(tr1::bind(&Download::receive_storage_error, this, tr1::placeholders::_1));
-  m_download.info()->signal_chunk_failed().push_back(tr1::bind(&Download::receive_chunk_failed, this, tr1::placeholders::_1));
+  m_download.info()->signal_tracker_success().push_back(bind(&Download::receive_tracker_msg, this, ""));
+  m_download.info()->signal_tracker_failed().push_back(bind(&Download::receive_tracker_msg, this, STD_PLACEHOLDERS::_1));
+  m_download.info()->signal_storage_error().push_back(bind(&Download::receive_storage_error, this, STD_PLACEHOLDERS::_1));
+  m_download.info()->signal_chunk_failed().push_back(bind(&Download::receive_chunk_failed, this, STD_PLACEHOLDERS::_1));
 }
 
 Download::~Download() {
