$NetBSD: patch-config.h,v 1.1.1.1 2014/12/12 22:05:04 agc Exp $

point to the right directory

--- config.h	2014/12/12 21:39:48	1.1
+++ config.h	2014/12/12 21:42:20
@@ -4,8 +4,8 @@
 #define FFMPEG_CONFIGURATION "--disable-asm --enable-small --disable-pthreads --disable-everything --enable-decoder=hevc --enable-demuxer=hevc --enable-protocol=file --disable-ffserver --disable-ffprobe --disable-doc --enable-parser=hevc"
 #define FFMPEG_LICENSE "LGPL version 2.1 or later"
 #define CONFIG_THIS_YEAR 2014
-#define FFMPEG_DATADIR "/usr/local/share/ffmpeg"
-#define AVCONV_DATADIR "/usr/local/share/ffmpeg"
+#define FFMPEG_DATADIR "@PREFIX@/share/ffmpeg"
+#define AVCONV_DATADIR "@PREFIX@/share/ffmpeg"
 #define CC_IDENT "gcc 4.7.2 (GCC) 20120921 (Red Hat 4.7.2-2)"
 #define av_restrict restrict
 #define EXTERN_PREFIX ""
