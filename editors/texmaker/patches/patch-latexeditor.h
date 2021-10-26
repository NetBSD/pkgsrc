$NetBSD: patch-latexeditor.h,v 1.2 2021/10/26 17:56:54 nros Exp $

use pkgsrc (system) hunspell , from openbsd ports

--- latexeditor.h.orig	2019-09-03 13:21:25.000000000 +0000
+++ latexeditor.h
@@ -35,7 +35,7 @@
 
 #include "latexhighlighter.h"
 #include "textblockselection.h"
-#include "hunspell/hunspell.hxx"
+#include <hunspell.hxx>
 
 typedef  int UserBookmarkList[3];
 
