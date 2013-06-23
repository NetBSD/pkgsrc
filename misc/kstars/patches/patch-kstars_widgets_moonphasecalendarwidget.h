$NetBSD: patch-kstars_widgets_moonphasecalendarwidget.h,v 1.1 2013/06/23 19:09:15 jperkin Exp $

Avoid "sun" conflict.

--- kstars/widgets/moonphasecalendarwidget.h.orig	2013-05-03 04:38:11.897302548 +0000
+++ kstars/widgets/moonphasecalendarwidget.h
@@ -21,6 +21,8 @@
 #include <QWidget>
 #include <KDateTable>
 
+#undef sun
+
 class KSMoon;
 class KSSun;
 class KStarsDateTime;
