$NetBSD: patch-src_portaudio_pa__unix__oss.c,v 1.1 2014/09/25 12:29:35 jperkin Exp $

SunOS needs sys/soundcard.h

--- src/portaudio/pa_unix_oss.c.orig	2005-02-12 10:40:06.000000000 +0000
+++ src/portaudio/pa_unix_oss.c
@@ -43,6 +43,8 @@
 
 #ifdef __linux__
 #include <linux/soundcard.h>
+#elif defined(__sun)
+#include <sys/soundcard.h>
 #else
 #include <machine/soundcard.h> /* JH20010905 */
 #endif
