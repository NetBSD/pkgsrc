$NetBSD: patch-OMXThread.cpp,v 1.1 2015/11/13 15:12:15 skrll Exp $

--- OMXThread.cpp.orig	2015-01-12 15:10:50.000000000 +0000
+++ OMXThread.cpp
@@ -41,8 +41,8 @@
 OMXThread::OMXThread()
 {
   pthread_mutex_init(&m_lock, NULL);
-  pthread_attr_setdetachstate(&m_tattr, PTHREAD_CREATE_JOINABLE);
   pthread_attr_init(&m_tattr);
+  pthread_attr_setdetachstate(&m_tattr, PTHREAD_CREATE_JOINABLE);
   m_thread    = 0;
   m_bStop     = false;
   m_running   = false;
