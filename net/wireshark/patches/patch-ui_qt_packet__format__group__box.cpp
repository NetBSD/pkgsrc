$NetBSD: patch-ui_qt_packet__format__group__box.cpp,v 1.1 2018/06/21 12:22:10 adam Exp $

Fix for Qt 5.11.

--- ui/qt/packet_format_group_box.cpp.orig	2018-06-21 09:11:22.000000000 +0000
+++ ui/qt/packet_format_group_box.cpp
@@ -10,6 +10,7 @@
 #include <ui_packet_format_group_box.h>
 
 #include <QStyle>
+#include <QStyleOption>
 
 PacketFormatGroupBox::PacketFormatGroupBox(QWidget *parent) :
     QGroupBox(parent),
