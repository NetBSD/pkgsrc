$NetBSD: patch-ext_strawberry-tagreader_tagreaderworker.h,v 1.1 2021/02/20 11:02:41 wiz Exp $

Fix build with protobuf 3.15.0.
Based on https://github.com/strawberrymusicplayer/strawberry/issues/654

--- ext/strawberry-tagreader/tagreaderworker.h.orig	2020-11-29 07:34:39.463138999 +0000
+++ ext/strawberry-tagreader/tagreaderworker.h
@@ -28,12 +28,12 @@
 
 class QIODevice;
 
-class TagReaderWorker : public AbstractMessageHandler<pb::tagreader::Message> {
+class TagReaderWorker : public AbstractMessageHandler<spb::tagreader::Message> {
  public:
   explicit TagReaderWorker(QIODevice *socket, QObject *parent = nullptr);
 
  protected:
-  void MessageArrived(const pb::tagreader::Message &message) override;
+  void MessageArrived(const spb::tagreader::Message &message) override;
   void DeviceClosed() override;
 
  private:
