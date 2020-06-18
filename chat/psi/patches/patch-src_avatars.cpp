$NetBSD: patch-src_avatars.cpp,v 1.1 2020/06/18 13:55:15 nia Exp $

Fix Qt 5.15 build issues

--- src/avatars.cpp.orig	2018-11-02 00:15:39.000000000 +0000
+++ src/avatars.cpp
@@ -34,6 +34,7 @@
 #include <QFile>
 #include <QBuffer>
 #include <QPainter>
+#include <QPainterPath>
 
 #include "xmpp_xmlcommon.h"
 #include "xmpp_vcard.h"
