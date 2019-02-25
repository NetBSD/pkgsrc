$NetBSD: patch-media_libcubeb_update.sh,v 1.1 2019/02/25 15:32:24 wiz Exp $

--- media/libcubeb/update.sh.orig	2018-05-03 16:58:30.000000000 +0000
+++ media/libcubeb/update.sh
@@ -20,6 +20,7 @@ cp $1/src/cubeb_log.h src
 cp $1/src/cubeb_mixer.cpp src
 cp $1/src/cubeb_mixer.h src
 cp $1/src/cubeb_opensl.c src
+cp $1/src/cubeb_oss.c src
 cp $1/src/cubeb-jni.cpp src
 cp $1/src/cubeb-jni.h src
 cp $1/src/android/cubeb-output-latency.h src/android
