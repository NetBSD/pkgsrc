$NetBSD: patch-libbase_GnashImageGif.cpp,v 1.1 2013/07/14 02:32:34 obache Exp $

* for giflib-5.0 API changes
  https://savannah.gnu.org/bugs/index.php?39482

--- libbase/GnashImageGif.cpp.orig	2012-01-19 19:17:48.000000000 +0000
+++ libbase/GnashImageGif.cpp
@@ -269,7 +269,11 @@ GifInput::processRecord(GifRecordType re
 void
 GifInput::read()
 {
+#if GIFLIB_MAJOR >= 5
+    _gif = DGifOpen(_inStream.get(), &readData, NULL); 
+#else
     _gif = DGifOpen(_inStream.get(), &readData); 
+#endif
 
     GifRecordType record;
 
