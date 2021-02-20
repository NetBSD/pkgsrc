$NetBSD: patch-src_core_song.h,v 1.1 2021/02/20 11:02:41 wiz Exp $

Fix build with protobuf 3.15.0.
Based on https://github.com/strawberrymusicplayer/strawberry/issues/654

--- src/core/song.h.orig	2020-12-12 17:21:46.352815979 +0000
+++ src/core/song.h
@@ -44,11 +44,11 @@ namespace Engine {
 struct SimpleMetaBundle;
 }  // namespace Engine
 
-namespace pb {
+namespace spb {
 namespace tagreader {
 class SongMetadata;
 }  // namespace tagreader
-}  // namespace pb
+}  // namespace spb
 
 #ifdef HAVE_LIBGPOD
 struct _Itdb_Track;
@@ -155,7 +155,7 @@ class Song {
   // Constructors
   void Init(const QString &title, const QString &artist, const QString &album, qint64 length_nanosec);
   void Init(const QString &title, const QString &artist, const QString &album, qint64 beginning, qint64 end);
-  void InitFromProtobuf(const pb::tagreader::SongMetadata &pb);
+  void InitFromProtobuf(const spb::tagreader::SongMetadata &pb);
   void InitFromQuery(const SqlRow &query, bool reliable_metadata, int col = 0);
   void InitFromFilePartial(const QString &filename);  // Just store the filename: incomplete but fast
   void InitArtManual();  // Check if there is already a art in the cache and store the filename in art_manual
@@ -180,7 +180,7 @@ class Song {
   void BindToQuery(QSqlQuery *query) const;
   void BindToFtsQuery(QSqlQuery *query) const;
   void ToXesam(QVariantMap *map) const;
-  void ToProtobuf(pb::tagreader::SongMetadata *pb) const;
+  void ToProtobuf(spb::tagreader::SongMetadata *pb) const;
 
   // Simple accessors
   bool is_valid() const;
