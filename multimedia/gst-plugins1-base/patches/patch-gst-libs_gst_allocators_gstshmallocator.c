$NetBSD: patch-gst-libs_gst_allocators_gstshmallocator.c,v 1.2 2024/03/11 09:37:10 wiz Exp $

Include sys/stat.h for S_*.
https://gitlab.freedesktop.org/gstreamer/gstreamer/-/issues/3370

--- gst-libs/gst/allocators/gstshmallocator.c.orig	2024-03-11 09:02:38.876091503 +0000
+++ gst-libs/gst/allocators/gstshmallocator.c
@@ -44,6 +44,7 @@
 #include "config.h"
 #endif
 
+#include <sys/stat.h>
 #include "gstshmallocator.h"
 
 #ifdef HAVE_MMAP
