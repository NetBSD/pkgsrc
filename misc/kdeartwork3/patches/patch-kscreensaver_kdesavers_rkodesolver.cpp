$NetBSD: patch-kscreensaver_kdesavers_rkodesolver.cpp,v 1.1 2015/03/18 10:27:54 joerg Exp $

--- kscreensaver/kdesavers/rkodesolver.cpp.orig	2015-03-17 22:50:05.000000000 +0000
+++ kscreensaver/kdesavers/rkodesolver.cpp
@@ -10,6 +10,7 @@
 //
 //============================================================================
 
+#include <cstdlib>
 #include <kdebug.h>
 #include "rkodesolver.h"
 
