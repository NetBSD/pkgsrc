$NetBSD: patch-mediafiles.cpp,v 1.1 2024/02/01 09:49:59 wiz Exp $

Fix build with taglib2.
https://invent.kde.org/multimedia/juk/-/commit/5389ae860ca4c672c022cad7e51c48bc699fcba3

--- mediafiles.cpp.orig	2024-02-01 09:48:43.998930162 +0000
+++ mediafiles.cpp
@@ -29,7 +29,6 @@
 #include <QMimeDatabase>
 
 #include <taglib.h>
-#include <taglib_config.h>
 #include <tag.h>
 #include <mpegfile.h>
 #include <vorbisfile.h>
