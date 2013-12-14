$NetBSD: patch-gst_gstdatetime.c,v 1.1 2013/12/14 17:11:22 joerg Exp $

--- gst/gstdatetime.c.orig	2013-12-13 11:16:38.000000000 +0000
+++ gst/gstdatetime.c
@@ -21,8 +21,8 @@
 #include "config.h"
 #endif
 
-#include "glib-compat-private.h"
 #include "gst_private.h"
+#include "glib-compat-private.h"
 #include "gstdatetime.h"
 #include "gstvalue.h"
 #include <glib.h>
