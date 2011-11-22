$NetBSD: patch-lib_synergy_IPrimaryScreen.cpp,v 1.1 2011/11/22 20:07:20 joerg Exp $

--- lib/synergy/IPrimaryScreen.cpp.orig	2011-11-22 19:37:41.000000000 +0000
+++ lib/synergy/IPrimaryScreen.cpp
@@ -13,6 +13,7 @@
  */
 
 #include "IPrimaryScreen.h"
+#include <stdlib.h>
 
 //
 // IPrimaryScreen
