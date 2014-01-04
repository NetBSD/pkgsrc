$NetBSD: patch-src_FileRenamerDlgImpl.h,v 1.2 2014/01/04 15:11:43 wiz Exp $

http://sourceforge.net/p/mp3diags/code/279/

--- src/FileRenamerDlgImpl.h.orig	2009-10-20 16:15:39.000000000 +0200
+++ src/FileRenamerDlgImpl.h	2012-01-02 11:33:04.351881930 +0100
@@ -33,6 +33,9 @@
 
 #include  "ui_FileRenamer.h"
 
+#ifdef ERR
+#undef ERR
+#endif
 
 class CommonData;
 class QSettings;
