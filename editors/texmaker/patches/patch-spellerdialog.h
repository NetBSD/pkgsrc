$NetBSD: patch-spellerdialog.h,v 1.2 2021/10/26 17:56:54 nros Exp $

* use pkgsrc (system) hunspell, from openbsd ports

--- spellerdialog.h.orig	2019-09-03 13:24:33.000000000 +0000
+++ spellerdialog.h
@@ -13,7 +13,7 @@
 
 #include "ui_spellerdialog.h"
 #include "latexeditor.h"
-#include "hunspell/hunspell.hxx"
+#include <hunspell.hxx>
 
 #include <QTextCursor>
 
