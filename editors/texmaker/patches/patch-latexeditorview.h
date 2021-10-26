$NetBSD: patch-latexeditorview.h,v 1.2 2021/10/26 17:56:54 nros Exp $

* use pkgsrc (system) hunspell, from openbsd ports

--- latexeditorview.h.orig	2019-09-03 13:22:35.000000000 +0000
+++ latexeditorview.h
@@ -23,7 +23,7 @@
 #include "gotolinewidget.h"
 #include "replacewidget.h"
 #include "minisplitter.h"
-#include "hunspell/hunspell.hxx"
+#include <hunspell.hxx>
 
 class LatexEditorView : public QWidget  {
    Q_OBJECT
