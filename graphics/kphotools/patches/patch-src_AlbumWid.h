$NetBSD: patch-src_AlbumWid.h,v 1.1 2011/11/25 21:58:42 joerg Exp $

--- src/AlbumWid.h.orig	2011-11-25 19:16:22.000000000 +0000
+++ src/AlbumWid.h
@@ -15,7 +15,7 @@
 #include <qwidget.h>
 #include <qdir.h>
 #include <qfiledialog.h>
-#include <vector.h>
+#include <vector>
 #include <qwmatrix.h>
 #include <qtabwidget.h>
 #include <qcheckbox.h>
