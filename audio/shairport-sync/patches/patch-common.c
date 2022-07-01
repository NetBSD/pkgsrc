$NetBSD: patch-common.c,v 1.1 2022/07/01 18:36:28 nia Exp $

Add support for Sun/NetBSD audio.

--- common.c.orig	2020-12-01 12:16:11.000000000 +0000
+++ common.c
@@ -1465,6 +1465,9 @@ char *get_version_string() {
 #ifdef CONFIG_SNDIO
     strcat(version_string, "-sndio");
 #endif
+#ifdef CONFIG_SUN
+    strcat(version_string, "-sun");
+#endif
 #ifdef CONFIG_JACK
     strcat(version_string, "-jack");
 #endif
