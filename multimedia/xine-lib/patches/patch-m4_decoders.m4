$NetBSD: patch-m4_decoders.m4,v 1.1 2026/01/03 14:10:39 nia Exp $

Fix shell portability.

--- m4/decoders.m4.orig	2026-01-03 11:56:26.446210809 +0000
+++ m4/decoders.m4
@@ -147,14 +147,14 @@ a52_init ();
 #include <libavutil/avutil.h>
 #include <libavcodec/avcodec.h>
             ]],[[]])], [have_avutil_avcodec_h=yes], [have_avutil_avcodec_h=no])
-            test x"$have_avutil_avcodec_h" == x"yes" && AC_DEFINE([HAVE_AVUTIL_AVCODEC_H],[1],
+            test x"$have_avutil_avcodec_h" = x"yes" && AC_DEFINE([HAVE_AVUTIL_AVCODEC_H],[1],
                 [Define this if you have libavutil/avutil.h and libavcodec/avcodec.h.])
             AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
 #include <libavutil/avutil.h>
 #include <libavcodec/avcodec.h>
 #include <libavformat/avformat.h>
             ]],[[]])], [have_avformat_avformat_h=yes], [have_avformat_avformat_h=no])
-            test x"$have_avformat_avformat_h" == x"yes" && AC_DEFINE([HAVE_AVFORMAT_AVFORMAT_H],[1],
+            test x"$have_avformat_avformat_h" = x"yes" && AC_DEFINE([HAVE_AVFORMAT_AVFORMAT_H],[1],
                 [Define this if you have libavformat/avformat.h.])
             AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[
 #include <libavutil/avutil.h>
@@ -162,7 +162,7 @@ a52_init ();
 #include <libavformat/avformat.h>
 #include <libavformat/avio.h>
             ]],[[]])], [have_avformat_avio_h=yes], [have_avformat_avio_h=no])
-            test x"$have_avformat_avio_h" == x"yes" && AC_DEFINE([HAVE_AVFORMAT_AVIO_H],[1],
+            test x"$have_avformat_avio_h" = x"yes" && AC_DEFINE([HAVE_AVFORMAT_AVIO_H],[1],
                 [Define this if you have libavformat/avformat.h.])
             if test "$ac_cv_header_ffmpeg_avutil_h" = "yes" && test "$ac_cv_header_libavutil_avutil_h" = "yes"; then
                 AC_MSG_ERROR([old & new ffmpeg headers found - you need to clean up!])
