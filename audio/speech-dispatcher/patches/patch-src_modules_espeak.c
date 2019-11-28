$NetBSD: patch-src_modules_espeak.c,v 1.1 2019/11/28 16:18:54 nia Exp $

Fix path to espeak header file

--- src/modules/espeak.c.orig	2016-04-17 22:05:32.000000000 +0000
+++ src/modules/espeak.c
@@ -37,7 +37,7 @@
 #include <semaphore.h>
 
 /* espeak header file */
-#include <espeak/speak_lib.h>
+#include <speak_lib.h>
 #ifndef ESPEAK_API_REVISION
 #define ESPEAK_API_REVISION 1
 #endif
