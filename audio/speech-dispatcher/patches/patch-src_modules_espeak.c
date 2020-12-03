$NetBSD: patch-src_modules_espeak.c,v 1.3 2020/12/03 13:00:48 nia Exp $

Fix path to espeak header file

--- src/modules/espeak.c.orig	2020-09-28 13:31:15.000000000 +0000
+++ src/modules/espeak.c
@@ -39,7 +39,7 @@
 #ifdef ESPEAK_NG_INCLUDE
 #include <espeak-ng/espeak_ng.h>
 #else
-#include <espeak/speak_lib.h>
+#include <speak_lib.h>
 #endif
 
 #ifndef ESPEAK_API_REVISION
