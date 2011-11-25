$NetBSD: patch-src_f4lmdoc.cpp,v 1.1 2011/11/25 21:56:47 joerg Exp $

--- src/f4lmdoc.cpp.orig	2011-11-25 17:34:16.000000000 +0000
+++ src/f4lmdoc.cpp
@@ -21,7 +21,7 @@
 #include <qwidget.h>
 #include <qmessagebox.h>
 #include <qfiledialog.h>
-#include <iostream.h>
+#include <iostream>
 #include <qfiledialog.h>
 #include <qprocess.h> // reading ttf files
 #include <qimage.h>
