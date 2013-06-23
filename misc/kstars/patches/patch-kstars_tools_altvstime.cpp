$NetBSD: patch-kstars_tools_altvstime.cpp,v 1.1 2013/06/23 19:09:15 jperkin Exp $

Avoid "sun" conflict.

--- kstars/tools/altvstime.cpp.orig	2013-05-03 04:38:11.880302708 +0000
+++ kstars/tools/altvstime.cpp
@@ -45,6 +45,8 @@
 #include "avtplotwidget.h"
 #include "ui_altvstime.h"
 
+#undef sun
+
 AltVsTimeUI::AltVsTimeUI( QWidget *p ) :
     QFrame( p )
 {
