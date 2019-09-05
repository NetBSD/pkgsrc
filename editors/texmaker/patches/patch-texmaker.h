$NetBSD: patch-texmaker.h,v 1.1 2019/09/05 08:07:25 nros Exp $
* use pkgsrc (system) hunspell, from openbsd ports
--- texmaker.h.orig	2019-09-03 13:27:59.000000000 +0000
+++ texmaker.h
@@ -1,3 +1,4 @@
+
 /***************************************************************************
  *   copyright       : (C) 2003-2017 by Pascal Brachet                     *
  *   http://www.xm1math.net/texmaker/                                      *
@@ -49,7 +50,7 @@
 #include "usertagslistwidget.h"
 #include "xmltagslistwidget.h"
 #include "logeditor.h"
-#include "hunspell/hunspell.hxx"
+#include <hunspell.hxx>
 #include "pdfviewerwidget.h"
 #include "pdfviewer.h"
 #include "sourceview.h"
