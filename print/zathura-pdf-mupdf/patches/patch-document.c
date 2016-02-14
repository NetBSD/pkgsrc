$NetBSD: patch-document.c,v 1.1 2016/02/14 14:01:49 leot Exp $

Correct the glib-2.0 include header file path.

--- document.c.orig	2015-12-22 22:38:09.000000000 +0000
+++ document.c
@@ -6,7 +6,7 @@
 #include <mupdf/xps.h>
 #include <mupdf/pdf.h>
 
-#include <glib-2.0/glib.h>
+#include <glib.h>
 
 #include "plugin.h"
 
