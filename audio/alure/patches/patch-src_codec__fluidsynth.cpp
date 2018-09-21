$NetBSD: patch-src_codec__fluidsynth.cpp,v 1.1 2018/09/21 13:24:34 maya Exp $

http://repo.or.cz/alure.git/patch/38e56406f47ee1322464e67b8fea8822856af61b

--- src/codec_fluidsynth.cpp.orig	2011-07-29 08:37:48.000000000 +0000
+++ src/codec_fluidsynth.cpp
@@ -29,6 +29,8 @@
 #include <assert.h>
 #ifdef _WIN32
 #include <io.h>
+#else
+#include <unistd.h>
 #endif
 
 #include <istream>
