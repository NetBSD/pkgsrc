$NetBSD: patch-tests_src_gui_testqgsexternalresourcewidgetwrapper.cpp,v 1.2 2022/02/15 12:59:21 gdt Exp $

Fix a test that should have been guarded on WITH_QTWEKBIT.

Not yet reported upstream.

--- tests/src/gui/testqgsexternalresourcewidgetwrapper.cpp.orig	2022-01-14 12:06:34.000000000 +0000
+++ tests/src/gui/testqgsexternalresourcewidgetwrapper.cpp
@@ -1258,7 +1258,9 @@ void TestQgsExternalResourceWidgetWrappe
 
   // content still null, fetching in progress...
   QVERIFY( !ww.mQgsWidget->mPixmapLabel->isVisible() );
+#ifdef WITH_QTWEBKIT
   QVERIFY( !ww.mQgsWidget->mWebView->isVisible() );
+#endif
   QVERIFY( ww.mQgsWidget->mLoadingLabel->isVisible() );
   QVERIFY( ww.mQgsWidget->mLoadingMovie->state() == QMovie::Running );
   QVERIFY( !ww.mQgsWidget->mErrorLabel->isVisible() );
