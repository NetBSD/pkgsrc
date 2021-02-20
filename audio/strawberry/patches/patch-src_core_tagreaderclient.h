$NetBSD: patch-src_core_tagreaderclient.h,v 1.1 2021/02/20 11:02:41 wiz Exp $

Fix build with protobuf 3.15.0.
Based on https://github.com/strawberrymusicplayer/strawberry/issues/654

--- src/core/tagreaderclient.h.orig	2020-11-19 06:56:43.587995530 +0000
+++ src/core/tagreaderclient.h
@@ -44,7 +44,7 @@ class TagReaderClient : public QObject {
  public:
   explicit TagReaderClient(QObject *parent = nullptr);
 
-  typedef AbstractMessageHandler<pb::tagreader::Message> HandlerType;
+  typedef AbstractMessageHandler<spb::tagreader::Message> HandlerType;
   typedef HandlerType::ReplyType ReplyType;
 
   static const char *kWorkerExecutableName;
@@ -78,7 +78,7 @@ class TagReaderClient : public QObject {
   static TagReaderClient *sInstance;
 
   WorkerPool<HandlerType> *worker_pool_;
-  QList<pb::tagreader::Message> message_queue_;
+  QList<spb::tagreader::Message> message_queue_;
   QThread *original_thread_;
 };
 
