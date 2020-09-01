$NetBSD: patch-src_validator.c,v 1.1 2020/09/01 10:21:55 schmonz Exp $

From OpenBSD ports, add pledge() support.

--- src/validator.c.orig	Thu Jan  1 00:00:00 1970
+++ src/validator.c
@@ -28,6 +28,9 @@
 
 #include <locale.h>
 
+#ifdef HAVE_PLEDGE
+#include <unistd.h>
+#endif
 #include "validate.h"
 
 static gboolean   warn_kde = FALSE;
@@ -50,6 +53,13 @@ main (int argc, char *argv[])
   GError         *error;
   int i;
   gboolean all_valid;
+
+#ifdef HAVE_PLEDGE
+  if (pledge ("stdio rpath", NULL) == -1) {
+    g_printerr ("pledge\n");
+    return 1;
+  }
+#endif
 
   setlocale (LC_ALL, "");
 
