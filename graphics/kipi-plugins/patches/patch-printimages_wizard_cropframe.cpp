$NetBSD: patch-printimages_wizard_cropframe.cpp,v 1.1 2013/03/02 18:08:48 joerg Exp $

--- printimages/wizard/cropframe.cpp.orig	2013-02-28 12:07:37.000000000 +0000
+++ printimages/wizard/cropframe.cpp
@@ -41,7 +41,7 @@
 namespace KIPIPrintImagesPlugin
 {
 
-CropFrame::CropFrame(QWidget* parent=0)
+CropFrame::CropFrame(QWidget* parent)
     : QWidget(parent)
 {
     m_mouseDown = false;
