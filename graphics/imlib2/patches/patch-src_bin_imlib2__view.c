$NetBSD: patch-src_bin_imlib2__view.c,v 1.2 2024/04/27 03:05:38 schmonz Exp $

Include sys/time.h for timeval.

--- src/bin/imlib2_view.c.orig	2024-02-03 15:58:21.000000000 +0000
+++ src/bin/imlib2_view.c
@@ -3,6 +3,7 @@
 
 #include <X11/Xlib.h>
 #include <X11/keysym.h>
+#include <sys/time.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
