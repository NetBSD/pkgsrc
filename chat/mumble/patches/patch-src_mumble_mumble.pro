$NetBSD: patch-src_mumble_mumble.pro,v 1.2 2019/09/16 22:46:21 nia Exp $

Add the OSS library, if any.

--- src/mumble/mumble.pro.orig	2019-09-07 19:44:58.000000000 +0000
+++ src/mumble/mumble.pro
@@ -572,6 +572,7 @@ oss {
   HEADERS *= OSS.h
   SOURCES *= OSS.cpp
   INCLUDEPATH *= /usr/lib/oss/include
+  LIBS += @LIBOSSAUDIO@
 }
 
 pulseaudio {
