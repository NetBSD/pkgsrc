$NetBSD: patch-src_modules_espeak.c,v 1.2 2019/11/28 16:51:49 nia Exp $

Fix path to espeak header file

--- src/modules/espeak.c.orig	2019-01-01 17:32:54.000000000 +0000
+++ src/modules/espeak.c
@@ -35,7 +35,7 @@
 #include <semaphore.h>
 
 /* espeak header file */
-#include <espeak/speak_lib.h>
+#include <speak_lib.h>
 
 #ifndef ESPEAK_API_REVISION
 #define ESPEAK_API_REVISION 1
