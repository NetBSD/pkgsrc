$NetBSD: patch-src_extractors_taglibextractor.cpp,v 1.1 2024/01/28 18:41:53 wiz Exp $

Fix build with taglib 2.
https://github.com/KDE/kfilemetadata/commit/0d1606612aca206a122aa376045ec8871d50de59
https://github.com/KDE/kfilemetadata/commit/c9a90eedc975f469c35369b9ed9462bb4cb48f79

--- src/extractors/taglibextractor.cpp.orig	2023-07-01 09:57:07.000000000 +0000
+++ src/extractors/taglibextractor.cpp
@@ -34,6 +34,7 @@
 #include <id3v2tag.h>
 #include <mp4tag.h>
 #include <popularimeterframe.h>
+#include <attachedpictureframe.h>
 
 using namespace KFileMetaData;
 
@@ -578,8 +579,8 @@ void TagLibExtractor::extract(Extraction
             extractAudioProperties(&file, result);
             readGenericProperties(file.properties(), result);
             if (file.hasID3v2Tag()) {
-                result->addImageData(extractId3Cover(file.tag(), imageTypes));
-                extractId3Tags(file.tag(), result);
+                result->addImageData(extractId3Cover(file.ID3v2Tag(), imageTypes));
+                extractId3Tags(file.ID3v2Tag(), result);
             }
         }
     } else if (mimeType == QLatin1String("audio/x-musepack")) {
