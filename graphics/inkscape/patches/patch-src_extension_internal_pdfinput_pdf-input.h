$NetBSD: patch-src_extension_internal_pdfinput_pdf-input.h,v 1.1 2019/01/06 08:41:01 markd Exp $

support for poppler 0.72 from upstream by way of linuxfromscratch 

--- src/extension/internal/pdfinput/pdf-input.h.orig	2018-03-11 20:38:09.000000000 +0000
+++ src/extension/internal/pdfinput/pdf-input.h
@@ -15,6 +15,7 @@
 #endif
 
 #ifdef HAVE_POPPLER
+#include "poppler-transition-api.h"
 
 #include <gtkmm/dialog.h>
 
