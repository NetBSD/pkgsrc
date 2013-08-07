$NetBSD: patch-kopete_protocols_wlm_wlmchatsession.cpp,v 1.1 2013/08/07 10:17:59 markd Exp $

From: Raymond Wooninck <tittiatcoke@gmail.com>
Date: Sun, 17 Mar 2013 12:24:09 +0000
Subject: Enable building with giflib v5
X-Git-Tag: v4.10.80
X-Git-Url: http://quickgit.kde.org/?p=kopete.git&a=commitdiff&h=47ceec53aa5ee6b84a753fdbf735e44558513fe2
---
Enable building with giflib v5

REVIEW: 7066

svn path=/trunk/KDE/kdenetwork/kopete/; revision=1344846
---


--- kopete/protocols/wlm/wlmchatsession.cpp
+++ kopete/protocols/wlm/wlmchatsession.cpp
@@ -65,6 +65,10 @@
 #include "wlmchatsessioninkaction.h"
 #ifdef HAVE_GIFLIB
 #include <gif_lib.h>
+/* old giflib has no GIFLIB_MAJOR, define to avoid cpp warnings */
+#ifndef GIFLIB_MAJOR
+#define GIFLIB_MAJOR 4
+#endif
 #endif
 
 WlmChatSession::WlmChatSession (Kopete::Protocol * protocol,
@@ -467,11 +471,15 @@
 {
 #ifdef HAVE_GIFLIB
 #ifdef HAVE_GIF_ERROR_STRING // giflib 4.2.0+
+#if GIFLIB_MAJOR >= 5
+        fprintf(stderr, "GIF-LIB error (exact reporting not implemented)\n");
+#else
         const char * errorString = GifErrorString();
         if (errorString)
             fprintf(stderr, "GIF-LIB error: %s\n", errorString);
         else
             fprintf(stderr, "GIF-LIB undefined error: %d\n", GifError());
+#endif
 #else // older giflib versions, libungif
         PrintGifError();
 #endif // HAVE_GIF_ERROR_STRING
@@ -483,6 +491,10 @@
 WlmChatSession::convertToGif( const QPixmap & ink, QString filename)
 {
 #ifdef HAVE_GIFLIB
+#if GIFLIB_MAJOR >= 5
+#define FreeMapObject  GifFreeMapObject
+#define MakeMapObject  GifMakeMapObject
+#endif
     int i, status;
     GifFileType *GifFile;
     ColorMapObject *screenColourmap;
@@ -525,7 +537,11 @@
         }
     }
 
+#if GIFLIB_MAJOR >= 5
+    GifFile= EGifOpenFileName(QFile::encodeName(filename).constData(), 0, NULL);
+#else
     GifFile= EGifOpenFileName(QFile::encodeName(filename).constData(), 0);
+#endif
     if (!GifFile) {
         FreeMapObject(imageColourmap);
         FreeMapObject(screenColourmap);

