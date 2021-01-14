$NetBSD: patch-operations_external_tiff-load.c,v 1.1 2021/01/14 10:16:30 jperkin Exp $

Fix SunOS flags.

--- operations/external/tiff-load.c.orig	2020-08-02 20:23:44.962150300 +0000
+++ operations/external/tiff-load.c
@@ -18,7 +18,9 @@
 
 #include "config.h"
 #ifdef HAVE_STRPTIME
+#  ifndef __sun
 #define _XOPEN_SOURCE
+#  endif
 #include <time.h>
 #endif
 #include <glib/gi18n-lib.h>
