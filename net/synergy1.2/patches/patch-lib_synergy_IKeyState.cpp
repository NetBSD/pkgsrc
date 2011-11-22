$NetBSD: patch-lib_synergy_IKeyState.cpp,v 1.1 2011/11/22 20:07:20 joerg Exp $

--- lib/synergy/IKeyState.cpp.orig	2011-11-22 19:37:22.000000000 +0000
+++ lib/synergy/IKeyState.cpp
@@ -13,6 +13,7 @@
  */
 
 #include "IKeyState.h"
+#include <stdlib.h>
 
 //
 // IKeyState
