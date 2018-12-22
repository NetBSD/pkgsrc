$NetBSD: patch-src_mumble_mumble.pro,v 1.1 2018/12/22 18:17:39 nia Exp $

Always use the builtin version of celt to avoid API incompatibilities.

Use ${LIBOSSAUDIO}.

Find speech-dispatcher's include directory with pkgconf.

--- src/mumble/mumble.pro.orig	2017-01-27 06:48:33.000000000 +0000
+++ src/mumble/mumble.pro
@@ -67,15 +67,7 @@ CONFIG(sbcelt) {
   LIBS *= -lcelt -lsbcelt
   DEFINES *= SBCELT_PREFIX_API SBCELT_COMPAT_API USE_SBCELT
 } else {
-  unix:!CONFIG(bundled-celt):system(pkg-config --atleast-version=0.7.0 celt) {
-    CONFIG	*= no-bundled-celt
-  }
-  CONFIG(no-bundled-celt) {
-    INCLUDEPATH	*= /usr/include/celt
-  }
-  !CONFIG(no-bundled-celt) {
-    INCLUDEPATH	*= ../../celt-0.7.0-src/libcelt
-  }
+  INCLUDEPATH *= ../../celt-0.7.0-src/libcelt
 }
 
 !win32 {
@@ -240,6 +232,7 @@ oss {
 	HEADERS *= OSS.h
 	SOURCES *= OSS.cpp
 	INCLUDEPATH *= /usr/lib/oss/include
+	LIBS *= "$$LIBOSSAUDIO"
 }
 
 pulseaudio {
@@ -292,6 +285,7 @@ dbus {
 
 speechd {
 	DEFINES *= USE_SPEECHD
+	PKGCONFIG *= speech-dispatcher
 	LIBS *= -lspeechd
 }
 
