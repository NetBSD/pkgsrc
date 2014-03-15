$NetBSD: patch-f.repair.cc,v 1.2 2014/03/15 05:37:03 ryoon Exp $

--- f.repair.cc.orig	2014-03-05 07:17:10.000000000 +0000
+++ f.repair.cc
@@ -28,6 +28,8 @@
    Fotoxx image edit - Repair menu functions
 ***************************************************************************/
 
+int smart_erase_blur(float radius);
+void smart_erase_func(int mode);
 
 //  image sharpen functions
 
@@ -1593,9 +1595,6 @@ void m_smart_erase(GtkWidget *, const ch
 
 int smart_erase_dialog_event(zdialog *zd, const char *event)               //  overhauled
 {
-   void smart_erase_func(int mode);
-   void smart_erase_blur(float radius);
-   
    float       radius;
    int         cc;
    
