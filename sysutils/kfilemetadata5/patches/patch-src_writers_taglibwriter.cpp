$NetBSD: patch-src_writers_taglibwriter.cpp,v 1.1 2024/01/28 18:41:53 wiz Exp $

Fix build with taglib 2.
https://github.com/KDE/kfilemetadata/commit/0d1606612aca206a122aa376045ec8871d50de59
https://github.com/KDE/kfilemetadata/commit/c9a90eedc975f469c35369b9ed9462bb4cb48f79

--- src/writers/taglibwriter.cpp.orig	2023-07-01 09:57:07.000000000 +0000
+++ src/writers/taglibwriter.cpp
@@ -33,6 +33,7 @@
 #include <wavpackfile.h>
 #include <wavfile.h>
 #include <popularimeterframe.h>
+#include <attachedpictureframe.h>
 
 namespace {
 
@@ -552,7 +553,7 @@ void TagLibWriter::write(const WriteData
             auto savedProperties = file.properties();
             writeGenericProperties(savedProperties, properties);
             file.setProperties(savedProperties);
-            auto id3Tags = dynamic_cast<TagLib::ID3v2::Tag*>(file.tag());
+            auto id3Tags = file.ID3v2Tag();
             if (id3Tags) {
                 writeID3v2Tags(id3Tags, properties);
                 writeID3v2Cover(id3Tags, data.imageData());
