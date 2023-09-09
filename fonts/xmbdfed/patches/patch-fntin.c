$NetBSD: patch-fntin.c,v 1.1 2023/09/09 14:56:28 vins Exp $

Fix signedness mismatch warnings.

--- fntin.c.orig	2004-01-29 17:15:37.000000000 +0000
+++ fntin.c
@@ -28,6 +28,7 @@ static char rcsid[] = "$Id: fntin.c,v 1.
 #endif
 
 #include <stdio.h>
+#include <stdint.h>
 #include <string.h>
 #include <stdlib.h>
 #include <Xm/Xm.h>
@@ -64,7 +65,7 @@ Widget w;
 XtPointer client_data, call_data;
 #endif
 {
-    select_action = (int) client_data;
+    select_action = (intptr_t) client_data;
 }
 
 static void
