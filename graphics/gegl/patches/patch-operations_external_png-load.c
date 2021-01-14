$NetBSD: patch-operations_external_png-load.c,v 1.1 2021/01/14 10:16:30 jperkin Exp $

Fix SunOS flags.

--- operations/external/png-load.c.orig	2020-08-02 20:23:44.958153000 +0000
+++ operations/external/png-load.c
@@ -20,7 +20,9 @@
 
 #include "config.h"
 #ifdef HAVE_STRPTIME
+#  ifndef __sun
 #define _XOPEN_SOURCE
+#  endif
 #include <time.h>
 #endif
 #include <glib/gi18n-lib.h>
