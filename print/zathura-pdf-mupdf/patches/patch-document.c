$NetBSD: patch-document.c,v 1.6 2026/03/02 13:31:38 yhardy Exp $

Correct the glib-2.0 include header file path.

--- zathura-pdf-mupdf/document.c.orig	2026-03-02 08:48:22.436471952 +0000
+++ zathura-pdf-mupdf/document.c
@@ -3,7 +3,7 @@
 #include <mupdf/fitz.h>
 #include <mupdf/pdf.h>
 
-#include <glib-2.0/glib.h>
+#include <glib.h>
 
 #include "plugin.h"
 #include <girara/utils.h>
