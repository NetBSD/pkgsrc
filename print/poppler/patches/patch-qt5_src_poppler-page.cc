$NetBSD: patch-qt5_src_poppler-page.cc,v 1.1 2019/10/20 03:12:22 markd Exp $

conditionalise defining splash related class

--- qt5/src/poppler-page.cc.orig	2019-09-22 15:56:22.000000000 +0000
+++ qt5/src/poppler-page.cc
@@ -103,6 +103,7 @@ public:
   QVariant payload;
 };
 
+#if defined(HAVE_SPLASH)
 class Qt5SplashOutputDev : public SplashOutputDev, public OutputDevCallbackHelper
 {
 public:
@@ -169,6 +170,7 @@ public:
 private:
   bool ignorePaperColor;
 };
+#endif
 
 
 class QImageDumpingArthurOutputDev : public ArthurOutputDev, public OutputDevCallbackHelper
