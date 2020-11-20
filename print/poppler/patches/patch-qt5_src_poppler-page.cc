$NetBSD: patch-qt5_src_poppler-page.cc,v 1.2 2020/11/20 19:08:05 wiz Exp $

conditionalise defining splash related class

--- qt5/src/poppler-page.cc.orig	2020-11-01 18:32:52.000000000 +0000
+++ qt5/src/poppler-page.cc
@@ -105,6 +105,7 @@ public:
     QVariant payload;
 };
 
+#if defined(HAVE_SPLASH)
 class Qt5SplashOutputDev : public SplashOutputDev, public OutputDevCallbackHelper
 {
 public:
@@ -165,6 +166,7 @@ public:
 private:
     bool ignorePaperColor;
 };
+#endif
 
 Qt5SplashOutputDev::~Qt5SplashOutputDev() = default;
 
