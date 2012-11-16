$NetBSD: patch-spunk_menue.cc,v 1.1 2012/11/16 00:37:46 joerg Exp $

--- spunk/menue.cc.orig	1997-01-26 18:17:32.000000000 +0000
+++ spunk/menue.cc
@@ -26,6 +26,10 @@
 #include <stdlib.h>
 #endif
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #include "keydef.h"
 #include "screen.h"
 #include "winattr.h"
@@ -495,8 +499,8 @@ void GenericMenue::DynamicRight ()
 
 i16 GenericMenue::GetChoice ()
 {
-    const AltNextKeyCode = MaxUserID + 1;
-    const AltPrevKeyCode = MaxUserID + 2;
+    const int AltNextKeyCode = MaxUserID + 1;
+    const int AltPrevKeyCode = MaxUserID + 2;
 
 
     // Remember old window state
