$NetBSD: patch-tests_src_gui_testqgsexternalresourcewidgetwrapper.cpp,v 1.1 2022/01/18 23:33:59 gdt Exp $

Fix a  test that should have been guarded based on qt5-webkit.

Reported upstream via email 20210118.

--- tests/src/gui/testqgsexternalresourcewidgetwrapper.cpp.orig	2022-01-14 12:06:23.000000000 +0000
+++ tests/src/gui/testqgsexternalresourcewidgetwrapper.cpp
@@ -44,7 +44,9 @@ class TestQgsExternalResourceWidgetWrapp
     void init();// will be called before each testfunction is executed.
     void cleanup();// will be called after every testfunction.
     void test_setNullValues();
+#ifdef WITH_QTWEBKIT
     void testBlankAfterValue();
+#endif /* WITH_QTWEBKIT */
 
   private:
     std::unique_ptr<QgsVectorLayer> vl;
@@ -115,6 +117,8 @@ void TestQgsExternalResourceWidgetWrappe
   delete widget;
 }
 
+#ifdef WITH_QTWEBKIT
+
 void TestQgsExternalResourceWidgetWrapper::testBlankAfterValue()
 {
   // test that application doesn't crash when we set a blank page in web preview
@@ -152,5 +156,7 @@ void TestQgsExternalResourceWidgetWrappe
   QCOMPARE( ww.mQgsWidget->mWebView->url().toString(), QStringLiteral( "about:blank" ) );
 }
 
+#endif /* WITH_QTWEBKIT */
+
 QGSTEST_MAIN( TestQgsExternalResourceWidgetWrapper )
 #include "testqgsexternalresourcewidgetwrapper.moc"
