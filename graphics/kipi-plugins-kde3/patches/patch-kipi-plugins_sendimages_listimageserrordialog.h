$NetBSD: patch-kipi-plugins_sendimages_listimageserrordialog.h,v 1.1 2013/03/28 21:43:08 joerg Exp $

--- kipi-plugins/sendimages/listimageserrordialog.h.orig	2013-03-27 16:40:27.000000000 +0000
+++ kipi-plugins/sendimages/listimageserrordialog.h
@@ -28,7 +28,6 @@
 #include <kdialogbase.h>
 
 class KListView;
-class KURL::List;
 
 namespace KIPISendimagesPlugin
 {
