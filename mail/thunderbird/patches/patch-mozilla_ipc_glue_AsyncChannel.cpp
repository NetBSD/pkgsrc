$NetBSD: patch-mozilla_ipc_glue_AsyncChannel.cpp,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/ipc/glue/AsyncChannel.cpp.orig	2013-10-23 22:09:00.000000000 +0000
+++ mozilla/ipc/glue/AsyncChannel.cpp
@@ -709,7 +709,7 @@ AsyncChannel::ProcessLink::OnChannelOpen
         mExistingListener = mTransport->set_listener(this);
 #ifdef DEBUG
         if (mExistingListener) {
-            queue<Message> pending;
+            std::queue<Message> pending;
             mExistingListener->GetQueuedMessages(pending);
             MOZ_ASSERT(pending.empty());
         }
@@ -726,7 +726,7 @@ AsyncChannel::ProcessLink::OnTakeConnect
 {
     AssertIOThread();
 
-    queue<Message> pending;
+    std::queue<Message> pending;
     {
         MonitorAutoLock lock(*mChan->mMonitor);
 
