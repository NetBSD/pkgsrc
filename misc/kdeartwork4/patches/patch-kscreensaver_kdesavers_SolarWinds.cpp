$NetBSD: patch-kscreensaver_kdesavers_SolarWinds.cpp,v 1.1 2012/01/23 20:51:10 joerg Exp $

--- kscreensaver/kdesavers/SolarWinds.cpp.orig	2012-01-23 15:14:00.000000000 +0000
+++ kscreensaver/kdesavers/SolarWinds.cpp
@@ -24,6 +24,7 @@
 #include <stdlib.h>
 #include <time.h>
 #include <qtimer.h>
+#include <GL/glu.h>
 #include "SolarWinds.h"
 #include "SolarWinds.moc"
 
