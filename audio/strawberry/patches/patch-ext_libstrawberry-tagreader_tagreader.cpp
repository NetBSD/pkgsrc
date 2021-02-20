$NetBSD: patch-ext_libstrawberry-tagreader_tagreader.cpp,v 1.1 2021/02/20 11:02:41 wiz Exp $

Fix build with protobuf 3.15.0.
Based on https://github.com/strawberrymusicplayer/strawberry/issues/654

--- ext/libstrawberry-tagreader/tagreader.cpp.orig	2020-11-29 07:35:15.638962593 +0000
+++ ext/libstrawberry-tagreader/tagreader.cpp
@@ -146,34 +146,34 @@ bool TagReader::IsMediaFile(const QStrin
 
 }
 
-pb::tagreader::SongMetadata_FileType TagReader::GuessFileType(TagLib::FileRef *fileref) const {
+spb::tagreader::SongMetadata_FileType TagReader::GuessFileType(TagLib::FileRef *fileref) const {
 
-  if (dynamic_cast<TagLib::RIFF::WAV::File*>(fileref->file())) return pb::tagreader::SongMetadata_FileType_WAV;
-  if (dynamic_cast<TagLib::FLAC::File*>(fileref->file())) return pb::tagreader::SongMetadata_FileType_FLAC;
-  if (dynamic_cast<TagLib::WavPack::File*>(fileref->file())) return pb::tagreader::SongMetadata_FileType_WAVPACK;
-  if (dynamic_cast<TagLib::Ogg::FLAC::File*>(fileref->file())) return pb::tagreader::SongMetadata_FileType_OGGFLAC;
-  if (dynamic_cast<TagLib::Ogg::Vorbis::File*>(fileref->file())) return pb::tagreader::SongMetadata_FileType_OGGVORBIS;
-  if (dynamic_cast<TagLib::Ogg::Opus::File*>(fileref->file())) return pb::tagreader::SongMetadata_FileType_OGGOPUS;
-  if (dynamic_cast<TagLib::Ogg::Speex::File*>(fileref->file())) return pb::tagreader::SongMetadata_FileType_OGGSPEEX;
-  if (dynamic_cast<TagLib::MPEG::File*>(fileref->file())) return pb::tagreader::SongMetadata_FileType_MPEG;
-  if (dynamic_cast<TagLib::MP4::File*>(fileref->file())) return pb::tagreader::SongMetadata_FileType_MP4;
-  if (dynamic_cast<TagLib::ASF::File*>(fileref->file())) return pb::tagreader::SongMetadata_FileType_ASF;
-  if (dynamic_cast<TagLib::RIFF::AIFF::File*>(fileref->file())) return pb::tagreader::SongMetadata_FileType_AIFF;
-  if (dynamic_cast<TagLib::MPC::File*>(fileref->file())) return pb::tagreader::SongMetadata_FileType_MPC;
-  if (dynamic_cast<TagLib::TrueAudio::File*>(fileref->file())) return pb::tagreader::SongMetadata_FileType_TRUEAUDIO;
-  if (dynamic_cast<TagLib::APE::File*>(fileref->file())) return pb::tagreader::SongMetadata_FileType_APE;
+  if (dynamic_cast<TagLib::RIFF::WAV::File*>(fileref->file())) return spb::tagreader::SongMetadata_FileType_WAV;
+  if (dynamic_cast<TagLib::FLAC::File*>(fileref->file())) return spb::tagreader::SongMetadata_FileType_FLAC;
+  if (dynamic_cast<TagLib::WavPack::File*>(fileref->file())) return spb::tagreader::SongMetadata_FileType_WAVPACK;
+  if (dynamic_cast<TagLib::Ogg::FLAC::File*>(fileref->file())) return spb::tagreader::SongMetadata_FileType_OGGFLAC;
+  if (dynamic_cast<TagLib::Ogg::Vorbis::File*>(fileref->file())) return spb::tagreader::SongMetadata_FileType_OGGVORBIS;
+  if (dynamic_cast<TagLib::Ogg::Opus::File*>(fileref->file())) return spb::tagreader::SongMetadata_FileType_OGGOPUS;
+  if (dynamic_cast<TagLib::Ogg::Speex::File*>(fileref->file())) return spb::tagreader::SongMetadata_FileType_OGGSPEEX;
+  if (dynamic_cast<TagLib::MPEG::File*>(fileref->file())) return spb::tagreader::SongMetadata_FileType_MPEG;
+  if (dynamic_cast<TagLib::MP4::File*>(fileref->file())) return spb::tagreader::SongMetadata_FileType_MP4;
+  if (dynamic_cast<TagLib::ASF::File*>(fileref->file())) return spb::tagreader::SongMetadata_FileType_ASF;
+  if (dynamic_cast<TagLib::RIFF::AIFF::File*>(fileref->file())) return spb::tagreader::SongMetadata_FileType_AIFF;
+  if (dynamic_cast<TagLib::MPC::File*>(fileref->file())) return spb::tagreader::SongMetadata_FileType_MPC;
+  if (dynamic_cast<TagLib::TrueAudio::File*>(fileref->file())) return spb::tagreader::SongMetadata_FileType_TRUEAUDIO;
+  if (dynamic_cast<TagLib::APE::File*>(fileref->file())) return spb::tagreader::SongMetadata_FileType_APE;
 #ifdef HAVE_TAGLIB_DSFFILE
-  if (dynamic_cast<TagLib::DSF::File*>(fileref->file())) return pb::tagreader::SongMetadata_FileType_DSF;
+  if (dynamic_cast<TagLib::DSF::File*>(fileref->file())) return spb::tagreader::SongMetadata_FileType_DSF;
 #endif
 #ifdef HAVE_TAGLIB_DSDIFFFILE
-  if (dynamic_cast<TagLib::DSDIFF::File*>(fileref->file())) return pb::tagreader::SongMetadata_FileType_DSDIFF;
+  if (dynamic_cast<TagLib::DSDIFF::File*>(fileref->file())) return spb::tagreader::SongMetadata_FileType_DSDIFF;
 #endif
 
-  return pb::tagreader::SongMetadata_FileType_UNKNOWN;
+  return spb::tagreader::SongMetadata_FileType_UNKNOWN;
 
 }
 
-void TagReader::ReadFile(const QString &filename, pb::tagreader::SongMetadata *song) const {
+void TagReader::ReadFile(const QString &filename, spb::tagreader::SongMetadata *song) const {
 
   const QByteArray url(QUrl::fromLocalFile(filename).toEncoded());
   const QFileInfo info(filename);
@@ -435,7 +435,7 @@ void TagReader::Decode(const QString &ta
 
 }
 
-void TagReader::ParseOggTag(const TagLib::Ogg::FieldListMap &map, QString *disc, QString *compilation, pb::tagreader::SongMetadata *song) const {
+void TagReader::ParseOggTag(const TagLib::Ogg::FieldListMap &map, QString *disc, QString *compilation, spb::tagreader::SongMetadata *song) const {
 
   if (!map["COMPOSER"].isEmpty()) Decode(map["COMPOSER"].front(), song->mutable_composer());
   if (!map["PERFORMER"].isEmpty()) Decode(map["PERFORMER"].front(), song->mutable_performer());
@@ -459,7 +459,7 @@ void TagReader::ParseOggTag(const TagLib
 
 }
 
-void TagReader::ParseAPETag(const TagLib::APE::ItemListMap &map, QString *disc, QString *compilation, pb::tagreader::SongMetadata *song) const {
+void TagReader::ParseAPETag(const TagLib::APE::ItemListMap &map, QString *disc, QString *compilation, spb::tagreader::SongMetadata *song) const {
 
   TagLib::APE::ItemListMap::ConstIterator it = map.find("ALBUM ARTIST");
   if (it != map.end()) {
@@ -503,7 +503,7 @@ void TagReader::ParseAPETag(const TagLib
 
 }
 
-void TagReader::SetVorbisComments(TagLib::Ogg::XiphComment *vorbis_comments, const pb::tagreader::SongMetadata &song) const {
+void TagReader::SetVorbisComments(TagLib::Ogg::XiphComment *vorbis_comments, const spb::tagreader::SongMetadata &song) const {
 
   vorbis_comments->addField("COMPOSER", StdStringToTaglibString(song.composer()), true);
   vorbis_comments->addField("PERFORMER", StdStringToTaglibString(song.performer()), true);
@@ -521,7 +521,7 @@ void TagReader::SetVorbisComments(TagLib
 
 }
 
-bool TagReader::SaveFile(const QString &filename, const pb::tagreader::SongMetadata &song) const {
+bool TagReader::SaveFile(const QString &filename, const spb::tagreader::SongMetadata &song) const {
 
   if (filename.isEmpty()) return false;
 
@@ -602,7 +602,7 @@ bool TagReader::SaveFile(const QString &
   return result;
 }
 
-void TagReader::SaveAPETag(TagLib::APE::Tag *tag, const pb::tagreader::SongMetadata &song) const {
+void TagReader::SaveAPETag(TagLib::APE::Tag *tag, const spb::tagreader::SongMetadata &song) const {
 
   tag->setItem("album artist", TagLib::APE::Item("album artist", TagLib::StringList(song.albumartist().c_str())));
   tag->addValue("disc", QStringToTaglibString(song.disc() <= 0 ? QString() : QString::number(song.disc())), true);
