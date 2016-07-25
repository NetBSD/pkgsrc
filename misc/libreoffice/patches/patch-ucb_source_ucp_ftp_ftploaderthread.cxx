$NetBSD: patch-ucb_source_ucp_ftp_ftploaderthread.cxx,v 1.1 2016/07/25 13:11:17 wiz Exp $

Add cast to fix build with curl-7.50.

--- ucb/source/ucp/ftp/ftploaderthread.cxx.orig	2016-06-14 20:05:10.000000000 +0000
+++ ucb/source/ucp/ftp/ftploaderthread.cxx
@@ -79,7 +79,7 @@ FTPLoaderThread::~FTPLoaderThread() {
 
 
 CURL* FTPLoaderThread::handle() {
-    CURL* ret = osl_getThreadKeyData(m_threadKey);
+    CURL* ret = static_cast<CURL*>(osl_getThreadKeyData(m_threadKey));
     if(!ret) {
         ret = curl_easy_init();
         if (ret != nullptr) {
