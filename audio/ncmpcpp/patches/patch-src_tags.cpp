$NetBSD: patch-src_tags.cpp,v 1.1 2024/02/01 07:13:37 wiz Exp $

Support taglib 2.
https://github.com/ncmpcpp/ncmpcpp/pull/590/commits/d7f487c648e05172aeb2c2d0899d2086160edaf1

--- src/tags.cpp.orig	2021-01-24 15:50:24.000000000 +0000
+++ src/tags.cpp
@@ -33,6 +33,7 @@
 #include <textidentificationframe.h>
 #include <commentsframe.h>
 #include <xiphcomment.h>
+#include <taglib/taglib.h>
 
 #include <boost/filesystem.hpp>
 #include "global.h"
@@ -122,12 +123,20 @@ void writeCommonTags(const MPD::MutableS
 	tag->setArtist(ToWString(s.getArtist()));
 	tag->setAlbum(ToWString(s.getAlbum()));
 	try {
+#if (TAGLIB_MAJOR_VERSION >= 2)
+		tag->setYear(boost::lexical_cast<unsigned int>(s.getDate()));
+#else
 		tag->setYear(boost::lexical_cast<TagLib::uint>(s.getDate()));
+#endif
 	} catch (boost::bad_lexical_cast &) {
 		std::cerr << "writeCommonTags: couldn't write 'year' tag to '" << s.getURI() << "' as it's not a positive integer\n";
 	}
 	try {
+#if (TAGLIB_MAJOR_VERSION >= 2)
+		tag->setTrack(boost::lexical_cast<unsigned int>(s.getTrack()));
+#else
 		tag->setTrack(boost::lexical_cast<TagLib::uint>(s.getTrack()));
+#endif
 	} catch (boost::bad_lexical_cast &) {
 		std::cerr << "writeCommonTags: couldn't write 'track' tag to '" << s.getURI() << "' as it's not a positive integer\n";
 	}
@@ -294,7 +303,11 @@ bool write(MPD::MutableSong &s)
 	{
 		writeID3v2Tags(s, mpeg_file->ID3v2Tag(true));
 		// write id3v2.4 tags only
+#if (TAGLIB_MAJOR_VERSION >= 2)
+		if (!mpeg_file->save(TagLib::MPEG::File::ID3v2, TagLib::File::StripNone, TagLib::ID3v2::Version::v4, TagLib::File::DuplicateTags::DoNotDuplicate))
+#else
 		if (!mpeg_file->save(TagLib::MPEG::File::ID3v2, true, 4, false))
+#endif
 			return false;
 		// do not call generic save() as it will duplicate tags
 		saved = true;
