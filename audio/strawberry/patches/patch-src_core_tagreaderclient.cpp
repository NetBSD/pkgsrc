$NetBSD: patch-src_core_tagreaderclient.cpp,v 1.1 2021/02/20 11:02:41 wiz Exp $

Fix build with protobuf 3.15.0.
Based on https://github.com/strawberrymusicplayer/strawberry/issues/654

--- src/core/tagreaderclient.cpp.orig	2020-11-21 08:32:20.599784703 +0000
+++ src/core/tagreaderclient.cpp
@@ -71,8 +71,8 @@ void TagReaderClient::WorkerFailedToStar
 
 TagReaderReply *TagReaderClient::ReadFile(const QString &filename) {
 
-  pb::tagreader::Message message;
-  pb::tagreader::ReadFileRequest *req = message.mutable_read_file_request();
+  spb::tagreader::Message message;
+  spb::tagreader::ReadFileRequest *req = message.mutable_read_file_request();
 
   req->set_filename(DataCommaSizeFromQString(filename));
 
@@ -82,8 +82,8 @@ TagReaderReply *TagReaderClient::ReadFil
 
 TagReaderReply *TagReaderClient::SaveFile(const QString &filename, const Song &metadata) {
 
-  pb::tagreader::Message message;
-  pb::tagreader::SaveFileRequest *req = message.mutable_save_file_request();
+  spb::tagreader::Message message;
+  spb::tagreader::SaveFileRequest *req = message.mutable_save_file_request();
 
   req->set_filename(DataCommaSizeFromQString(filename));
   metadata.ToProtobuf(req->mutable_metadata());
@@ -96,8 +96,8 @@ TagReaderReply *TagReaderClient::SaveFil
 
 TagReaderReply *TagReaderClient::IsMediaFile(const QString &filename) {
 
-  pb::tagreader::Message message;
-  pb::tagreader::IsMediaFileRequest *req = message.mutable_is_media_file_request();
+  spb::tagreader::Message message;
+  spb::tagreader::IsMediaFileRequest *req = message.mutable_is_media_file_request();
 
   req->set_filename(DataCommaSizeFromQString(filename));
 
@@ -107,8 +107,8 @@ TagReaderReply *TagReaderClient::IsMedia
 
 TagReaderReply *TagReaderClient::LoadEmbeddedArt(const QString &filename) {
 
-  pb::tagreader::Message message;
-  pb::tagreader::LoadEmbeddedArtRequest *req = message.mutable_load_embedded_art_request();
+  spb::tagreader::Message message;
+  spb::tagreader::LoadEmbeddedArtRequest *req = message.mutable_load_embedded_art_request();
 
   req->set_filename(DataCommaSizeFromQString(filename));
 
