$NetBSD: patch-f.repair.cc,v 1.3 2016/01/03 04:33:50 ryoon Exp $

--- f.repair.cc.orig	2016-01-01 08:20:29.000000000 +0000
+++ f.repair.cc
@@ -51,6 +51,8 @@
 
 /********************************************************************************/
 
+void smart_erase_func(int mode);
+int smart_erase_blur(float radius);
 
 //  image sharpen functions
 
@@ -2234,9 +2236,6 @@ void m_smart_erase(GtkWidget *, const ch
 
 int smart_erase_dialog_event(zdialog *zd, const char *event)                     //  overhauled
 {
-   void smart_erase_func(int mode);
-   void smart_erase_blur(float radius);
-
    float       radius;
    int         cc;
 
