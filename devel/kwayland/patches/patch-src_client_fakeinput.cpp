$NetBSD: patch-src_client_fakeinput.cpp,v 1.1 2022/04/25 05:26:49 markd Exp $

linux/input.h only for linux

--- src/client/fakeinput.cpp.orig	2022-04-02 10:04:14.000000000 +0000
+++ src/client/fakeinput.cpp
@@ -10,7 +10,9 @@
 #include <QPointF>
 #include <QSizeF>
 
+#ifdef Q_OS_LINUX
 #include <linux/input.h>
+#endif
 
 #include <wayland-fake-input-client-protocol.h>
 
@@ -98,13 +100,19 @@ void FakeInput::Private::sendPointerButt
     uint32_t b = 0;
     switch (button) {
     case Qt::LeftButton:
+#ifdef BTN_LEFT
         b = BTN_LEFT;
+#endif
         break;
     case Qt::RightButton:
+#ifdef BTN_RIGHT
         b = BTN_RIGHT;
+#endif
         break;
     case Qt::MiddleButton:
+#ifdef BTN_MIDDLE
         b = BTN_MIDDLE;
+#endif
         break;
     default:
         // TODO: more buttons, check implementation in QtWayland
