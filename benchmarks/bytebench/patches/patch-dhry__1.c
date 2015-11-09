$NetBSD: patch-dhry__1.c,v 1.1 2015/11/09 07:30:59 dholland Exp $

- use standard headers

--- src/dhry_1.c~	1999-07-28 21:43:08.000000000 +0000
+++ src/dhry_1.c
@@ -81,7 +81,7 @@ extern  int     times ();
                 /* Measurements should last at least about 2 seconds */
 #endif
 #ifdef TIME
-extern long     time();
+#include <time.h>
                 /* see library function "time"  */
 #define Too_Small_Time 2
                 /* Measurements should last at least 2 seconds */
