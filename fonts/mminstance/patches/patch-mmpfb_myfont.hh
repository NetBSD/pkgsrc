$NetBSD: patch-mmpfb_myfont.hh,v 1.1 2013/04/30 22:19:28 joerg Exp $

--- mmpfb/myfont.hh.orig	2013-04-30 11:12:05.000000000 +0000
+++ mmpfb/myfont.hh
@@ -1,7 +1,9 @@
 #ifndef MYFONT_HH
 #define MYFONT_HH
 #include <efont/t1font.hh>
-class Efont::EfontMMSpace;
+namespace Efont {
+class EfontMMSpace;
+}
 class ErrorHandler;
 
 class MyFont: public Efont::Type1Font { public:
