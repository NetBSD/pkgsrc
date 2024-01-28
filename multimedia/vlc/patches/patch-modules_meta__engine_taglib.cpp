$NetBSD: patch-modules_meta__engine_taglib.cpp,v 1.1 2024/01/28 22:40:44 wiz Exp $

Fix build with taglib 2. From arch.
https://gitlab.archlinux.org/archlinux/packaging/packages/vlc/-/blob/40b8a8a1fc24f594a0b828fbde521c644964efaf/taglib-2.patch

--- modules/meta_engine/taglib.cpp.orig	2023-04-22 23:27:28.000000000 +0000
+++ modules/meta_engine/taglib.cpp
@@ -185,7 +185,7 @@ public:
         ByteVector res(length, 0);
         ssize_t i_read = vlc_stream_Read( m_stream, res.data(), length);
         if (i_read < 0)
-            return ByteVector::null;
+            return ByteVector();
         else if ((size_t)i_read != length)
             res.resize(i_read);
         return res;
@@ -465,7 +465,7 @@ static void ReadMetaFromASF( ASF::Tag* t
 static void ReadMetaFromBasicTag(const Tag* tag, vlc_meta_t *dest)
 {
 #define SET( accessor, meta )                                                  \
-    if( !tag->accessor().isNull() && !tag->accessor().isEmpty() )              \
+    if( !tag->accessor().isEmpty() )              \
         vlc_meta_Set##meta( dest, tag->accessor().toCString(true) )
 #define SETINT( accessor, meta )                                               \
     if( tag->accessor() )                                                      \
@@ -806,15 +806,15 @@ static void ReadMetaFromMP4( MP4::Tag* t
 {
     MP4::Item list;
 #define SET( keyName, metaName )                                                             \
-    if( tag->itemListMap().contains(keyName) )                                               \
+    if( tag->itemMap().contains(keyName) )                                               \
     {                                                                                        \
-        list = tag->itemListMap()[keyName];                                                  \
+        list = tag->itemMap()[keyName];                                                  \
         vlc_meta_Set##metaName( p_meta, list.toStringList().front().toCString( true ) );     \
     }
 #define SET_EXTRA( keyName, metaName )                                                   \
-    if( tag->itemListMap().contains(keyName) )                                  \
+    if( tag->itemMap().contains(keyName) )                                  \
     {                                                                                \
-        list = tag->itemListMap()[keyName];                                     \
+        list = tag->itemMap()[keyName];                                     \
         vlc_meta_AddExtra( p_meta, metaName, list.toStringList().front().toCString( true ) ); \
     }
 
@@ -824,9 +824,9 @@ static void ReadMetaFromMP4( MP4::Tag* t
 #undef SET
 #undef SET_EXTRA
 
-    if( tag->itemListMap().contains("covr") )
+    if( tag->itemMap().contains("covr") )
     {
-        MP4::CoverArtList list = tag->itemListMap()["covr"].toCoverArtList();
+        MP4::CoverArtList list = tag->itemMap()["covr"].toCoverArtList();
         const char *psz_format = list[0].format() == MP4::CoverArt::PNG ? "image/png" : "image/jpeg";
 
         msg_Dbg( p_demux_meta, "Found embedded art (%s) is %i bytes",
@@ -1337,7 +1337,7 @@ static int WriteMeta( vlc_object_t *p_th
         if( RIFF::AIFF::File* riff_aiff = dynamic_cast<RIFF::AIFF::File*>(f.file()) )
             WriteMetaToId3v2( riff_aiff->tag(), p_item );
         else if( RIFF::WAV::File* riff_wav = dynamic_cast<RIFF::WAV::File*>(f.file()) )
-            WriteMetaToId3v2( riff_wav->tag(), p_item );
+            WriteMetaToId3v2( riff_wav->ID3v2Tag(), p_item );
     }
     else if( TrueAudio::File* trueaudio = dynamic_cast<TrueAudio::File*>(f.file()) )
     {
