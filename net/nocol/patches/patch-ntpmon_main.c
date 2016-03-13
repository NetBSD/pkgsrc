$NetBSD: patch-ntpmon_main.c,v 1.1 2016/03/13 09:06:01 dholland Exp $

Use standard headers.

--- ntpmon/main.c~	1998-06-30 20:26:16.000000000 +0000
+++ ntpmon/main.c
@@ -26,6 +26,7 @@
   */ 
 
 #include <stdio.h>
+#include <string.h>
 #include <fcntl.h>
 #include "nocol.h"
 #include "ntpmon.h"
