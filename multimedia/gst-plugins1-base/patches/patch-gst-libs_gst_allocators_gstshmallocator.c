$NetBSD: patch-gst-libs_gst_allocators_gstshmallocator.c,v 1.1 2024/03/11 09:13:41 jperkin Exp $

Include sys/stat.h for S_*.

--- gst-libs/gst/allocators/gstshmallocator.c.orig	2024-03-11 09:02:38.876091503 +0000
+++ gst-libs/gst/allocators/gstshmallocator.c
@@ -44,6 +44,7 @@
 #include "config.h"
 #endif
 
+#include <sys/stat.h>
 #include "gstshmallocator.h"
 
 #ifdef HAVE_MMAP
