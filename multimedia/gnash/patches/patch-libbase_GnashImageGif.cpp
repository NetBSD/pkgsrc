$NetBSD: patch-libbase_GnashImageGif.cpp,v 1.3 2014/05/16 12:15:55 obache Exp $

* for giflib-5.0 API changes
  https://savannah.gnu.org/bugs/index.php?39482
* for giflib-5.1 API changes

--- libbase/GnashImageGif.cpp.orig	2012-01-19 19:17:48.000000000 +0000
+++ libbase/GnashImageGif.cpp
@@ -121,7 +121,13 @@ GifInput::GifInput(boost::shared_ptr<IOC
 GifInput::~GifInput()
 {
     // Clean up allocated data.
-    DGifCloseFile(_gif);
+#if (GIFLIB_MAJOR + 0) == 5 && (GIFLIB_MINOR + 0) >= 1 || (GIFLIB_MAJOR + 0) > 5
+    DGifCloseFile(_gif, NULL);
+#else
+    if (DGifCloseFile(_gif) != GIF_OK) {
+        free(_gif);
+    }
+#endif
 }
 
 size_t
@@ -269,7 +275,11 @@ GifInput::processRecord(GifRecordType re
 void
 GifInput::read()
 {
+#if (GIFLIB_MAJOR + 0) >= 5
+    _gif = DGifOpen(_inStream.get(), &readData, NULL); 
+#else
     _gif = DGifOpen(_inStream.get(), &readData); 
+#endif
 
     GifRecordType record;
 
