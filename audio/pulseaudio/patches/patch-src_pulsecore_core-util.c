$NetBSD: patch-src_pulsecore_core-util.c,v 1.1 2015/09/25 14:37:27 ryoon Exp $

--- src/pulsecore/core-util.c.orig	2015-09-15 04:46:06.000000000 +0000
+++ src/pulsecore/core-util.c
@@ -54,7 +54,9 @@
 
 #ifdef HAVE_STRTOD_L
 #include <locale.h>
+#  if !defined(__NetBSD__)
 #include <xlocale.h>
+#  endif
 #endif
 
 #ifdef HAVE_SCHED_H
