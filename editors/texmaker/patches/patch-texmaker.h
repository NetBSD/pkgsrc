$NetBSD: patch-texmaker.h,v 1.2 2021/10/26 17:56:54 nros Exp $

* use pkgsrc (system) hunspell, from openbsd ports

--- texmaker.h.orig	2021-08-13 06:55:34.000000000 +0000
+++ texmaker.h
@@ -50,7 +50,7 @@
 #include "usertagslistwidget.h"
 #include "xmltagslistwidget.h"
 #include "logeditor.h"
-#include "hunspell/hunspell.hxx"
+#include <hunspell.hxx>
 #include "pdfviewerwidget.h"
 #include "pdfviewer.h"
 #include "sourceview.h"
