$NetBSD: patch-mediafiles.h,v 1.1 2024/02/01 09:50:00 wiz Exp $

Fix build with taglib2.
https://invent.kde.org/multimedia/juk/-/commit/5389ae860ca4c672c022cad7e51c48bc699fcba3

--- mediafiles.h.orig	2024-02-01 09:48:48.334649220 +0000
+++ mediafiles.h
@@ -28,8 +28,6 @@ namespace TagLib {
     class File;
 }
 
-#include <taglib_config.h>
-
 /**
  * A namespace for file JuK's file related functions.  The goal is to hide
  * all specific knowledge of mimetypes and file extensions here.
