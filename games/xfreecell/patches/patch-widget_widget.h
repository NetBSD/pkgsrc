$NetBSD: patch-widget_widget.h,v 1.1 2018/02/19 09:51:48 he Exp $

--- widget/widget.h.orig	1999-03-15 16:29:32.000000000 +0000
+++ widget/widget.h
@@ -8,6 +8,8 @@
 #include <vector>
 #include <string>
 
+using namespace std;
+
 const char defaultFont[] = "7x14";
 
 extern Display* NSdpy;
@@ -31,7 +33,7 @@ class NSFrame;
 class NSScrollbarListener;
 class NSVScrollbar;
 
-unsigned long allocColor(Display*, unsigned int R, unsigned int G, unsigned int B);
+unsigned long allocColor(Display*, short unsigned int R, short unsigned int G, short unsigned int B);
 unsigned long nameToPixel(const char* colorName);
 void NSInitialize();
 void NSMainLoop();
@@ -42,6 +44,7 @@ Display* NSdisplay();
 // ##### NSComponent #####
 class NSComponent {
 public:
+  virtual ~NSComponent() {};
   virtual int x() const = 0;
   virtual int y() const = 0;
   virtual unsigned int width() const = 0;
