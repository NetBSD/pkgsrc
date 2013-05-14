$NetBSD: patch-lib_cpp_src_server_TNonblockingServer.cpp,v 1.1 2013/05/14 19:15:36 joerg Exp $

--- lib/cpp/src/server/TNonblockingServer.cpp.orig	2013-05-03 22:07:25.000000000 +0000
+++ lib/cpp/src/server/TNonblockingServer.cpp
@@ -846,7 +846,11 @@ void TNonblockingServer::registerEvents(
 void TNonblockingServer::setThreadManager(boost::shared_ptr<ThreadManager> threadManager) {
   threadManager_ = threadManager;
   if (threadManager != NULL) {
+#if __cplusplus >= 201103L
+    threadManager->setExpireCallback(std::bind(&TNonblockingServer::expireClose, this, std::placeholders::_1));
+#else
     threadManager->setExpireCallback(std::tr1::bind(&TNonblockingServer::expireClose, this, std::tr1::placeholders::_1));
+#endif
     threadPoolProcessing_ = true;
   } else {
     threadPoolProcessing_ = false;
