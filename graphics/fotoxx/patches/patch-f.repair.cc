$NetBSD: patch-f.repair.cc,v 1.1 2013/10/20 18:07:43 joerg Exp $

--- f.repair.cc.orig	2013-10-18 21:25:06.000000000 +0000
+++ f.repair.cc
@@ -28,6 +28,8 @@
    Fotoxx image edit - Repair menu functions
 ***************************************************************************/
 
+int smart_erase_blur(float radius);
+void smart_erase_func(int mode);
 
 //  image sharpening function
 
@@ -1557,9 +1559,6 @@ void m_smart_erase(GtkWidget *, const ch
 
 int smart_erase_dialog_event(zdialog *zd, const char *event)               //  overhauled
 {
-   void smart_erase_func(int mode);
-   void smart_erase_blur(float radius);
-   
    float       radius;
    int         cc;
    
