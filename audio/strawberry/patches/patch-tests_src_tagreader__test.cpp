$NetBSD: patch-tests_src_tagreader__test.cpp,v 1.1 2021/02/20 11:02:41 wiz Exp $

Fix build with protobuf 3.15.0.
Based on https://github.com/strawberrymusicplayer/strawberry/issues/654

--- tests/src/tagreader_test.cpp.orig	2020-11-29 07:34:39.479138921 +0000
+++ tests/src/tagreader_test.cpp
@@ -44,7 +44,7 @@ class TagReaderTest : public ::testing::
   static Song ReadSongFromFile(const QString& filename) {
     TagReader tag_reader;
     Song song;
-    ::pb::tagreader::SongMetadata pb_song;
+    ::spb::tagreader::SongMetadata pb_song;
 
     // We need to init protobuf object from a Song object, to have default values initialized correctly.
     song.ToProtobuf(&pb_song);
@@ -55,7 +55,7 @@ class TagReaderTest : public ::testing::
 
   static void WriteSongToFile(const Song& song, const QString& filename) {
     TagReader tag_reader;
-    ::pb::tagreader::SongMetadata pb_song;
+    ::spb::tagreader::SongMetadata pb_song;
     song.ToProtobuf(&pb_song);
     tag_reader.SaveFile(filename, pb_song);
   }
