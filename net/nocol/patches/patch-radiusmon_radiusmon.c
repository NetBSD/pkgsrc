$NetBSD: patch-radiusmon_radiusmon.c,v 1.1 2016/03/13 09:06:01 dholland Exp $

Use standard headers.

--- radiusmon/radiusmon.c~	1999-11-05 03:37:33.000000000 +0000
+++ radiusmon/radiusmon.c
@@ -37,6 +37,8 @@
  *
  */
 
+#include <string.h>
+#include <arpa/inet.h>
 #include "radiusmon.h"
 
 #ifdef TEST
