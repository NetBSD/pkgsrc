$NetBSD: patch-src_calibre_headless_headless__integration.cpp,v 1.1 2019/09/24 16:39:51 kamil Exp $

Fix Qt 5.13 compat.
https://github.com/kovidgoyal/calibre/commit/0a5dc07da1cb0f9409803b4df1a92e497e3c0e95.patch

--- src/calibre/headless/headless_integration.cpp.orig	2019-03-08 06:09:34.000000000 +0000
+++ src/calibre/headless/headless_integration.cpp
@@ -58,7 +58,12 @@ HeadlessIntegration::HeadlessIntegration
     mPrimaryScreen->mDepth = 32;
     mPrimaryScreen->mFormat = QImage::Format_ARGB32_Premultiplied;
 
+#if (QT_VERSION >= QT_VERSION_CHECK(5, 13, 0))
+    QWindowSystemInterface::handleScreenAdded(mPrimaryScreen);
+#else
     screenAdded(mPrimaryScreen);
+#endif
+
 #ifdef __APPLE__
     m_fontDatabase.reset(new QCoreTextFontDatabase());
 #else
