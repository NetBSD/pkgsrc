$NetBSD: patch-src_FileRenamerDlgImpl.h,v 1.1 2012/01/11 19:25:08 hans Exp $

--- src/FileRenamerDlgImpl.h.orig	2009-10-20 16:15:39.000000000 +0200
+++ src/FileRenamerDlgImpl.h	2012-01-02 11:33:04.351881930 +0100
@@ -33,6 +33,9 @@
 
 #include  "ui_FileRenamer.h"
 
+#ifdef ERR
+#undef ERR
+#endif
 
 class CommonData;
 class QSettings;
