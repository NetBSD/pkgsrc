--- qt/src/xmlpatterns/api/qcoloroutput_p.h.orig	2020-04-11 03:48:03.891503085 +0200
+++ qt/src/xmlpatterns/api/qcoloroutput_p.h	2020-04-11 03:56:49.652502308 +0200
@@ -69,10 +69,10 @@
         {
             ForegroundShift = 10,
             BackgroundShift = 20,
             SpecialShift    = 20,
-            ForegroundMask  = ((1 << ForegroundShift) - 1) << ForegroundShift,
-            BackgroundMask  = ((1 << BackgroundShift) - 1) << BackgroundShift
+            ForegroundMask  = 0x000ffc00,
+            BackgroundMask  = 0x3ff00000
         };
 
     public:
         enum ColorCodeComponent
