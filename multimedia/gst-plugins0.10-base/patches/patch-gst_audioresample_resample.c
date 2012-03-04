$NetBSD: patch-gst_audioresample_resample.c,v 1.1 2012/03/04 11:19:07 obache Exp $

* fix build on i386 without SSE/SSE2 support.
https://bugzilla.gnome.org/show_bug.cgi?id=670690

--- gst/audioresample/resample.c.orig	2011-12-30 13:29:15.000000000 +0000
+++ gst/audioresample/resample.c
@@ -77,13 +77,13 @@
 #define EXPORT G_GNUC_INTERNAL
 
 #ifdef _USE_SSE
-#ifndef HAVE_XMMINTRIN_H
+#ifndef __SSE__
 #undef _USE_SSE
 #endif
 #endif
 
 #ifdef _USE_SSE2
-#ifndef HAVE_EMMINTRIN_H
+#ifndef __SSE2__
 #undef _USE_SSE2
 #endif
 #endif
