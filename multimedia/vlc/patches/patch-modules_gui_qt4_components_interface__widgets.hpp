$NetBSD: patch-modules_gui_qt4_components_interface__widgets.hpp,v 1.1 2015/10/25 11:00:18 wiz Exp $

Qt's MOC doesn't handle int64_t, so introduce a meaningful type name
so that slot/signal/connection macros work properly.

--- modules/gui/qt4/components/interface_widgets.hpp.orig	2014-11-16 18:57:59.000000000 +0000
+++ modules/gui/qt4/components/interface_widgets.hpp
@@ -206,7 +206,7 @@ private:
     char psz_time[MSTRTIME_MAX_SIZE];
     void toggleTimeDisplay();
 private slots:
-    void setDisplayPosition( float pos, int64_t time, int length );
+    void setDisplayPosition( float pos, putime_t time, int length );
     void setDisplayPosition( float pos );
 };
 
