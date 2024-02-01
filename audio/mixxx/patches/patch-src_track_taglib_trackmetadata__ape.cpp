$NetBSD: patch-src_track_taglib_trackmetadata__ape.cpp,v 1.1 2024/02/01 08:33:30 wiz Exp $

Fix build with taglib 2.
https://gitlab.archlinux.org/archlinux/packaging/packages/mixxx/-/blob/main/taglib-2.patch?ref_type=heads

--- src/track/taglib/trackmetadata_ape.cpp.orig	2024-02-01 08:27:27.916407263 +0000
+++ src/track/taglib/trackmetadata_ape.cpp
@@ -58,7 +58,7 @@ bool importCoverImageFromTag(QImage* pCo
     if (tag.itemListMap().contains("COVER ART (FRONT)")) {
         const TagLib::ByteVector nullStringTerminator(1, 0);
         TagLib::ByteVector item =
-                tag.itemListMap()["COVER ART (FRONT)"].value();
+                tag.itemListMap()["COVER ART (FRONT)"].binaryData();
         int pos = item.find(nullStringTerminator); // skip the filename
         if (++pos > 0) {
             const TagLib::ByteVector data(item.mid(pos));
