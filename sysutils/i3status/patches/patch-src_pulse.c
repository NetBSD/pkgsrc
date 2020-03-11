$NetBSD: patch-src_pulse.c,v 1.1 2020/03/11 22:46:36 nia Exp $

The makefile forgets to conditionally build this file even
when pulseaudio isn't available. Hack around this.

--- src/pulse.c.orig	2019-01-23 08:03:56.000000000 +0000
+++ src/pulse.c
@@ -1,3 +1,4 @@
+#if defined(__linux__)
 // vim:ts=4:sw=4:expandtab
 #include <config.h>
 #include <string.h>
@@ -337,3 +338,4 @@ bool pulse_initialize(void) {
     }
     return true;
 }
+#endif
