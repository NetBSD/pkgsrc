$NetBSD: patch-autotests_client_test__fake__input.cpp,v 1.1 2022/04/25 05:26:49 markd Exp $

linux/input.h only for linux

--- autotests/client/test_fake_input.cpp.orig	2022-04-02 10:04:14.000000000 +0000
+++ autotests/client/test_fake_input.cpp
@@ -15,7 +15,9 @@
 #include "../../src/server/display.h"
 #include "../../src/server/fakeinput_interface.h"
 
+#ifdef Q_OS_LINUX
 #include <linux/input.h>
+#endif
 
 using namespace KWayland::Client;
 using namespace KWayland::Server;
@@ -198,9 +200,11 @@ void FakeInputTest::testPointerButtonQt_
     QTest::addColumn<Qt::MouseButton>("qtButton");
     QTest::addColumn<quint32>("linuxButton");
 
+#ifdef BTN_LEFT
     QTest::newRow("left") << Qt::LeftButton << quint32(BTN_LEFT);
     QTest::newRow("right") << Qt::RightButton << quint32(BTN_RIGHT);
     QTest::newRow("middle") << Qt::MiddleButton << quint32(BTN_MIDDLE);
+#endif
 }
 
 void FakeInputTest::testPointerButtonQt()
@@ -247,6 +251,7 @@ void FakeInputTest::testPointerButtonLin
 {
     QTest::addColumn<quint32>("linuxButton");
 
+#ifdef BTN_LEFT
     QTest::newRow("left") << quint32(BTN_LEFT);
     QTest::newRow("right") << quint32(BTN_RIGHT);
     QTest::newRow("middle") << quint32(BTN_MIDDLE);
@@ -255,6 +260,7 @@ void FakeInputTest::testPointerButtonLin
     QTest::newRow("forward") << quint32(BTN_FORWARD);
     QTest::newRow("back") << quint32(BTN_BACK);
     QTest::newRow("task") << quint32(BTN_TASK);
+#endif
 }
 
 void FakeInputTest::testPointerButtonLinux()
