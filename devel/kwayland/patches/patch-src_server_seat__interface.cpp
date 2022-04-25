$NetBSD: patch-src_server_seat__interface.cpp,v 1.1 2022/04/25 05:26:49 markd Exp $

linux/input.h only for linux

--- src/server/seat_interface.cpp.orig	2022-04-02 10:04:14.000000000 +0000
+++ src/server/seat_interface.cpp
@@ -19,7 +19,9 @@
 #define WL_SEAT_NAME_SINCE_VERSION 2
 #endif
 
+#ifdef Q_OS_LINUX
 #include <linux/input.h>
+#endif
 
 #include <functional>
 
@@ -38,6 +40,10 @@ SeatInterface::Private::Private(SeatInte
 {
 }
 
+#ifndef Q_OS_LINUX
+enum mouse_button { BTN_LEFT, BTN_RIGHT, BTN_MIDDLE, BTN_TOUCH };
+#endif
+
 #ifndef K_DOXYGEN
 const struct wl_seat_interface SeatInterface::Private::s_interface = {getPointerCallback, getKeyboardCallback, getTouchCallback, releaseCallback};
 #endif
@@ -753,6 +759,7 @@ namespace
 static quint32 qtToWaylandButton(Qt::MouseButton button)
 {
     static const QHash<Qt::MouseButton, quint32> s_buttons({
+#ifdef BTN_LEFT
         {Qt::LeftButton, BTN_LEFT},
         {Qt::RightButton, BTN_RIGHT},
         {Qt::MiddleButton, BTN_MIDDLE},
@@ -769,6 +776,7 @@ static quint32 qtToWaylandButton(Qt::Mou
         {Qt::ExtraButton11, BTN_TASK + 6},
         {Qt::ExtraButton12, BTN_TASK + 7},
         {Qt::ExtraButton13, BTN_TASK + 8}
+#endif
         // further mapping not possible, 0x120 is BTN_JOYSTICK
     });
     return s_buttons.value(button, 0);
