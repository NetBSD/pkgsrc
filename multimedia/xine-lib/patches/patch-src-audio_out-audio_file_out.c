$NetBSD: patch-src-audio_out-audio_file_out.c,v 1.1 2011/11/20 11:43:37 marino Exp $

--- src/audio_out/audio_file_out.c.orig	2011-10-04 21:42:53.000000000 +0000
+++ src/audio_out/audio_file_out.c
@@ -30,6 +30,7 @@
 #include <math.h>
 #include <unistd.h>
 #include <inttypes.h>
+#include <sys/stat.h>
 
 #include "xine_internal.h"
 #include "xineutils.h"
