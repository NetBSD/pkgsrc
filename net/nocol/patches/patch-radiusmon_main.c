$NetBSD: patch-radiusmon_main.c,v 1.1 2016/03/13 09:06:01 dholland Exp $

Use standard headers.

--- radiusmon/main.c~	1999-11-15 06:43:48.000000000 +0000
+++ radiusmon/main.c
@@ -32,7 +32,9 @@
   */ 
 
 #include <stdio.h>
+#include <string.h>
 #include <fcntl.h>
+#include <arpa/inet.h>
 
 #include "nocol.h"
 #include "radiusmon.h"
