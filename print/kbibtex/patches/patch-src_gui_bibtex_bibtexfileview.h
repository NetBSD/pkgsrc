$NetBSD: patch-src_gui_bibtex_bibtexfileview.h,v 1.1 2012/03/26 09:15:04 markd Exp $

--- src/gui/bibtex/bibtexfileview.h.orig	2011-11-20 20:36:54.000000000 +0000
+++ src/gui/bibtex/bibtexfileview.h
@@ -21,6 +21,7 @@
 #define KBIBTEX_GUI_BIBTEXFILEVIEW_H
 
 #include <QTreeView>
+#include <KSharedConfig>
 
 #include <kbibtexgui_export.h>
 
