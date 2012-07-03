$NetBSD: patch-amarok_src_metadata_rmff_rmff.h,v 1.1 2012/07/03 18:21:48 joerg Exp $

--- amarok/src/metadata/rmff/rmff.h.orig	2008-08-13 21:21:51.000000000 +0000
+++ amarok/src/metadata/rmff/rmff.h
@@ -35,6 +35,8 @@
 
 namespace TagLib
 {
+   class AudioProperties;
+
    namespace RealMedia
    {
 #if SIZEOF_LONG == 4
@@ -278,7 +280,6 @@ namespace TagLib
          TagLib::ID3v1::Tag *m_id3tag;
       };
       
-      class TagLib::AudioProperties;
       
       class RealMediaFF
       {
