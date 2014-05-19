$NetBSD: patch-protocols_wlm_wlmchatsession.cpp,v 1.1 2014/05/19 11:07:25 markd Exp $

Fix build with giflib 5.1.

--- protocols/wlm/wlmchatsession.cpp.orig	2014-01-02 19:38:04.000000000 +0000
+++ protocols/wlm/wlmchatsession.cpp
@@ -557,7 +557,7 @@ WlmChatSession::convertToGif( const QPix
                 screenColourmap);
 
     if (status != GIF_OK) {
-        EGifCloseFile(GifFile);
+        EGifCloseFile(GifFile, NULL);
         return;
     }
 
@@ -580,11 +580,11 @@ WlmChatSession::convertToGif( const QPix
 
     if (status != GIF_OK) {
         printGifErrorMessage();
-        EGifCloseFile(GifFile);
+        EGifCloseFile(GifFile, NULL);
         return;
     }
 
-    if (EGifCloseFile(GifFile) != GIF_OK) {
+    if (EGifCloseFile(GifFile, NULL) != GIF_OK) {
         printGifErrorMessage();
         return;
     }
