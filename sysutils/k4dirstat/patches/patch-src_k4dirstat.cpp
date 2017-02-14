$NetBSD: patch-src_k4dirstat.cpp,v 1.1 2017/02/14 21:24:49 joerg Exp $

--- src/k4dirstat.cpp.orig	2017-02-09 18:05:02.833187514 +0000
+++ src/k4dirstat.cpp
@@ -45,6 +45,8 @@
 #include <Qt/qmenu.h>
 #include <Qt/qsplitter.h>
 
+#include <unistd.h>
+
 #include "kdirtree.h"
 #include "kpacman.h"
 #include "ktreemapview.h"
