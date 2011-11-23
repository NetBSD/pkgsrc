$NetBSD: patch-plug-ins_pdf_pdf.cpp,v 1.1 2011/11/23 23:30:30 joerg Exp $

--- plug-ins/pdf/pdf.cpp.orig	2011-11-23 17:14:05.000000000 +0000
+++ plug-ins/pdf/pdf.cpp
@@ -40,6 +40,8 @@
 #include "pdf.h"
 #include "pdf_dialog.h"
 
+#include <cstring>
+
 extern "C" {
 #include <gtk/gtk.h>
 #include "lib/plugin_main.h"
