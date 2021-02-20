$NetBSD: patch-src_core_song.cpp,v 1.1 2021/02/20 11:02:41 wiz Exp $

Fix build with protobuf 3.15.0.
Based on https://github.com/strawberrymusicplayer/strawberry/issues/654

--- src/core/song.cpp.orig	2020-12-12 17:21:46.352815979 +0000
+++ src/core/song.cpp
@@ -744,7 +744,7 @@ void Song::set_genre_id3(int id) {
   set_genre(TStringToQString(TagLib::ID3v1::genre(id)));
 }
 
-void Song::InitFromProtobuf(const pb::tagreader::SongMetadata &pb) {
+void Song::InitFromProtobuf(const spb::tagreader::SongMetadata &pb) {
 
   if (d->source_ == Source_Unknown) d->source_ = Source_LocalFile;
 
@@ -791,7 +791,7 @@ void Song::InitFromProtobuf(const pb::ta
 
 }
 
-void Song::ToProtobuf(pb::tagreader::SongMetadata *pb) const {
+void Song::ToProtobuf(spb::tagreader::SongMetadata *pb) const {
 
   const QByteArray url(d->url_.toEncoded());
   const QByteArray art_automatic(d->art_automatic_.toEncoded());
@@ -826,7 +826,7 @@ void Song::ToProtobuf(pb::tagreader::Son
   pb->set_filesize(d->filesize_);
   pb->set_suspicious_tags(d->suspicious_tags_);
   pb->set_art_automatic(art_automatic.constData(), art_automatic.size());
-  pb->set_filetype(static_cast<pb::tagreader::SongMetadata_FileType>(d->filetype_));
+  pb->set_filetype(static_cast<spb::tagreader::SongMetadata_FileType>(d->filetype_));
 
 }
 
