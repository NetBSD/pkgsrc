$NetBSD: patch-src_core_view_TexImageView.cpp,v 1.1 2024/10/18 20:38:24 wiz Exp $

Compatibility with poppler 24.10.0.

--- src/core/view/TexImageView.cpp.orig	2024-10-18 20:36:17.087214090 +0000
+++ src/core/view/TexImageView.cpp
@@ -4,9 +4,7 @@
 
 #include <cairo.h>             // for cairo_paint_with_alpha, cairo_scale
 #include <glib.h>              // for g_warning
-#include <poppler-document.h>  // for poppler_document_get_n_pages, poppler_...
-#include <poppler-page.h>      // for poppler_page_render, poppler_page_get_...
-#include <poppler.h>           // for PopplerPage, PopplerDocument, g_clear_...
+#include <poppler.h>           // for poppler, poppler_...
 
 #include "model/TexImage.h"  // for TexImage
 #include "view/View.h"       // for Context, OPACITY_NO_AUDIO, view
