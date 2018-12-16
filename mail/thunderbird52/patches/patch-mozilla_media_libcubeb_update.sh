$NetBSD: patch-mozilla_media_libcubeb_update.sh,v 1.1 2018/12/16 08:29:48 ryoon Exp $

--- mozilla/media/libcubeb/update.sh.orig	2017-04-14 04:53:18.000000000 +0000
+++ mozilla/media/libcubeb/update.sh
@@ -17,6 +17,7 @@ cp $1/src/cubeb_audiounit.cpp src
 cp $1/src/cubeb_osx_run_loop.h src
 cp $1/src/cubeb_jack.cpp src
 cp $1/src/cubeb_opensl.c src
+cp $1/src/cubeb_oss.c src
 cp $1/src/cubeb_panner.cpp src
 cp $1/src/cubeb_panner.h src
 cp $1/src/cubeb_pulse.c src
