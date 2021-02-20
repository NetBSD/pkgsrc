$NetBSD: patch-ext_libstrawberry-tagreader_tagreader.h,v 1.1 2021/02/20 11:02:41 wiz Exp $

Fix build with protobuf 3.15.0.
Based on https://github.com/strawberrymusicplayer/strawberry/issues/654

--- ext/libstrawberry-tagreader/tagreader.h.orig	2020-11-09 22:12:40.431554880 +0000
+++ ext/libstrawberry-tagreader/tagreader.h
@@ -51,10 +51,10 @@ class TagReader {
   ~TagReader();
 
   bool IsMediaFile(const QString &filename) const;
-  pb::tagreader::SongMetadata_FileType GuessFileType(TagLib::FileRef *fileref) const;
+  spb::tagreader::SongMetadata_FileType GuessFileType(TagLib::FileRef *fileref) const;
 
-  void ReadFile(const QString &filename, pb::tagreader::SongMetadata *song) const;
-  bool SaveFile(const QString &filename, const pb::tagreader::SongMetadata &song) const;
+  void ReadFile(const QString &filename, spb::tagreader::SongMetadata *song) const;
+  bool SaveFile(const QString &filename, const spb::tagreader::SongMetadata &song) const;
 
   QByteArray LoadEmbeddedArt(const QString &filename) const;
   QByteArray LoadEmbeddedAPEArt(const TagLib::APE::ItemListMap &map) const;
@@ -62,11 +62,11 @@ class TagReader {
   static void Decode(const TagLib::String &tag, std::string *output);
   static void Decode(const QString &tag, std::string *output);
 
-  void ParseOggTag(const TagLib::Ogg::FieldListMap &map, QString *disc, QString *compilation, pb::tagreader::SongMetadata *song) const;
-  void ParseAPETag(const TagLib::APE::ItemListMap &map, QString *disc, QString *compilation, pb::tagreader::SongMetadata *song) const;
+  void ParseOggTag(const TagLib::Ogg::FieldListMap &map, QString *disc, QString *compilation, spb::tagreader::SongMetadata *song) const;
+  void ParseAPETag(const TagLib::APE::ItemListMap &map, QString *disc, QString *compilation, spb::tagreader::SongMetadata *song) const;
 
-  void SetVorbisComments(TagLib::Ogg::XiphComment *vorbis_comments, const pb::tagreader::SongMetadata &song) const;
-  void SaveAPETag(TagLib::APE::Tag *tag, const pb::tagreader::SongMetadata &song) const;
+  void SetVorbisComments(TagLib::Ogg::XiphComment *vorbis_comments, const spb::tagreader::SongMetadata &song) const;
+  void SaveAPETag(TagLib::APE::Tag *tag, const spb::tagreader::SongMetadata &song) const;
 
   void SetTextFrame(const char *id, const QString &value, TagLib::ID3v2::Tag *tag) const;
   void SetTextFrame(const char *id, const std::string &value, TagLib::ID3v2::Tag *tag) const;
