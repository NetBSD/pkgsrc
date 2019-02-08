$NetBSD: patch-src_accountmanagedlg.cpp,v 1.1 2019/02/08 14:56:01 nia Exp $

Fix missing include.

--- src/accountmanagedlg.cpp.orig	2019-02-08 13:44:45.092357357 +0000
+++ src/accountmanagedlg.cpp
@@ -28,6 +28,7 @@
 #include <QTimer>
 #include <QHeaderView>
 #include <QDropEvent>
+#include <QButtonGroup>
 
 #include "psicon.h"
 #include "psiaccount.h"
