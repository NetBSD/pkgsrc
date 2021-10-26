$NetBSD: patch-latexhighlighter.h,v 1.2 2021/10/26 17:56:54 nros Exp $

* use pkgsrc (system) hunspell, from openbsd ports

--- latexhighlighter.h.orig	2019-09-03 13:23:28.000000000 +0000
+++ latexhighlighter.h
@@ -20,7 +20,7 @@
 #include <QColor>
 #include <QTextBlockUserData>
 //#include "latexeditor.h"
-#include "hunspell/hunspell.hxx"
+#include <hunspell.hxx>
 
 class QTextDocument;
 class LatexEditor;
