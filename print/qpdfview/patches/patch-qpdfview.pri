$NetBSD: patch-qpdfview.pri,v 1.1 2013/01/03 13:38:55 ryoon Exp $

* Set install places

--- qpdfview.pri.orig	2012-12-29 16:48:33.000000000 +0000
+++ qpdfview.pri
@@ -1,4 +1,4 @@
-TARGET_INSTALL_PATH = /usr/bin
-DATA_INSTALL_PATH = /usr/share/qpdfview
-LAUNCHER_INSTALL_PATH = /usr/share/applications
-MANUAL_INSTALL_PATH = /usr/share/man/man1
+TARGET_INSTALL_PATH = @DESTDIR@@PREFIX@/bin
+DATA_INSTALL_PATH = @DESTDIR@@PREFIX@/share/qpdfview
+LAUNCHER_INSTALL_PATH = @DESTDIR@@PREFIX@/share/applications
+MANUAL_INSTALL_PATH = @DESTDIR@@PREFIX@/@PKGMANDIR@/man1
