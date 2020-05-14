$NetBSD: patch-gr-qtgui_lib_TimeDomainDisplayPlot.cc,v 1.1 2020/05/14 19:22:44 joerg Exp $

--- gr-qtgui/lib/TimeDomainDisplayPlot.cc.orig	2020-05-10 01:44:39.017593633 +0000
+++ gr-qtgui/lib/TimeDomainDisplayPlot.cc
@@ -30,6 +30,7 @@
 #include <QColor>
 #include <cmath>
 #include <iostream>
+#include <sstream>
 #include <volk/volk.h>
 
 class TimePrecisionClass
