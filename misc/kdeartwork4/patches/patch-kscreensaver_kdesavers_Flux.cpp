$NetBSD: patch-kscreensaver_kdesavers_Flux.cpp,v 1.1 2012/01/23 20:51:10 joerg Exp $

--- kscreensaver/kdesavers/Flux.cpp.orig	2012-01-23 15:10:59.000000000 +0000
+++ kscreensaver/kdesavers/Flux.cpp
@@ -32,6 +32,7 @@
 #include <math.h>
 #include <time.h>
 #include <qtimer.h>
+#include <GL/glu.h>
 
 #include "Flux.h"
 #include "Flux.moc"
