$NetBSD: patch-ext_strawberry-tagreader_tagreaderworker.cpp,v 1.1 2021/02/20 11:02:41 wiz Exp $

Fix build with protobuf 3.15.0.
Based on https://github.com/strawberrymusicplayer/strawberry/issues/654

--- ext/strawberry-tagreader/tagreaderworker.cpp.orig	2020-11-29 07:34:39.463138999 +0000
+++ ext/strawberry-tagreader/tagreaderworker.cpp
@@ -27,11 +27,11 @@
 #include "tagreaderworker.h"
 
 TagReaderWorker::TagReaderWorker(QIODevice *socket, QObject *parent)
-  : AbstractMessageHandler<pb::tagreader::Message>(socket, parent) {}
+  : AbstractMessageHandler<spb::tagreader::Message>(socket, parent) {}
 
-void TagReaderWorker::MessageArrived(const pb::tagreader::Message &message) {
+void TagReaderWorker::MessageArrived(const spb::tagreader::Message &message) {
 
-  pb::tagreader::Message reply;
+  spb::tagreader::Message reply;
 
   if (message.has_read_file_request()) {
     tag_reader_.ReadFile(QStringFromStdString(message.read_file_request().filename()), reply.mutable_read_file_response()->mutable_metadata());
@@ -54,7 +54,7 @@ void TagReaderWorker::MessageArrived(con
 
 
 void TagReaderWorker::DeviceClosed() {
-  AbstractMessageHandler<pb::tagreader::Message>::DeviceClosed();
+  AbstractMessageHandler<spb::tagreader::Message>::DeviceClosed();
 
   qApp->exit();
 }
