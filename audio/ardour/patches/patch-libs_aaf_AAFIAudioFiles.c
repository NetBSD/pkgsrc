$NetBSD: patch-libs_aaf_AAFIAudioFiles.c,v 1.1 2024/03/18 15:36:15 ryoon Exp $

--- libs/aaf/AAFIAudioFiles.c.orig	2024-02-04 02:23:25.222620443 +0000
+++ libs/aaf/AAFIAudioFiles.c
@@ -50,6 +50,8 @@
 #ifndef _MSC_VER
 #include <unistd.h> // access()
 #endif
+#else
+#include <unistd.h> // access()
 #endif
 
 #define WAV_FILE_EXT "wav"
